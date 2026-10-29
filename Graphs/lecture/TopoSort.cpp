#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int>* l_ptr;
public:
    Graph(int V){
        this->V = V;
        l_ptr = new list<int>[V];
    }

    void addEdge(int u, int v){
        l_ptr[u].push_back(v);
        // l_ptr[v].push_back(u);
    }

    void topoHelper(int src, vector<bool>& visited, stack<int>& s){

        visited[src] = true;

        for(int v : l_ptr[src]){
            if(!visited[v]){
                topoHelper(v, visited, s);
            }
        }

        s.push(src);
    }

    void topoSort(){
        vector<bool> visited(V, false);
        stack<int> s;

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                topoHelper(i, visited, s);
            }
        }

        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }

        cout << endl;
    }

    void calcIndegree(vector<int>& indeg){
        for(int u = 0; u < V; u++){
            for(int v : l_ptr[u]){
                indeg[v] += 1;
            }
        }
    }

    /**
     * Kahn's Algorithm:
     * Works by calculating the indegree and outdegree of each node.
     * 
     * If the indegree of a node is 0, we can tell that is a starting node as it does
     * not depend on another node.
     * 
     * If the outdegree of a node is 0, we can tell that now it does not have neighbours.
     * 
     * This helps us detemine if there is a cycle or not because Topo sort can only 
     * be done if the graph is a DAG.
     */

    void topoSort2(){ 
        vector<int> indeg(V, 0);
        calcIndegree(indeg);

        queue<int> q;

        //0 indeg nodes -> starting point
        for(int i = 0; i < V; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int currNode = q.front();
            q.pop();

            cout << currNode << " ";

            for(int v : l_ptr[currNode]){
                indeg[v] -= 1;
                if(indeg[v] == 0){ // no pending dependencies
                    q.push(v);
                }
            }
        }

        cout << endl;
    }
};

int main(){

    Graph graph(6);
    
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort();
}
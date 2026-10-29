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
        l_ptr[v].push_back(u);
    }

    void print(){

        for(int u = 0; u < V; u++){
            list<int> neighbours = l_ptr[u];
            cout << u << ": ";
            for(int v : neighbours){
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfsHelper(vector<bool>& visited, int start){ // O(V + E)
        queue<int> frontier;

        frontier.push(start); // Assuming 0 is the starting node
        visited[start] = true;

        while(frontier.size() > 0){
            int u = frontier.front();
            frontier.pop();

            cout << u << " ";

            list<int> neightbours = l_ptr[u];

            for(int neightbour : neightbours){
                if(visited[neightbour] == false){
                    visited[neightbour] = true;
                    frontier.push(neightbour);
                }
            }
        }

        cout << endl;
    }

    void bfs(){
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bfsHelper(visited, i);
            }
        }
    }

    void dfsHelper(int u, vector<bool>& visited){
        visited[u] = true;
        cout << u << " ";

        list<int> neighbours = l_ptr[u];

        for(int v : neighbours){
            if(visited[v] == false){
                dfsHelper(v, visited);
            }
        }
    }

    void dfs(){
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfsHelper(i, visited);
            }
        }
        cout << endl;
    }

    bool undirCycleHelper(int src, int par, vector<bool>& vis){ //O(V+E)

        vis[src] = true;

        for(int v : l_ptr[src]){
            if(!vis[v]){
                if(undirCycleHelper(v, src, vis)){
                    return true;
                }
            } else{ 
                
                // Check for back edge
                // if we see our parent, that's okay cause we literally just came from there
                // problem is when we visit a node and it is not our parent
                //Is this just the node I came from?
                //Yes → ignore.
                //No → cycle.

                if(v != par){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir(){
        vector<bool> visited(V, false);
        return undirCycleHelper(0, -1, visited);
    }

    bool dirCycleHelper(int src, vector<bool>& visited, vector<bool>& recPath){
        visited[src] = true;
        recPath[src] = true;

        for(int v : l_ptr[src]){
            if(!visited[v]){
                if(dirCycleHelper(v, visited, recPath)){
                    return true;
                }
            } else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir(){
        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dirCycleHelper(i, visited, recPath)){
                    return true;
                }
            }
        }
        return false;
    }

    bool isBipartite(){
        queue<int> frontier;
        vector<int> colour(V, -1); // logic of visited and colour together
        
        frontier.push(0);
        colour[0] = 0;

        while(!frontier.empty()){
            int curr = frontier.front();
            frontier.pop();

            for(int v : l_ptr[curr]){
                if(colour[v] == -1){
                    colour[v] = !colour[curr];
                    frontier.push(v);
                } else{
                    if(colour[v] == colour[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main(){

    Graph graph(7);
    
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    graph.addEdge(5,6);
    graph.addEdge(0,1);

    graph.print();
    graph.bfs();
    graph.dfs();
}
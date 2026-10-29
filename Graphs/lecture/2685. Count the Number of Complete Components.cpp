#include <iostream>
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

    void dfsHelper(vector<bool>& visited, int u){

        visited[u] = true;

        for(int v : l_ptr[u]){
            if(!visited[v]){
                dfsHelper(visited, v);
            }
        }
    }

    int dfs(){

        vector<bool> visited(V, false);
        int count = 0;

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                count += 1;
                dfsHelper(visited, i);
            }
        }
        return count;
    }
};

int countCompleteComponents(int n, vector<vector<int>>& edges) {

    Graph graph(n);

    for(int i = 0; i < edges.size(); i++){
        graph.addEdge(edges[i][0], edges[i][1]);
    }
    return graph.dfs();
}

int main(){
    vector<vector<int>> edges_list = {{0,1},{0,2},{1,2},{3,4},{3,5}};
    int n = 6;

    cout << countCompleteComponents(n, edges_list) << endl;
}
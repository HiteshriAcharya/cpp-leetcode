#include <iostream>
#include <vector>
using namespace std;

bool hasPath(int src, int par, 
                                   vector<vector<int>>& graph, 
                                   vector<bool>& visited){

    
    if(src == par) {
        return true;
    }

    visited[src] = true;

    for(int v : graph[src]) {
        if(!visited[v] && hasPath(v, par, graph, visited)) {
            return true;
        }
    }

    return false;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

   int V = edges.size();
    vector<vector<int>> graph(V + 1);

    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        vector<bool> visited(V + 1, false);

        // return the first edge that's redundant
        if(hasPath(u, v, graph, visited)) {
            return {u, v};
        }

        // create the graph as you go to find the redundant path
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    return {};
}

int main(){
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};

    for(int node : findRedundantConnection(edges)){
        cout << node << " ";
    }

    cout << endl;
}
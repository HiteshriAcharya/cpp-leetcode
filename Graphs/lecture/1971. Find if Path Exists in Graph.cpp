#include <iostream>
#include <list>
#include <vector>
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

    bool validPathHelper(int source, int dest,vector<bool>& visited){

        if(source == dest) return true;

        visited[source] = true;

        for(int v : l_ptr[source]){
            if(!visited[v]){
                if(validPathHelper(v, dest, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

    Graph graph(n);

    for(int i = 0; i < edges.size(); i++){
        graph.addEdge(edges[i][0], edges[i][1]);
    }

    vector<bool> visited(n, false);
    return graph.validPathHelper(source, destination, visited);
}

int main(){

    vector<vector<int>> edges_list = {{0,1},{1,2},{2,0}};
    int n = 3;
    int source = 0;
    int dest = 2;

    cout << validPath(n, edges_list, source, dest) << endl;
}
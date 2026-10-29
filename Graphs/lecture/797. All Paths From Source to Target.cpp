#include <iostream>
#include <vector>
using namespace std;

void allPathsHelper(int src, 
                    int dst, 
                    vector<bool>& visited, 
                    vector<int>& currPath, 
                    vector<vector<int>>& paths, 
                    vector<vector<int>>& graph){
    
    visited[src] = true;
    currPath.push_back(src);
    
    if(src == dst){
         paths.push_back(currPath);

        currPath.pop_back();
        visited[src] = false;
        return;
    }

    for(int v : graph[src]){
        if(!visited[v]){
            allPathsHelper(v, dst, visited, currPath, paths, graph);
        }
    }

    currPath.pop_back();
    visited[src] = false;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

    int V = graph.size();

    vector<vector<int>> paths;
    vector<bool> visited(V, false);
    vector<int> currPath;

    allPathsHelper(0, V-1, visited, currPath, paths, graph);

    return paths;
}

int main(){

    vector<vector<int>> graph = {{1,2},{3},{3},{}};

    for(auto path : allPathsSourceTarget(graph)){
        for(auto node : path){
            cout << node << " ";
        }
        cout << endl;
    }
}
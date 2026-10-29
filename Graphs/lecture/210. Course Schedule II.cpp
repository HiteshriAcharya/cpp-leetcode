#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isCycle(int src, 
             stack<int>& s, 
             vector<bool>& visited, 
             vector<bool>& recPath, 
             vector<vector<int>>& graph) {

    visited[src] = true;
    recPath[src] = true;

    for(int v : graph[src]) {
        if(!visited[v]) {
            if(isCycle(v, s, visited, recPath, graph)) {
                return true;
            }
        } else {
            if(recPath[v]) {
                return true;
            }
        }
    }

    recPath[src] = false;
    s.push(src); 
    return false;
} 

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
    vector<bool> visited(numCourses, false);
    vector<bool> recPath(numCourses, false);
    stack<int> s;
    vector<int> topoSort;

    vector<vector<int>> graph(numCourses);

    for(auto edge : prerequisites) {
        int course = edge[0];
        int preReq = edge[1];

        graph[preReq].push_back(course);
    }

    for(int i = 0; i < numCourses; i++) {
        if(!visited[i]) {
            if(isCycle(i, s, visited, recPath, graph)) {
                return {};
            }
        }
    }

    while(!s.empty()) {
        topoSort.push_back(s.top());
        s.pop();
    }

    return topoSort;
}

int main(){

}
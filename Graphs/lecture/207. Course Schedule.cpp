#include <iostream>
#include <vector>
using namespace std;

bool cycleDetection(int src,
                        vector<vector<int>>& graph,
                        vector<bool>& visited,
                        vector<bool>& recPath) {
        
        visited[src] = true;
        recPath[src] = true;

        for(int v : graph[src]) {
            if(!visited[v]) {
                if(cycleDetection(v, graph, visited, recPath)) {
                    return true;
                }
            } else if(recPath[v]) {
                return true;
            }
        }

        recPath[src] = false;
        return false;
    }

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);

    for(auto edge : prerequisites) {
            
        int course = edge[0];
        int prereq = edge[1];    
        graph[prereq].push_back(course);
        
    }

    vector<bool> visited(numCourses, false);
    vector<bool> recPath(numCourses, false);

    for(int i = 0; i < numCourses; i++) {
        if(!visited[i]) {
            if(cycleDetection(i, graph, visited, recPath)) {
                return false;
            }
        }
    }

    return true;
}

bool cycleDetection(int src, 
                    vector<vector<int>>& prerequisites, 
                    vector<bool>& visited, 
                    vector<bool>& recPath) {

    visited[src] = true;
    recPath[src] = true;

    for(auto edge : prerequisites) {
        int course = edge[0];
        int prereq = edge[1];

        if(prereq == src) {
            int v = course;

            if(!visited[v]) {
                if(cycleDetection(v, prerequisites, visited, recPath)) {
                    return true;
                }
            } else if(recPath[v]) {
                return true;
            }
        }
    }

    recPath[src] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<bool> visited(numCourses, false);
    vector<bool> recPath(numCourses, false);

    for(int i = 0; i < numCourses; i++) {
        if(!visited[i]) {
            if(cycleDetection(i, prerequisites, visited, recPath)) {
                return false;
            }
        }
    }

    return true;
}

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    cout << canFinish(numCourses, prerequisites) << endl;
}
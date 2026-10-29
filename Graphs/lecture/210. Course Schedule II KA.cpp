#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * Apperently, DFS is better for this
 */

void buildGraph(vector<vector<int>>& graph, vector<vector<int>>& prerequisites){
    for(auto edge : prerequisites){
        int course = edge[0];
        int prereq = edge[1];

        graph[prereq].push_back(course);
    }
}

void calcIndegree(vector<int>& indeg, vector<vector<int>>& prerequisites){
    
    for(int i = 0; i < prerequisites.size(); i++){
        indeg[prerequisites[i][0]] += 1;
    }
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    vector<int> results;
    vector<int> indeg(numCourses, 0);
    vector<vector<int>> graph(numCourses);
    queue<int> q;
    int count = 0;

    buildGraph(graph, prerequisites);
    calcIndegree(indeg, prerequisites);

    for(int i = 0; i < indeg.size(); i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){

        int currNode = q.front();
        q.pop();
        count += 1;
        results.push_back(currNode);

         for(int neighbour : graph[currNode]){
            indeg[neighbour]--;

            if(indeg[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    if(count == numCourses) return results;
    else return {};
}

int main(){
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    int numCourses = 2;
}
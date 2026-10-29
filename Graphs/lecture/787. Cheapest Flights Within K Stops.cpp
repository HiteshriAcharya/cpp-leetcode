#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge{
    int u;
    int cost;
    int stops;

    Edge(int u, int cost, int stops){
        this->u = u;
        this->cost = cost;
        this->stops = stops;
    }
};

void buildGraph(vector<vector<pair<int,int>>>& graph, vector<vector<int>>& edges){
    for(auto edge : edges){
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
}

// // Modified Dijkstra
// int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

// }

// Modified BFS + Edge Relaxation
int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int k) {

    vector<vector<pair<int,int>>> graph(n);
    buildGraph(graph, flights);

    queue<Edge> q; // node idx, cost, stops
    vector<int> dist(n, INT_MAX);
    q.push({src, 0, -1});

    dist[src] = 0;

    while(!q.empty()){
        Edge curr = q.front();
        q.pop();

        for(auto neigh : graph[curr.u]){
            int v = neigh.first;
            int wt = neigh.second;

            if(dist[v] > curr.cost + wt && curr.stops+1 <= k){
                dist[v] = curr.cost + wt;
                q.push({v, dist[v], curr.stops+1});
            }
        }
    }

    if(dist[dst] == INT_MAX) return -1;
    return dist[dst];
}

int main(){

    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;

    cout << findCheapestPrice2(n, flights, src, dst, k) << endl;
}
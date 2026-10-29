#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minCostConnectPoints2(vector<vector<int>>& points) {
    int V = points.size();

    vector<bool> visited(V, false);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, 0});

    int cost = 0;
    int nodesUsed = 0;

    while(!pq.empty() && nodesUsed < V) {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(visited[u]) {
            continue;
        }

        visited[u] = true;
        cost += wt;
        nodesUsed++;

        for(int v = 0; v < V; v++) {
            if(!visited[v]) {
                int currWt =
                    abs(points[u][0] - points[v][0]) +
                    abs(points[u][1] - points[v][1]);

                pq.push({currWt, v});
            }
        }
    }

    return cost;
}

int minCostConnectPoints(vector<vector<int>>& points) {

    int V = points.size();
    vector<bool> visited(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int cost = 0;

    int src = 0;
    pq.push(make_pair(0, src));

    while(!pq.empty()){

        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(!visited[u]){

            visited[u] = true;
            cost += wt;

            for(int i = 0; i < V; i++){
                if(i != u){
                    int currWt = abs(points[i][0] - points[u][0]) + abs(points[i][1] - points[u][1]);
                    pq.push(make_pair(currWt, i));
                }
            }
        }
    }
    return cost;
}

int main(){

    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << minCostConnectPoints(points) << endl;
}
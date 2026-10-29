#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>>* l_ptr;
public:
    Graph(int V){
        this->V = V;
        l_ptr = new list<pair<int,int>>[V];
    }

    void addEdge(int u, int v, int wt){
        l_ptr[u].push_back(make_pair(v, wt));
        l_ptr[v].push_back(make_pair(u, wt));
    }

    void primsAlgo(int src){

        vector<int> visited(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0, src));

        int cost = 0;

        while(!pq.empty()){

            int u = pq.top().second;
            int wt = pq.top().first;

            pq.pop();

            if(!visited[u]){

                visited[u] = true;
                cost += wt;

                for(pair<int,int> n : l_ptr[u]){
                    int v = n.first;
                    int currWt = n.second;
                    pq.push(make_pair(currWt, v));
                }
            }
        }
        cout << cost << endl;
    }
};

int main(){

    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);

    graph.addEdge(1,3,40);
    graph.addEdge(2,3,50);

    graph.primsAlgo(0);
}
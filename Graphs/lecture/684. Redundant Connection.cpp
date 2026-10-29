#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l_ptr;

public:
    Graph(int V) {
        this->V = V;
        l_ptr = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l_ptr[u].push_back(v);
        l_ptr[v].push_back(u);
    }

    bool cycleUndirHelper(int src, int dest, vector<bool>& visited) {
        if (src == dest) return true;

        visited[src] = true;

        for (int v : l_ptr[src]) {
            if (!visited[v]) {
                if (cycleUndirHelper(v, dest, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool cycleUndir(int u, int v) {
        vector<bool> visited(V, false);
        return cycleUndirHelper(u, v, visited);
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int E = edges.size();

    Graph graph(E + 1); // nodes are 1-indexed

    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        if (graph.cycleUndir(u, v)) {
            return edge;
        }

        graph.addEdge(u, v);
    }

    return {};
}

int main() {
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};

    vector<int> result = findRedundantConnection(edges);

    cout << result[0] << " " << result[1] << endl;
}
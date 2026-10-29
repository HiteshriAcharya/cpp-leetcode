#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* dfs(Node* node, unordered_map<Node*, Node*> &visited){

    if(visited.find(node) != visited.end()) return visited[node]; // Already cloned

    visited[node] = new Node(node->val);

    for(auto &neighbour : node->neighbors){
        visited[node]->neighbors.push_back(dfs(neighbour, visited));
    }
    
    return visited[node];
}

Node* cloneGraph(Node* node) {
    if(node == NULL) return NULL;
    unordered_map<Node*, Node*> visited;
    return dfs(node, visited);
}

int main(){


}
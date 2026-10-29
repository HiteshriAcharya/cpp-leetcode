#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> nodes;
    if(!root) return nodes;

    queue<TreeNode*> frontier;
    frontier.push(root);
    int level = 0;

    while(!frontier.empty()){
        int queueLen = frontier.size();
        nodes.push_back({});
        for(int i = 0; i < queueLen; i++){
            nodes[level].push_back(frontier.front()->val);
            if(frontier.front()->left != NULL) frontier.push(frontier.front()->left);
            if(frontier.front()->right != NULL) frontier.push(frontier.front()->right);
            frontier.pop();
        }

        level += 1;
    }

    return nodes;
}

int main(){

}
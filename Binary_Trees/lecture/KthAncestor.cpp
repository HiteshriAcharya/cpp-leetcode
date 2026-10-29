#include <iostream>
using namespace std;

class TreeNode{

public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int KthAncestor(TreeNode* root, int node, int k){

    if (root == NULL) return -1;

    if (root->val == node) return 0;

    int dist = KthAncestor(root->left, node, k);

    if (dist == -1) {
        dist = KthAncestor(root->right, node, k);
    }

    if (dist == -1) return -1;

    if (dist + 1 == k) {
        cout << root->val << endl; // kth ancestor found
    }

    return dist + 1;
}

int main(){

}
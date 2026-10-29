#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    if(root == p || root == q) return root;

    TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

    if(leftNode != NULL && rightNode != NULL) return root;
    return leftNode == NULL ? rightNode : leftNode;
}

int dist(TreeNode* root, TreeNode* target){

    if(root == NULL) return -1;
    if(root == target) return 0;

    int leftDist = dist(root->left, target);
    if(leftDist != -1) return leftDist + 1;

    int rightDist = dist(root->right, target);
    if(rightDist != -1) return rightDist + 1;

    return -1;
}

int minDist(TreeNode* root, TreeNode* p, TreeNode* q){

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    int dist1 = dist(root, p);
    int dist2 = dist(root, q);

    return dist1 + dist2;
}

int main(){


}
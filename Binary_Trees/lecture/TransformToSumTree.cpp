#include <iostream>
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

int transform(TreeNode* root){

    if(root == NULL) return 0;

    int leftNode = transform(root->left);
    int rightNode = transform(root->right);
    int currNode = root->val;

    root->val = leftNode + rightNode;

    // VERY IMPORTANT! We cannot do root->left->val for leaf nodes!!
    
    if(root->left) root->val += root->left->val;
    if(root->right) root->val += root->right->val;

    return currNode;

}

int main(){

}
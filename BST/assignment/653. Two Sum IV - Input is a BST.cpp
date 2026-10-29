#include <iostream>
using namespace std;

class TreeNode{

public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};

void pushLeft(TreeNode* root, stack<TreeNode*>& leftStack){
    
    if(root == NULL) return;

    leftStack.push(root);
    pushLeft(root->left, leftStack);
}

void pushRight(TreeNode* root, stack<TreeNode*>& rightStack){

    if(root == NULL) return;

    rightStack.push(root);
    pushRight(root->right, rightStack);
}

TreeNode* nextSmallest(stack<TreeNode*>& leftStack){

    TreeNode* node = leftStack.top();
    leftStack.pop();

    pushLeft(node->right, leftStack);

    return node;

}

TreeNode* nextLarget(stack<TreeNode*>& rightStack){

    TreeNode* node = rightStack.top();
    rightStack.pop();

    pushRight(node->right, rightStack);

    return node;
}

bool findTarget(TreeNode* root, int k) {

    stack<TreeNode*> leftStack;
    stack<TreeNode*> rightStack;

    pushLeft(root, leftStack);
    pushRight(root, rightStack);

    TreeNode* left = nextSmallest(leftStack);
    TreeNode* right = nextLarget(rightStack);

    while(left != right){

        int sum = left->val + right->val;

        if(sum == k) return true;

        if(sum < k) left = nextSmallest(leftStack);
        else right = nextLarget(rightStack);
    }

    return false;
}

int main(){

}
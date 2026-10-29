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

int minDiff = INT_MAX;
int closestNode;

void closestValue(TreeNode* root, int k){

    if(root == NULL) return;

    int currMin = abs(root->val - k);

    if(currMin < minDiff){
        minDiff = currMin;
        closestNode = root->val;
    }

    if(root->val > k){
        closestValue(root->left, k);
    }else{
        closestValue(root->right, k);
    }
}

int main(){

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(11);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(20);

    int k = 19;

    closestValue(root, k);

    cout << closestNode << endl;

}
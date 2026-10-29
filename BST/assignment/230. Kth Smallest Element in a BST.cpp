#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * We do not increment when going left or right.
 * We only increment when we reach an actual node.
 * 
 * Call inorder(5)
   Call inorder(3)
    Call inorder(2)
      Call inorder(1)
        Call inorder(NULL)   // left of 1
        visit 1: count = 1
        Call inorder(NULL)   // right of 1
      return to 2
      visit 2: count = 2
      Call inorder(NULL)     // right of 2
    return to 3
    visit 3: count = 3  -> ans = 3
    Call inorder(4)
      Call inorder(NULL)
      visit 4: count = 4
      Call inorder(NULL)
  return to 5
  visit 5: count = 5
  Call inorder(6)
    Call inorder(NULL)
    visit 6: count = 6
    Call inorder(NULL)
 */

void inorder(TreeNode* root, int k, int& nodeVal, int& count){

    if(root == NULL) return;

    inorder(root->left, k, nodeVal, count);
    
    count += 1;

    if(count == k){
        nodeVal = root->val;
        return;
    }

    inorder(root->right, k, nodeVal, count);
}

int kthSmallest(TreeNode* root, int k) {

    int nodeVal = -1;
    int count = 0;
    inorder(root, k, nodeVal, count);

    return nodeVal;

}

int main(){

}
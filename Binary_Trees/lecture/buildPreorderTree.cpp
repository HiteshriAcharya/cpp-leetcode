#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

static int idx = 0;

Node* buildTree(vector<int>& preorder){

    if(preorder[idx++] == -1) return NULL;

    Node* newNode = new Node(preorder[idx++]); // just create the node, no connection formed yet

    newNode->left = buildTree(preorder); 
    newNode->right = buildTree(preorder);

    return newNode;
}

int main(){

    vector<int> preorder = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

}
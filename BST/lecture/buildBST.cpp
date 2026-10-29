#include <iostream>
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

Node* insert(Node* root, int val){

    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(root->val > val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}


Node* buildBST(vector<int> nodes){
    Node* root = NULL;

    for(int i = 0; i < nodes.size(); i++){
        root = insert(root, nodes[i]);
    }

    return root;
}

void inorder(Node* root){

    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){

    vector<int> nodes = {5, 1, 3, 4, 2, 7};

    Node* root = buildBST(nodes);
    inorder(root);
    cout << endl;
}
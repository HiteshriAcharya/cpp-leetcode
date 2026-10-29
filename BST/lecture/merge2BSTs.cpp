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

Node* buildBalancedBST(vector<int>& inorderSeq, int start, int end){

    if(start > end) return NULL;

    int mid = start + (end-start)/2;
    Node* root = new Node(inorderSeq[mid]);

    root->left = buildBalancedBST(inorderSeq, start, mid-1);
    root->right = buildBalancedBST(inorderSeq, mid+1, end);

    return root;
}


void preorder(Node* root){

    if(root == NULL) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void getInorder(Node* root, vector<int>& seq){

    if(root == NULL) return;

    getInorder(root->left, seq);
    seq.push_back(root->val);
    getInorder(root->right, seq);
}

vector<int> mergeSeq(vector<int>& inorder1, vector<int>& inorder2){

    vector<int> result;

    int i = 0;
    int j = 0;

    while(i < inorder1.size() && j < inorder2.size()){
        if(inorder1[i] <= inorder2[j]) result.push_back(inorder1[i++]);
        else result.push_back(inorder2[j++]);
    }

    while(i < inorder1.size()) result.push_back(inorder1[i++]);
    while(j < inorder2.size()) result.push_back(inorder2[j++]);

    return result;
}

Node* merge2Tress(Node* root1, Node* root2){

    vector<int> inorder1;
    vector<int> inorder2;

    getInorder(root1, inorder1);
    getInorder(root2, inorder2);

    vector<int> mergedSeq = mergeSeq(inorder1, inorder2);

    return buildBalancedBST(mergedSeq, 0, mergedSeq.size()-1);
}

int main(){

    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* root = merge2Tress(root1, root2);

    preorder(root);
    cout << endl;

}
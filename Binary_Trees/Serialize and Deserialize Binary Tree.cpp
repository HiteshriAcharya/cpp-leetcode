#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
        queue<TreeNode*> frontier;
        string result;
        frontier.push(root);

        while(!frontier.empty()){
            TreeNode* curr = frontier.front();
            frontier.pop();
            if(curr != NULL){
                result += to_string(curr->val) + ",";
                frontier.push(curr->left);
                frontier.push(curr->right);
            } else{
                result += "N,";
            }
        }

        return result;
    }

    TreeNode* deserialize(string data) {
        
        queue<TreeNode*> frontier;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');

        TreeNode* root = new TreeNode(stoi(token));
        frontier.push(root);

        while(!frontier.empty()){

            TreeNode* curr = frontier.front();
            frontier.pop();

            if (token == "N" || token == "") return NULL; // Must check for this! It is a possible case in this question!

            getline(ss, token, ',');
            if(token != "N" && token != ""){
                TreeNode* left = new TreeNode(stoi(token));
                curr->left = left;
                frontier.push(left);
            }

            getline(ss, token, ',');
            if(token != "N" && token != ""){
                TreeNode* right = new TreeNode(stoi(token));
                curr->right = right;
                frontier.push(right);
            }
        }

        return root;
    }
};
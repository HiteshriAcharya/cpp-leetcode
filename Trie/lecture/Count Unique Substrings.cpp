#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string key){

        Node* temp = root;
        for(char c : key){
            if(temp->children.count(c) == 0){
                temp->children[c] = new Node;
            }
             temp = temp->children[c];
        }

        temp->endOfWord = true;
    }

    bool search(string key){

        Node* temp = root;

        for(char c : key){
            if(temp->children.count(c) == 1){
                temp = temp->children[c];
            } else{
                return false;
            }
        }

        return temp->endOfWord;
    }

    int countHelper(Node* root){

        int ans = 0;

        for(pair<char, Node*> child : root->children){
            ans += countHelper(child.second);
        }

        return ans + 1;
    }

    int countNodes(){
        return countHelper(root);
    }

};

/**
 * The shared paths are what remove duplicates.
 * Think of one Trie as a global storage of all substrings seen so far. 
 * New nodes mean new unique substrings; 
 * existing nodes mean that substring was already seen.
 */

int countUniqueSubstr(string str){

    Trie trie;

    //Step 1: Find all the suffix
    for(int i = 0; i < str.size(); i++){
        string suffix = str.substr(i);
        // Step 2: Add all suffix in a trie to get the prefix
        // Prefix of Suffix
        trie.insert(suffix);
    }

    return trie.countNodes();
}

int main(){
    string s = "abc";
    cout << countUniqueSubstr(s) << endl;
}
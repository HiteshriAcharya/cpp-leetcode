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

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();  
    }
    
    void insert(string word) {

        Node* temp = root;
        for(char c : word){
            if(temp->children.count(c) == 0){
                temp->children[c] = new Node;
            }
             temp = temp->children[c];
        }
        temp->endOfWord = true;
    }
    
    bool search(string word) {
        Node* temp = root;

        for(char c : word){
            if(temp->children.count(c) == 1){
                temp = temp->children[c];
            } else{
                return false;
            }
        }
        return temp->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;

        for(char c : prefix){
            if(temp->children.count(c) == 1){
                temp = temp->children[c];
            } else{
                return false;
            }
        }

        return true;
    }
};
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

};

int main(){

    vector<string> words = {"the", "a", "there", "their", "any", "thee"};
    Trie trie;

    for(int i = 0; i < words.size(); i++){
        trie.insert(words[i]);
    }

    cout << trie.search("an") << endl;
}
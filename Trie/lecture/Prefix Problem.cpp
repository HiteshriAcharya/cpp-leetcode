#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
        root->freq = -1;
    }

    void insert(string key){

        Node* temp = root;
        for(char c : key){
            if(temp->children.count(c) == 0){
                temp->children[c] = new Node;
                temp->children[c]->freq = 1;
            } else{
                temp->children[c]->freq += 1;
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

    string getPrefix(string word){

        Node* temp = root;
        string prefix = "";

        for(char c : word){
            prefix += c;

            if(temp->children[c]->freq == 1){
                break;
            }
            temp = temp->children[c];
        }
        return prefix;
    }

};

void prefixProblem(vector<string>& dict){

    Trie trie;

    for(string word : dict){
        trie.insert(word);
    }

    for(string word : dict){
        cout << trie.getPrefix(word) << endl;
    }
}

int main(){
    vector<string> dict = {"zebra", "dog", "duck", "dove"};
    prefixProblem(dict);
}
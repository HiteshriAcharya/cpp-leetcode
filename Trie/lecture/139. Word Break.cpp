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

bool helper(Trie& trie, string s){

    if(s.size() == 0) return true;

    for(int i = 0; i < s.size(); i++){
        string first = s.substr(0, i+1);
        string second = s.substr(i+1);

        if(trie.search(first) && helper(trie, second)){
            return true;
        }
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {

    Trie trie;

    for(string word : wordDict){
        trie.insert(word);
    }

    return helper(trie, s);
}

int main(){

    vector<string> wordDict = {"leet","code"};
    string s = "leecode";

    cout << wordBreak(s, wordDict) << endl;
}
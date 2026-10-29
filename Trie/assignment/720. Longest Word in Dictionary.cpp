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

    void longestStringHelper(Node* root, string& ans, string temp){

        for(pair<char, Node*> child : root->children){
            if(child.second->endOfWord){
                temp += child.first;
                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())){
                    ans = temp;
                }
                longestStringHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1); // backtrack to remove last character
            }
        }
    }

    string longestStringWithEOW(){
        string ans = "";
        longestStringHelper(root, ans, "");
        return ans;
    }
};

string longestWord(vector<string>& words) {

    Trie trie;

    for(string word : words){
        trie.insert(word);
    }

    return trie.longestStringWithEOW();
}

int main(){
    vector<string> words = {"a","banana","app","appl","ap","apply"};
    cout << longestWord(words) << endl;
}
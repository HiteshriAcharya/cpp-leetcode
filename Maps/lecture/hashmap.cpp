#include <iostream>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }
};

class Hashmap{

    int totalSize;
    int currSize;
    Node** table;

    int hashFunction(string key){

        int idx = 0;

        for(char c : key){
            idx = idx + (c * c)%totalSize;
        }

        return idx;
    }

public:
    Hashmap(int size){
        totalSize = size;
        currSize = 0;

        table = new Node*[totalSize];

        for(int i = 0; i < totalSize; i++) table[i] = NULL;
    }

    /**
     * We add the new nodes at the top 
     */

    void insert(string key, int val){

        Node* newNode = new Node(key, val);
        int idx = hashFunction(key);
        
        Node* head = table[idx];
        newNode->next = head;
        head = newNode;
    }

    void remove(){

    }
};
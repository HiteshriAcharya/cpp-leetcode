#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache{

    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };

    //head --> Node 1 --> Node 2 --> tail -->  NULL
    //     <--        <--        <--      <--

    void RemoveNode(Node* node){
        
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    //head --> new --> Node 1 --> Node 2 --> tail -->  NULL
    //     <--     <--        <--      <--        <--

    // Add at the head
    void AddNode(Node* node){
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }

public:

    int capacity;
    unordered_map<int, Node*> map;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity){
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (map.find(key) != map.end()){
            Node* node = map[key];
            RemoveNode(node);
            AddNode(node);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {

        if(map.find(key) != map.end()){
            Node* node = map[key];
            node->val = value;
            RemoveNode(node);
            AddNode(node);
            return;
        } 

         if(map.size() == capacity){
            Node* leastUsed = tail->prev;
            RemoveNode(leastUsed);
            map.erase(leastUsed->key);
            delete leastUsed;
        }

        Node* newNode = new Node(key,value);
        AddNode(newNode);
        map[key] = newNode;
        return;
    }

};

int main(){

}
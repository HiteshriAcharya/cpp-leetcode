#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Insert Op: O(1)
 * Search Op: O(1)
 * Remove Op: O(1)
 */

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

    // !! This helps recursively delete the entire LL !!

    ~Node(){
        if(next !=  NULL){
            delete next;
        }
    }
 };

class HashTable{

    int totalSize;
    int currSize;

    Node** table;

    int hashFunction(string key){

        int idx = 0;

        for(int i = 0; i < key.size(); i++){
            idx = (idx + (key[i] * key[i])) %totalSize;
        }

        return idx;
    }

    void rehash(){

        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize *= 2;
        currSize = 0;

        table = new Node*[totalSize];

        for(int i = 0; i < totalSize; i++){
            table[i] = NULL;
        }

        //copy old values
        for(int i = 0; i < oldSize; i++){

            Node* temp = oldTable[i];

            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int totalSize=5){
        this->totalSize = totalSize;
        currSize = 0;

        table = new Node*[totalSize];

        for(int i = 0; i < totalSize; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){

        int idx = hashFunction(key);

        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize += 1;

        double lambda = currSize/(double) totalSize;

        if(lambda > 1) rehash();
    }

    // O(lambda)
    void remove (string key){

        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;

        while(temp != NULL){
            if(temp->key == key){
                if(temp == prev){ //head
                    table[idx] = temp->next;
                } else{
                    prev->next = temp->next;
                }

                currSize--;
            }

            prev = temp;
            temp = temp->next;
        }
    }

    // O(lambda)
    bool exists(string key){

        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key) return true;
            temp = temp->next;
        }

        return false;
    }

    // O(lambda)
    int search(string key){

        int idx = hashFunction(key);

        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key) return temp->val;

            temp = temp->next;
        }
        return -1;
    }

    void print(){

        for(int i = 0; i < currSize; i++){
            Node* temp = table[i];

            cout << "Node: " << i << endl;

            while(temp != NULL){
                cout << temp->val << "->";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main(){

    HashTable ht;

    ht.insert("India", 150);
    ht.insert("SG", 160);
    ht.insert("China", 10);
    ht.insert("USA", 50);
    ht.insert("UK", 0);

    if(ht.exists("India")) cout << "India's score: " << ht.search("India") << endl;

    ht.remove("China");

    ht.print();
}
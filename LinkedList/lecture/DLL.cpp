#include <iostream>
using namespace std;

class Node{

public:
    int data;
    Node* nextAddr;
    Node* prevAddr;

    Node(int data){

        this->data = data;
        prevAddr = nextAddr = NULL;
    }

};

class doublyList{

public:

    Node* head;
    Node* tail;

    doublyList(){

        head = NULL;
        tail = NULL;
    }

     void push_front(int val){

         Node *newNode = new Node(val);

         if (head == NULL)
         {
            head = tail = newNode;
         } else{

            newNode->nextAddr = head;
            head->prevAddr = newNode;
            head = newNode;

        }
    }

    void pop_front(){

        Node* temp = head;
        head = head->nextAddr;

        if(head != NULL){

            head->prevAddr = NULL;
        }

        temp->nextAddr = NULL;
        delete temp;
    }

    void printLL(){

        Node* temp = head;
        while(temp != NULL){

            cout << temp->data << " ";
            temp = temp->nextAddr;
        }

        cout << endl;
    }
};

int main(){

    doublyList DL1;
    DL1.push_front(3);
    DL1.push_front(2);
    DL1.push_front(1);

    DL1.printLL();

    DL1.pop_front();
    DL1.printLL();
}
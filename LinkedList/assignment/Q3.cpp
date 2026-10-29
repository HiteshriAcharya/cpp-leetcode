#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

ListNode* createList(const initializer_list<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int v : values) {
        ListNode* node = new ListNode(v);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

int lengthOfList(ListNode* head){

    int count = 0;

    while(head != NULL){
        count += 1;
        head = head->next;
    }

    return count;
}

ListNode* lastKthNode(ListNode* head, int k, int size){

    for(int i = 0; i < size - k; i++){
        head = head->next;
    }

    return head;
}

ListNode* swapNodes(ListNode* head, int k) {

    int listSize = lengthOfList(head);

    ListNode* right = lastKthNode(head, k, listSize);
    ListNode* left = head;
    
    for(int i = 0; i < k-1; i++){
        left = left->next;
    }

    int temp = right->val;
    right->val = left->val;
    left->val = temp;

    return head;
}

int main() {

    ListNode* head = createList({1,2,3,4,5});

    cout << "Original list:\n";
    printList(head);

    int k = 2;

    head = swapNodes(head, k);
    printList(head);

    return 0;
}
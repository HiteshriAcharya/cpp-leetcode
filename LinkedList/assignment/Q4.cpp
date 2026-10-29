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

/**
 * Very important to think about any case where any of the pointers 
 * suddenly becomes NULL. When the odd ptr becomes NULL, when the 
 * even ptr becomes NULL, what we need to do. 
 * 
 * Trace out the solution!
 */

ListNode* oddEvenList(ListNode* head) {

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* firstEven = even;

    while(odd != NULL && even != NULL){
        odd->next = even->next;
        if(even->next == NULL) break;
        odd = even->next;
        even->next = odd->next;
        even = odd->next;
    }

    odd->next = firstEven;

    return head;
}

int main(){

    ListNode* head = createList({2,1,3,5,6,4,7});

    cout << "Original list:\n";
    printList(head);

    head = oddEvenList(head);
    printList(head);

    return 0;
}
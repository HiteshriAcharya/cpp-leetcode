#include <iostream>
#include <list>
using namespace std;

/**
 * When you are dealing with pointers like here in LL 
 * and you do not know the length, you need to check 
 * for NULL inside EVERY LOOP!! If there it hits NULL,
 * you need to code out what happens next and exit the 
 * fucntion!!
 */

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

ListNode*deleteNodes(ListNode* head,int m,int n){

    ListNode* ptr = head;
    ListNode* from = NULL;
    ListNode* to = NULL;

    while(ptr != NULL){
        
        for(int i = 0; i < m-1 && ptr != NULL; i++){
            ptr = ptr->next;
        }

        if(ptr == NULL){
            return head;
        }

        from = ptr;

        for(int j = 0; j < n && ptr != NULL; j++){
            ptr = ptr->next;
        }

        if(ptr == NULL){
            from->next = NULL;
            return head;
        }

        to = ptr->next;

        from->next = to;
        ptr = from->next;
    }

    return head;
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


int main() {

    ListNode* head = createList({1,2,3,4,5,6,7,8});

    cout << "Original list:\n";
    printList(head);

    int m = 5;
    int n = 4;

    head = deleteNodes(head, m, n);

    cout << "\nAfter deleting " << n << " nodes after every "
         << m << " nodes:\n";
    printList(head);

    return 0;
}

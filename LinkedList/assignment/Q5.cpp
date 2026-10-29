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

ListNode* merge(ListNode* head1, ListNode* head2){

    ListNode dummy(0);
    ListNode* temp = &dummy;

    while(head1 != NULL && head2 != NULL){

        if(head1->val < head2->val){
            temp->next = head1;
            head1 = head1->next;
        } else{
            temp->next = head2;
            head2 = head2->next;
        }

        temp = temp->next;
    }

    if(head1 != NULL){
        temp->next = head1;
    } 

    if(head2 != NULL){
        temp->next = head2;
    }

    return dummy.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    int size = lists.size();
    if(size == 0) return NULL;

    ListNode* mainList = lists[0];

    for(int i = 1; i < size; i++){
        mainList = merge(mainList, lists[i]);
    }

    return mainList;
}

int main(){

    ListNode* head1 = createList({1,4,5});
    ListNode* head2 = createList({1,3,4});
    ListNode* head3 = createList({2,6});

    vector<ListNode*> list = {head1, head2, head3};

    ListNode* mainHead = mergeKLists(list);
    printList(mainHead);

}
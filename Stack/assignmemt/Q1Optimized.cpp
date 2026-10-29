#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

bool isPalindrome(ListNode* head){

    stack<int> s;
    ListNode* curr = head;

    while(curr != NULL){
        s.push(curr->val);
        curr = curr->next;
    }

    curr = head;

    while(curr != NULL){
        
        if(s.top() != curr->val) return false;

        s.pop();
        curr = curr->next;
    }

    return true;
}

int main(){

    ListNode* head = createList({1,2,0,1,3});

    bool result = isPalindrome(head);

    cout << result << endl;
}
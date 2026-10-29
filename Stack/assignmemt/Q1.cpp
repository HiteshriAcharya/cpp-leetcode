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

int lengthOfList(ListNode* head){

    int count = 0;

    while(head != NULL){
        count += 1;
        head = head->next;
    }

    return count;
}

bool isPalindrome(ListNode* head) {

    int size = lengthOfList(head);
    cout << size << endl;
    if(size == 1) return true;
    int mid = size/2;

    ListNode* curr = head;
    stack<int> s;

    for(int i = 0; i < mid; i++){
        s.push(curr->val);
        cout << curr->val << endl;
        curr = curr->next;
    }

    if(size %2 != 0) curr = curr->next;

    for(int i = 0; i < mid; i++){
        cout << curr->val << endl;
        cout << s.top() << endl;
        if(curr->val != s.top()) return false;

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
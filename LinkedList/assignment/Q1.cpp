#include <iostream>
#include <list>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    int count_B = 0;
    int count_A = 0;

    ListNode *B = headB;
    ListNode *A = headA;

    while(B->next != NULL){ count_B += 1; B = B->next;}
    while(A->next != NULL){ count_A += 1; A = A->next;}

    if(A != B) return NULL;

    A = headA;
    B = headB;

    if(count_A > count_B){
        int diff = count_A - count_B;
        while(diff != 0){
            A = A->next;
            diff -= 1;
        }
    } else{
        int diff = count_B - count_A;
        while(diff != 0){
            B = B->next;
            diff -= 1;
        }
    }

    while(A != NULL && B != NULL){

        if(A == B) return A;

        A = A->next;
        B = B->next;
    }

    return NULL;
}
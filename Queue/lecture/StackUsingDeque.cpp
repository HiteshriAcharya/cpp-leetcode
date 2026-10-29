#include <iostream>
#include <deque>
using namespace std;

class Stack{

deque<int> dq;

public:

    void push(int x){

        dq.push_front(x);
    }

    void pop(){
        dq.pop_front();
    }

    int top(){
        return dq.front();
    }
};
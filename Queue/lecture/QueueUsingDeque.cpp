#include <iostream>
#include <deque>
using namespace std;

class Queue{

deque<int> dq;

public:
    void push(int x){
        dq.push_back(x);
    }

    void pop(){
        dq.pop_front();
    }

    int front(){
        return dq.front();
    }

    bool empty(){
        return dq.empty();
    }
};
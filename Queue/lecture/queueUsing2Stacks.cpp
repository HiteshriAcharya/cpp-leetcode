#include <iostream>
#include <stack>
using namespace std;

class MyQueue {

    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        
        if(s1.empty()) s1.push(x);
        else{
            while(!s1.empty()){
                int curr = s1.top();
                s2.push(curr);
                s1.pop();
            }

            s1.push(x);

            while(!s2.empty()){
                int curr = s2.top();
                s1.push(curr);
                s2.pop();
            }
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
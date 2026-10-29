#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <class T>
class Stack{
    vector<T> vec;
public:

    void push(T val){
        vec.push_back(val);
    }

    void pop(){
        vec.pop_back();
    }

    T top(){

        // if(isEmpty()){

        //     cout << "Stack is empty" << endl;
        //     return -1;
        // }

        int lastIdx = vec.size()-1;
        return vec[lastIdx];
    }

    bool isEmpty(){
        bool empty = (vec.size() == 0) ? 1 : 0;
        return empty;
    }
};

template <class J>
class Stack2{

    list<J> l;
public:

    void push(J val){

        l.push_front(val);
    }

    void pop(){

        l.pop_front();
    }

    J top(){

        return l.front();
    }

    bool isEmpty(){

        return l.size() == 0;
    }
};

int main(){

    Stack<string> stack;

    stack.push("world");
    stack.push("hello");

    while(!stack.isEmpty()){

        cout << stack.top() << endl;
        stack.pop();
    }

    Stack2<int> stack2;

    stack2.push(3);
    stack2.push(2);
    stack2.push(1);

    while(!stack2.isEmpty()){

        cout << stack2.top() << endl;
        stack2.pop();
    }
}
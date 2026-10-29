#include <iostream>
#include <stack>
using namespace std;

void pushAtBottom(stack<int> &s, int val)
{

    if (s.empty())
    {
        s.push(val); // push at top = push at bottom
        return;
    }

    int temp = s.top();
    s.pop();

    pushAtBottom(s, val);
    s.push(temp);
}

void reverseStack(stack<int>& s){

    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverseStack(s);

    pushAtBottom(s, temp);
    //s.push(temp);  this does not work you will end up with the same stack. Need to flip as pushed.
}

int main(){

    stack<int> s; //0,1,2,3 vs 3,2,1,0
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(0);

    reverseStack(s);

    while(!s.empty()){

        cout << s.top() << endl;
        s.pop();
    }
}
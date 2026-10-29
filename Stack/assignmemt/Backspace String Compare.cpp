#include <iostream>
#include <stack>
#include <string>

using namespace std;

void populateStack(stack<char> &stack, string s){

    for(char c : s){
        if(c == '#' && stack.empty()) continue;
        else if(c == '#' && !stack.empty()) stack.pop();
        else stack.push(c);
    }
}

bool backspaceCompare(string s, string t) {

    stack<char> s_stack;
    stack<char> t_stack;

    populateStack(s_stack, s);
    populateStack(t_stack, t);

    while(!s_stack.empty() && !t_stack.empty()){
        if(s_stack.top() != t_stack.top()) return false;
        s_stack.pop();
        t_stack.pop();
    }

    if(!s_stack.empty() || !t_stack.empty()) return false;

    return true;
}

int main(){
    string s = "a#c";
    string t = "b";

    bool result = backspaceCompare(s,t);
}
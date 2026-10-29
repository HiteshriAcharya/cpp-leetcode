#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string str){

    stack<char> s;

    for(char c:str){

        if(!s.empty()){

            if (c == ')' && s.top() == '(')
            {
                s.pop();
            }
            else if (c == ']' && s.top() == '[')
            {
                s.pop();
            }
            else if (c == '}' && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        } else {

            s.push(c);
        }
    }

    if(s.empty()){
        return true;
    } else {
        return false;
    }
}

int main(){

    string str;
    cout << "Enter the bracket string: ";
    getline(cin, str);

    bool result = isValid(str);

    cout << "The result is: " << result;
}
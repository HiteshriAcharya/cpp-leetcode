#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValidParenthesis(string str){

    stack<char> openBrackets;

    for(char ch: str){

        if(ch == '(' || ch == '[' || ch == '{'){
            openBrackets.push(ch);
        }
        else if (!openBrackets.empty() && (ch == ')' && openBrackets.top() == '(' ||
                                           ch == ']' && openBrackets.top() == '[' ||
                                           ch == '}' && openBrackets.top() == '{')){

            openBrackets.pop();
        }
        else
        {

            return false;
        }
    }

    if(!openBrackets.empty()){

        return false;
    }

    return true;
}

int main(){

    string input;
    cout << "Enter string: ";
    cin >> input;

    bool result = isValidParenthesis(input);
    cout << result << endl;

}
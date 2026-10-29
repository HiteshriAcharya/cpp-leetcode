#include <iostream>
#include <stack>
#include <string>
using namespace std;

// (x + ((a)) + b)

bool isDuplicateParenthesis(string str){

    stack<char> temp;

    for(char ch:str){

        if(ch == ')'){
            char finding = '(';
            if(temp.top() == finding){
                return true;
            } else{
                while (temp.top() != finding){
                    temp.pop();
                }
                temp.pop();
            }
        } else{
            temp.push(ch);
        }
    }

    return false;

}

int main(){

    string input;
    cout << "Enter string: ";
    cin >> input;

    bool result = isDuplicateParenthesis(input);

    cout << result << endl;
}
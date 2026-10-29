#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseString (string str){

    stack<char> s;
    string temp;

    for(char ch:str){
        s.push(ch);
    }

    while(!s.empty()){

        temp.push_back(s.top());
        s.pop();

    }

    return temp;

}

int main(){

    string str = "abcde fghi";
    string reverse = reverseString(str);
    cout << reverse << endl;
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/**
 * Because this string can be nested, it is best to use a stack
 */

bool charIsDigit(char c){

    if((int)c >= 48 && (int)c <= 57) return true;
    else{ return false; }
}

string decodeString(string s) {

    stack<int> countStack;
    stack<string> wordStack;
    string word;
    int number = 0;

    for(int i = 0; i<s.length(); i++){
        char c = s[i];
        if(charIsDigit(c)){
            number = number*10 + ((int)c - 48);
            cout << "number: " << number << endl;
        } else if(c == '['){

            wordStack.push(word);
            countStack.push(number);
            number = 0;
            word = "";

        } else if(c == ']'){

            string duplicateWord = wordStack.top();
            wordStack.pop();
            int count = countStack.top();
            countStack.pop();
            for(int j = 0; j < count; j++) duplicateWord.append(word);
            word = duplicateWord;
        } else{
            word.append(1,c);
            cout << "word: " << word << endl;
        }
    }
    return word;
}

int main(){

    string s = "3[a2[c]]";
    string decode = decodeString(s);
    cout << decode << endl;
    
}
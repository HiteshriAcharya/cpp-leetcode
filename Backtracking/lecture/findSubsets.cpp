#include <iostream>
#include <string>
using namespace std;

void findSubets(string s, string substring){

    if(s.length() == 0){
        cout << substring << endl;
        return;
    }

    char c = s[0];
    findSubets(s.substr(1, s.length()-1), substring + c); //add the char
    findSubets(s.substr(1, s.length()-1), substring); // do not add the char
}

int main(){

    string s = "abc";
    string substring = "";

    findSubets(s, substring);
}
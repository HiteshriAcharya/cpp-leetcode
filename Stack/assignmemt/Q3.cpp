#include <iostream>
#include <stack>
using namespace std;

string simplifyPath(string path) {

    stack<string> s;
    string currDir = "";
    
    for(int i = 0; i < path.length(); i++){

        char c = path[i];

        if (c == '/') {
            if (currDir == "" || currDir == ".") {
            // ignore
        } else if (currDir == "..") {
            if (!s.empty()) s.pop();
        } else {
            s.push(currDir);
        }
            currDir = "";
        } else {
            currDir.push_back(c);
        }
    }

    // what if the string does not end with '/', the last
    // dir would be lost. So need to check again if currDir 
    // has value stored or not

    if (currDir != "" && currDir != ".") {
        if (currDir == "..") {
            if (!s.empty()) s.pop();
        } else {
            s.push(currDir);
        }
    }
    
    currDir = "";

    if(s.empty()) return "/";

    while(!s.empty()){
        currDir = '/' + s.top() + currDir;
        cout << currDir << endl;
        s.pop();
    }

    return currDir;
}

int main(){

    string s = "/a//b////c/d//././/..";
    string ans = simplifyPath(s);
    cout << ans << endl;
}
#include <iostream>
#include <string>
using namespace std;

void permutations(string s, string ans){

    if(s.size() == 0){
        cout << ans << endl;
        return;
    }

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        string nextStr = s.substr(0,i) + s.substr(i+1, s.size()-i-1); //omit the char chosen
        permutations(nextStr, ans + ch);
    }

}

int main(){

    string s = "abc";
    permutations(s, "");
}
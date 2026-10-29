#include <iostream>
#include <string>
using namespace std;

int balancedStringSplit(string s) {

    int maxNum = 0;
    int RCount = 0;
    int LCount = 0;
    
    for(char c : s){
        if(c == 'R') RCount +=1;
        else LCount +=1;

        if(LCount == RCount){
            maxNum += 1;
            RCount = 0;
            LCount = 0;
        }
    }

    return maxNum;
}

int main(){
    string s = "LLLLRRRR";
    cout << balancedStringSplit(s) << endl;
}
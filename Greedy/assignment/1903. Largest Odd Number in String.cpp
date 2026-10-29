#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {

    while(!num.empty()){
        char c = num.back();
        if(c == '1' || c == '3' || c == '5' || c == '7' || c == '9') return num;
        else num.pop_back();
    }

    return num;
}

int main(){
    string num = "4206";
    cout << largestOddNumber(num) << endl;
}
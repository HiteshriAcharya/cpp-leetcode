#include <iostream>
#include <string>
using namespace std;

bool judgeCircle(string moves) {

    int x = 0;
    int y = 0;

    for(char c : moves){

        if(c == 'U') x += 1;
        else if(c == 'D') x-=1;
        else if(c == 'R') y+=1;
        else y-=1;
    }

    if(x == 0 && y == 0) return true;
    else return false;
}

int main(){
    string moves = "UU";
    bool result = judgeCircle(moves);
    cout << result << endl;
}
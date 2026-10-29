#include <iostream>
using namespace std;

bool isPowerOfThree(int n){
    if(n == 0) return false;
    while(n%3 == 0) n /= 3;
    if(n == 1) return true;
    else return false;
}

int main(){
    int n = 27;
    bool result = isPowerOfThree(n);
    cout << result << endl;
}
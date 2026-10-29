#include <iostream>
using namespace std;

int PrintNthFibonacciNumber(int n){

    if(n == 1){

        return 1;
    }

    if(n == 0){

        return 0;
    }

    return PrintNthFibonacciNumber(n-1) + PrintNthFibonacciNumber(n-2);
}

int main(){

    int result = PrintNthFibonacciNumber(2);
    cout << result << endl;
}
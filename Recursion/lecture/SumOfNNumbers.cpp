#include <iostream>
using namespace std;

int SumOfNNumbers(int n){

    if(n == 1){

        return 1;
    }

    return n + SumOfNNumbers(n-1);
}

int main(){

    int result = SumOfNNumbers(6);
    cout << result << endl;
}
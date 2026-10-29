#include <iostream>
using namespace std;

int friendPairing(int n){

    if(n == 1 || n == 2){

        return n;
    }

    return friendPairing(n-1) + (n-1)*friendPairing(n-2);

}

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int ways = friendPairing(n);

    cout << ways << endl;

}
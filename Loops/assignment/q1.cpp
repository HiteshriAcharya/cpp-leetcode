#include <iostream>
using namespace std;

int main(){

    int n;

    cout << "Enter a number n: ";
    cin >> n;

    int i = n;
    int f = 1;

    while(i >= 1){

        f = f*i;
        i = i - 1;
    }

    cout << n << "! is equal to " << f << endl; 
}
#include <iostream>
using namespace std;

int main(){

    int n;

    cout << "Enter n: ";
    cin >> n;

    int i = n;
    int sum = 0;

    while (i > 0){

        sum = sum + (i % 10);
        i = i / 10;

    }

    cout << "Sum of digits of " << n << " is: " << sum << endl;
}
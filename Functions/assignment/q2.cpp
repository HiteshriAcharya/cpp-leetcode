#include <iostream>
using namespace std;

int sumOfDigits(int n){

    int sum = 0;
    int num = n;

    while(num > 0){

        sum = sum + (num%10);
        num /= 10;
    }

    return sum;
}

int main(){

    int n;
    cout << "Enter a number n: ";
    cin >> n;

    int sum = sumOfDigits(n);

    cout << "Sum of digits of " << n << " is " << sum << endl;


}
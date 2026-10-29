#include <iostream>
using namespace std;

int main()
{
    int a;

    cout << "Enter a 3-digit number: ";
    cin >> a;

    if (a < 100 || a > 999) {
        cout << "Please enter a valid 3 digit number" << endl;
        exit(0);
    }

    // cout << a%10 << endl;
    // cout << a%100 << endl;
    // cout << a % 1000 << endl;

    // cout << a / 10 << endl;
    // cout << a / 100 << endl;
    // cout << a / 1000 << endl;

    // int x = a/100;
    // int y = (a%100)/10;
    // int z = a%10;

    int num = a;  // Creating a copy of a

    int x = num % 10;
    num /= 10;

    int y = num % 10;
    num /= 10;

    int z = num;

    int sum =  (x*x*x) + (y*y*y) + (z*z*z);

    if(sum == a){
        cout << a << " is an Armstrong number" << endl;
    } else {
        cout << a << " is not an Armstrong number" << endl;
    }

}
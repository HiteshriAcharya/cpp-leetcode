#include <iostream>
using namespace std;

int main() {

    int a,b,c;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Enter third number: ";
    cin >> c;

    if(a>=b && a>=c) {
        cout << a << " is greater than both " << b << " and " << c;
    } else if (b>=c){
        cout << b << " is greater than both " << a << " and " << c;
    } else if (a == b && b == c && a == c){
        cout << a << "," << b << " and " << c << " have the same values";
        } else {
        cout << c << " is greater than both " << b << " and " << a;
    }
}
#include <iostream>
using namespace std;

int main(){

    float a,b;
    char c;

    cout << "Enter first number: ";
    cin>>a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Enter operation: ";
    cin >> c;

    switch(c) {

        case '+': cout << a << " + " << b << " = " << a+b << endl;
            break;
        case '-':
            cout << a << " - " << b << " = " << a - b << endl;
            break;
        case '*':
            cout << a << " * " << b << " = " << a * b << endl;
            break;
        case '/':
            cout << a << " / " << b << " = " << a / b << endl;
            break;
        default : cout<< c << " is an invalid operation" << endl;
    }

}
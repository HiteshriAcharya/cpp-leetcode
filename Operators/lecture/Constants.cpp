#include <iostream>
using namespace std;

int main(){

    int a, b;

    a = 3;

    a = a++;

    cout << a << endl;

    a = ++a;

    cout << a << endl;

    b = a++;

    cout << a << endl;
    cout << b << endl;

    b = ++a;

    cout << a << endl;
    cout << b << endl;

    a = a--;

    cout << a << endl;
    cout << b << endl;

    a = --a;

    cout << a << endl;
    cout << b << endl;

    b = a--;

    cout << a << endl;
    cout << b << endl;

    b = --a;

    cout << a << endl;
    cout << b << endl;
}
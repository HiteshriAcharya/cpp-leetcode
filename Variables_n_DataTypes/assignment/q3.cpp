#include <iostream>
using namespace std;

int main()
{
    double P, R, T;

    cout << "Value of P: ";
    cin >> P;
    cout << endl;

    cout << "Value of R: ";
    cin >> R;
    cout << endl;

    cout << "Value of T: ";
    cin >> T;
    cout << endl;

    double output = (P*R*T)/100;

    cout << "The output is: " << output << endl;
}
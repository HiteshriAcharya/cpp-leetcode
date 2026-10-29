#include <iostream>
#include <cmath>
using namespace std;

int curveEquation(int a, int b){

    int output = pow(a,2) + pow(b,2) + 2*a*b;

    return output;

}

int main(){

    int a,b;
    cout << "Enter a number a: ";
    cin >> a;

    cout << "Enter a number b: ";
    cin >> b;

    int output = curveEquation(a,b);

    cout << "The output is: " << output << endl;
}
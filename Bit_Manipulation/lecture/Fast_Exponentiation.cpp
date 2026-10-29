#include <iostream>
using namespace std;

double pow(double a, int b){

    bool isExponentNeg = (b < 0) ? 1 : 0;
    double result = 1;
    double exponent = (isExponentNeg == 1) ? (1/a) : a;
    unsigned long long copy = (b < 0) ? -(long long)b : (long long)b; // need this or else the negation of a very large neg number might not
                                                                      // fit within "int". Hence, need to type cast to long long before negation

    cout << "DEBUG: isExponentNeg: " << isExponentNeg << ",result: " << result << ",exponent: " << exponent << ",b: " << b << endl; 

    while(copy != 0){

        if(copy&1 == 1){

            result *= exponent;
            cout << "DEBUG: result: " << result << " and exponent: " << exponent << endl;
        }

        cout << "DEBUG: exponent: " << exponent << endl;
        exponent *= exponent;
        cout << "DEBUG: exponent: " << exponent << endl;

        copy = copy >> 1;
    }

    return result;
}

int main(){

    double a;
    int b;
    cout << "Enter base a: ";
    cin >> a;

    cout << "Enter exponent b: ";
    cin >> b;

    double result = pow(a,b);
    cout << result << endl;
}
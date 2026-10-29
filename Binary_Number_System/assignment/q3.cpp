#include <iostream>
#include <math.h>
using namespace std;

long long decToBin(long decimal) {

    long long binary = 0;
    int factor = 1;

    while (decimal != 0)
    {
        if (decimal % 2 == 1)
        {
            binary = factor + binary;
            // cout << "DEBUG: " << binary << " ," << factor << " ," << decimal << endl;
        }
        decimal /= 2;
        factor *= 10;
    }
    return binary;
}

long long binToDec(long binary) {
    long long decimal = 0;
    int bit_value;
    int pos = 0;

    while (binary != 0) {
        bit_value = binary % 10;

        if (bit_value == 0) {
        }
        else if (bit_value == 1) {
            decimal += pow (2, pos);
        }
        else {
            cout << "ERROR: Invalid bit value. Please enter in binary format" << endl;
            exit(1);
        }

        binary /= 10;
        pos += 1;
    }
    return decimal;
}

long long binaryAdd(long A, long B){

    long long a, b;
    long long output = 0;
    int carry = 0;
    int factor = 1;

    a = decToBin(A);
    b = decToBin(B);

    cout << "DEBUG: " << a << " " << b << endl;

    while (a != 0 || b != 0 || carry != 0)
    {

        if (a%10 + b%10 + carry == 0) {
        }
        else if (a % 10 + b % 10 + carry == 1){
            output = output + factor;
            if(carry == 1){
                carry = 0;
            }
        } else if (a%10 + b%10 + carry == 2){
            carry = 1;
        } else if (a%10 + b%10 + carry == 3){

            carry = 1;
            output = output + factor;

        }

        factor*=10;
        a/=10;
        b/=10;
    }

    return output;
}

int main(){

    long A,B;
    long long output, OUTPUT;

    cout << "Enter a: ";
    cin >> A;

    cout << "Enter b: ";
    cin >> B;

    output = binaryAdd(A,B);

    cout << "Binary output: " << output << endl;

    OUTPUT = binToDec(output);

    cout << "Decimal output: " << OUTPUT << endl;

}
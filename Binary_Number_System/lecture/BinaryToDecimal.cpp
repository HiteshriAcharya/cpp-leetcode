#include <iostream>
#include <math.h>
using namespace std;


long long binToDec(long binary){

    long long decimal = 0;
    int bit_value;
    int pos = 0;

    while(binary != 0){

        bit_value = binary%10;

        if(bit_value == 0){
            
        } else if(bit_value == 1){
            decimal += pow(2,pos);
        } else {
            cout << "ERROR: Invalid bit value. Please enter in binary format" << endl;
            exit(1);
        }

        binary/=10;
        pos+=1;
    }

    return decimal;
}


int main(){

    long long binary_input, decimal_output;
    cout << "Enter a binary number: ";
    cin >> binary_input;

    decimal_output = binToDec(binary_input);

    cout << "The decimal equivalent is : " << decimal_output << endl;

}
#include <iostream>
#include <math.h>
using namespace std;

long long decToBin(long decimal){

    long long binary = 0;
    int factor = 1;

    while(decimal != 0){

        if(decimal%2 == 1){

            binary = factor + binary;
            //cout << "DEBUG: " << binary << " ," << factor << " ," << decimal << endl;
        } 

        decimal/=2;
        factor *= 10;
    }

        return binary;
}

int main(){

    long decimal;
    long long binary;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    binary = decToBin(decimal);
    cout << "The binary equivalent is: " << binary << endl;

}
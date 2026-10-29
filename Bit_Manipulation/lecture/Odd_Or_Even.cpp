#include <iostream>
using namespace std;

bool oddOrEven(int number){

    return (number & 1);
}


int main(){

    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << oddOrEven(number) << endl;
}
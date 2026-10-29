#include <iostream>
using namespace std;

/**
 * Must include num>0 because it is not a power of 2 but it will return 0 for this
 * and also make sure of laws of precedence. == 0 takes a greater precedence than
 * &
 */

bool isPowerOf2(int num){

    return (num > 0) && ((num & (num-1)) == 0); 
}

int main(){

    int num;

    cout << "Enter num: ";
    cin >> num;

    cout << isPowerOf2(num) << endl;

}
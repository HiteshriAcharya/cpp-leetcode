#include <iostream>
#include <math.h>
using namespace std;

/** 
 * We must use MOD at each step of the computation
 * because we don't want it to overflow at ANY STAGE
 */
const long long MOD = 1e9 + 7;

unsigned long long customPow(int options, unsigned long long n){

    unsigned long long result = 1;
    unsigned long long exponent = options;
    unsigned long long power = n;

    while (power > 0){

        if((power & 1) == 1){
            result = (result*exponent)%MOD;
        }

        power = power >> 1;
        exponent = (exponent*exponent)%MOD;
    }

    return result%MOD;
}

unsigned long long goodNumbers(unsigned long long n){

    unsigned long long total;
    unsigned long long evenPower;
    unsigned long long oddPower;

    oddPower = n/2 ;
    evenPower = (n%2 == 0) ? n/2 : (n/2) + 1;

    total = (customPow(5, evenPower)%MOD) * (customPow(4,oddPower) % MOD) % MOD;

    return total;
}

int main(){

    unsigned long long n = 1924;
    unsigned long long total = goodNumbers(n);
    cout << total << endl;
}
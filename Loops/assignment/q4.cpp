#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){

    if(n == 1){

        return false;
    }
    
    int i = 2;
    while(i <= sqrt(n)){

        if(n % i == 0){
            return false;
        } 

        i +=1;
    }

    return true;
}

int main(){

    int n;
    cout << "Enter a number n: ";
    cin >> n;

    int i = 2;

    while(i <= n){

        if(isPrime(i)){

            cout << i << endl;
        }

        i +=1;
    }

}



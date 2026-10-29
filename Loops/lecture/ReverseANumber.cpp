#include <iostream>
using namespace std;

int main(){

    int n;

    cout << "Enter n: ";
    cin >> n;

    int i = n;
    int sum = 0;

    while(i > 0){

        sum *= 10;
        sum += i%10;
        i /=10;

    }

    cout << "Reverse of the number " << n << " is: " << sum << endl;
}
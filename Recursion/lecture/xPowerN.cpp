#include <iostream>
using namespace std;

int powerOf(int x, int n){

    if(n == 1){

        return x;
    }

    if(n == 0){

        return 1;
    }

    int half = powerOf(x, n / 2);

        if (n % 2 == 0)
    {

        return half * half;
    }
    else
    {

        return half * half * x;
    }
}

int main(){

    int x,n;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter n: ";
    cin >> n;

    int result = powerOf(x,n);
    cout << result << endl;
}
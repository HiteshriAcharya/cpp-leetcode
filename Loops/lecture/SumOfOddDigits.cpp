#include <iostream>
using namespace std;

bool isOdd(int n){

    if(n % 2 != 0){

        return 1;
    } else {

        return 0;
    }
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    int i = n;
    int sum = 0;

    while (i > 0)
    {

        if(isOdd(i)){

            sum = sum + (i % 10);
        }

        i = i / 10;
    }

    cout << "Sum of odd digits of " << n << " is: " << sum << endl;
}
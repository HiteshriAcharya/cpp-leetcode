#include <iostream>
#include <cmath>
using namespace std;

int power(int base, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

bool isArmstrong(int n)
{
    int original = n;
    int sum = 0;

    // Calculate the number of digits in n
    int len = floor(log10(n) + 1);

    while (n > 0)
    {
        int digit = n % 10;
        sum += power(digit, len);
        n /= 10;
    }

    return (sum == original);
}

int main()
{
    int n;
    cout << "Enter a number n: ";
    cin >> n;

    if (isArmstrong(n))
    {
        cout << n << " IS an Armstrong number" << endl;
    }
    else
    {
        cout << n << " IS NOT an Armstrong number" << endl;
    }

    return 0;
}

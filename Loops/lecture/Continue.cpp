#include <iostream>
using namespace std;

int main()
{

    while (1)
    {

        int n;
        cout << "Enter a number that is not a multiple of 10: ";
        cin >> n;

        if (n % 10 == 0)
        {
            continue;
        }

        cout << "Number you have entered: "<< n << endl;
    }
}
#include <iostream>
using namespace std;

int main(){

    int row;

    cout << "Enter the number of rows you want: ";
    cin >> row;

    int stars, spaces;

    for(int i = 1; i <= row; i+=1){

        cout << "*";

        stars = i - 1;

        spaces = 2*(row - i);

        for(int j = 1; j <= stars; j+=1){

            cout << "*";
        }

        for(int k = 1; k <= spaces; k+=1){

            cout << " ";
        }

        for(int l = 1; l <= stars; l+=1){

            cout << "*";
        }

        cout << "*";
        cout << endl;
    }

    for (int a = row; a >= 1; a -= 1)
    {

        cout << "*";

        stars = a - 1;

        spaces = 2 * (row - a);

        for (int b = 1; b <= stars; b += 1)
        {

            cout << "*";
        }

        for (int c = 1; c <= spaces; c += 1)
        {

            cout << " ";
        }

        for (int d = 1; d <= stars; d += 1)
        {

            cout << "*";
        }

        cout << "*";
        cout << endl;
    }
}
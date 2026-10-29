#include <iostream>
using namespace std;

int main(){

    int row;

    cout << "Enter the number of rows you want: ";
    cin >> row;

    int stars = 1; // dont have magic numbers!
    int spaces;

    for(int i = 1; i <= row; i+=1){

        spaces = row - i;
        stars = 2*i - 1;

        for(int j = 1; j <= spaces; j+=1){

            cout << " ";
        }

        for(int k = 1; k <= stars; k+=1){

            cout << "*";
        }

        for(int l = 1; l <= spaces; l+=1){

            cout << " ";
        }

        cout << endl;
    }

    for (int i = row; i >= 1; i -= 1)
    {

        spaces = row - i;
        stars = 2*i - 1;

        for (int j = 1; j <= spaces; j += 1)
        {

            cout << " ";
        }

        for (int k = 1; k <= stars; k += 1)
        {

            cout << "*";
        }

        for (int l = 1; l <= spaces; l += 1)
        {

            cout << " ";
        }

        cout << endl;
    }
}
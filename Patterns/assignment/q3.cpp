#include <iostream>
using namespace std;

int main(){

    int row;

    cout << "Enter the number of rows: ";
    cin >> row;

    int spaces;

    for(int i = 1; i <= row; i+=1){

        spaces = row - i;

        for(int j = 1; j <= spaces; j+=1){

            cout << " ";
        }

        for(int k = i; k > 1; k -=1){

            cout << k;
        }

        cout << "1";

        for(int l = 2; l <= i; l+=1 ){

            cout << l;
        }

        for(int m = 1; m <= spaces; m+=1){

            cout << " ";
        }

        cout << endl;
    }
}
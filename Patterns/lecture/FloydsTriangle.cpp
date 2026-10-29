#include <iostream>
using namespace std;

int main(){

    int row;

    cout << "Enter the number of rows you want: ";
    cin >> row;

    int n = 1;

    for(int  i= 1; i <= row; i+=1){

        for(int j = 1; j <= i; j+=1){

            cout << n << " ";
            n+=1;
        }
        cout<< endl;
    }
}
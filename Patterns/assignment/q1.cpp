#include <iostream>
using namespace std;

int main(){

    int row;

    cout << "Enter the number of rows: ";
    cin >> row;

    bool b = 1;

    for(int i = 1; i <= row; i+=1){
        for(int j = 1; j <= i; j+=1){
            cout << b;
            b = !b;
        }

        cout << endl;
    }

}
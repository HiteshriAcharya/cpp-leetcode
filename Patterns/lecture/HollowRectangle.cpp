#include <iostream>
using namespace std;

int main(){

    int row;
    int col;

    cout << "Enter the number of rows you want: ";
    cin >> row;

    cout << "Enter the number of columns you want: ";
    cin >> col;

    for(int i = 1; i <= row; i+=1){

        cout << "*";

        for(int j = 1; j < col - 1; j+=1){

            if (i == 1 || i == row){

                cout << "*";
            } else {

                cout << " ";
            }
        }

        cout << "*";
        cout << endl;
    }

}
#include <iostream>
using namespace std;

int main(){

    int row;

    cout << "Enter the height of the rhombus: ";
    cin >> row;

    int space1, space2;

    for(int i = 0; i < row; i+=1){

        space1 = row - i - 1;
        space2 = i;

        for(int j = 1; j <= space1; j+=1 ){

            cout << " ";
        }

        for (int k = 1; k <= row; k+=1){

            cout << "*";
        }

        // for(int l = 1; l <= space2; l+=1){

        //     cout << " ";
        // }

        cout << endl;
    }
}
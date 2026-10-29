#include <iostream>
using namespace std;

int main(){

    int row;

    cout << "Enter the number of rows you want: ";
    cin >> row;

    int stars, spaces;

    for(int i = 1; i <= row; i +=1){

        stars = i;
        spaces = row - stars;

        for(int j = 1; j<= spaces; j+=1){

            cout << " ";
        }

        for(int k = 1; k <= stars; k+=1){

            cout << "*";
        }

        cout << endl;
    }
}
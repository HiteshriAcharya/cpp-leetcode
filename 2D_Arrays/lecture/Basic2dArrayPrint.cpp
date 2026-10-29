#include <iostream>
using namespace std;

int main(){

    int rows, cols;

    cout<<"Enter rows and cols: ";
    cin >> rows;
    cin >> cols;

    int twoDArray[rows][cols];

    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j++){

            cout << "Enter number for index [" << i << "][" << j << "]" ;
            cin >> twoDArray[i][j];
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){

            cout << twoDArray[i][j] << " ";
        }

        cout << endl;
    }
}
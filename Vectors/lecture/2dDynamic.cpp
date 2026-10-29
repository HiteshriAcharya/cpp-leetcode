#include <iostream>
using namespace std;

int main(){

    int rows, cols;

    cout << "Enter row: ";
    cin >> rows;

    cout << "Enter col: ";
    cin >> cols;

    int* *matrix = new int* [rows];

    for(int i = 0; i < rows; i++){

        matrix[i] = new int [cols];
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "Enter matrix[" << i << "]" << "[" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}
#include <iostream>
using namespace std;

void printAddress(int (*row_ptr)[4], int rows){

    cout << "Address of 0th row" << row_ptr << endl;
    cout << "Address of 1st row" << row_ptr+1 << endl;
    cout << "Address of 2th row" << row_ptr+2 << endl;

    cout << "Value of 0th row" << *row_ptr << endl;
    cout << "Value of 1st row" << *(row_ptr + 1) << endl;
    cout << "Value of 2th row" << *(row_ptr + 2) << endl;

    cout << "arr[2][3]: " << row_ptr[2][3] << " = " << *(*(row_ptr+2) + 3) << endl;
}

int main(){

    int arr[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Enter number for index [" << i << "][" << j << "]";
            cin >> arr[i][j];
        }
    }

    printAddress(arr, 4);
}
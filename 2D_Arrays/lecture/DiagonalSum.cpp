#include <iostream>
using namespace std;

#define MAX 100

int diagonalSumElegant(int arr[][MAX], int row){

    int total = 0;

    for(int i = 0; i < row; i++){
        total += arr[i][i];
        if(i != row-i-1){
            total += arr[i][row-i-1];
        }
    }

    return total;
}

int diagonalSum(int arr[][MAX], int row){

    int pd = 0;
    int sd = 0;
    int total = 0;

    int j = 0;

    for(int i = 0; i < row; i++){
        pd += arr[i][j];
        j+=1;
    }

    j = row-1;

    for(int i = 0; i < row; i++){
        sd += arr[i][j];
        j-=1;
    }

    total = (row%2 == 0) ? (pd+sd) : (pd+sd-arr[row/2][row/2]);
    cout << "pd : " << pd << " sd: " << sd <<" arr[row/2][row/2]: " << arr[row/2][row/2] << endl;
    return total;
}

int main(){

    int rows, cols;

    cout << "Enter rows and cols: ";
    cin >> rows;
    cin >> cols;

    int arr[MAX][MAX];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter number for index [" << i << "][" << j << "]";
            cin >> arr[i][j];
        }
    }

    int total = diagonalSum(arr, rows);
    int total2 = diagonalSumElegant(arr, rows);
    cout << "total sum: " << total << endl;
    cout << "total2 sum: " << total2 << endl;
}
#include <iostream>
using namespace std;

#define MAX 100 // ***NOTE*** : For some reason, with MAX=10000, it does not work

void construct2DArray(int *arr, int size, int row, int col){

    if (size != row * col)
    {
        return;
    }

    int twoDArray[MAX][MAX];

    int rowIndex = 0;
    int colIndex = 0;

    for (int i = 0; i < row * col; i++)
    {
        twoDArray[rowIndex][colIndex] = arr[i];
        colIndex = colIndex == col - 1 ? 0 : colIndex += 1;
        rowIndex = colIndex == 0 ? rowIndex += 1 : rowIndex;
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << twoDArray[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int rows, cols;

    cout << "Enter rows and cols: ";
    cin >> rows;
    cin >> cols;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
       cout << "Enter arr[" << i << "]: " << endl;
       cin >> arr[i]; 
    }
    
    construct2DArray(arr, size, rows, cols);

}
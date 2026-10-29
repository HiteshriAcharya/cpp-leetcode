#include <iostream>
using namespace std;

#define MAX 100

void searchMatrix(int arr[][MAX], int row, int col, int target, int *result){

    for(int i = 0; i < row; i++){
        int colStart = 0;
        int colEnd = col - 1;
        if(target >= arr[i][0] && target <= arr[i][col-1]){
            while(colStart <= colEnd){
                int mid = (colStart+colEnd)/2;
                if(target == arr[i][mid]){
                    result[0] = i;
                    result[1] = mid;
                    return;
                } else if(target < arr[i][mid]){
                    colEnd = mid - 1; 
                } else{
                    colStart = mid + 1;
                }
            }
        }
    }
}

int main(){

    int rows, cols, target;

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

    cout << "Enter target: ";
    cin >> target;

    int result[2] = {-1};

    searchMatrix(arr,rows,cols,target,result);

    cout << "The location of the target number is: [" << *result << "][" << *(result+1) << "]" << endl; 

}
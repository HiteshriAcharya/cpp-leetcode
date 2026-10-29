#include <iostream>
using namespace std;

#define MAX 100

void stairCaseSearchBottom(int arr[][MAX], int row, int col, int target, int *result){

    int r, c;
    r = row -1;
    c = 0;

    while (r >= 0 && c <= col - 1)
    {

        if (target == arr[r][c])
        {
            result[0] = r;
            result[1] = c;
            return;
        }  
        else if (target < arr[r][c])
        {
            r -= 1;
        }
        else
        {
            c += 1;
        }
    }
}

void stairCaseSearch(int arr[][MAX], int row, int col, int target, int *result){

    int r,c;
    r = 0;
    c = col-1;

    while(r <= row-1 && c >= 0){

        if(target == arr[r][c]){
            result[0] = r;
            result[1] = c;
            return;
        } else if(target < arr[r][c]){
            c -= 1;
        } else {
            r += 1;
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
    int result2[2] = {-1};

    stairCaseSearch(arr,rows,cols,target,result);
    stairCaseSearchBottom(arr,rows,cols,target,result2);

    cout << "The location of the target number is from method 1: [" << *result << "][" << *(result + 1) << "]" << endl;
    cout << "The location of the target number is from method 2: [" << *result2 << "][" << *(result2 + 1) << "]" << endl;
}
#include <iostream>
using namespace std;

#define MAX 100

void printSpiralMatrix(int arr[][MAX], int row, int col){

    int rowIndexStart, colIndexStart, rowIndexEnd, colIndexEnd, coveredIndex;

    rowIndexStart = 0;
    colIndexStart = 0;
    rowIndexEnd = row - 1;
    colIndexEnd = col - 1;
    coveredIndex = 0;

    /**
     * 
     * There is another method of checking as well. The condition 
     * coveredIndex < row*col can be replaced with 
     * rowIndexStart <= rowIndexEnd && colIndexStart <= colIndexEnd
     * and within the bottom and left loops, the condition will be 
     * if(rowIndexStart == rowIndexEnd) and if(colIndexStart == colIndexEnd)
     * 
     */
    
    while(coveredIndex < row*col){

        //Top
        for(int i = colIndexStart; i <= colIndexEnd; i++){
            cout << arr[rowIndexStart][i] << " ";
            coveredIndex+=1;
            //cout << "coveredIndex at top: " << coveredIndex << endl;
        }

        //Right
        for(int j = rowIndexStart+1; j <= rowIndexEnd; j++){
            cout << arr[j][colIndexEnd] << " ";
            coveredIndex+=1;
            //cout << "coveredIndex at right: " << coveredIndex << endl;
        }

        //Bottom
        for(int k = colIndexEnd-1 ; k >= colIndexStart; k--){
            if(coveredIndex < row*col){
                cout << arr[rowIndexEnd][k] << " ";
                coveredIndex += 1;
                //cout << "coveredIndex at bottom: " << coveredIndex << endl;
            }
        }

        //Left
        for(int l = rowIndexEnd-1; l >= rowIndexStart+1; l--){
            if(coveredIndex < row*col){
                cout << arr[l][colIndexStart] << " ";
                coveredIndex += 1;
                //cout << "coveredIndex at left: " << coveredIndex << endl;
            }
        }

        rowIndexStart+=1;
        rowIndexEnd-=1;
        colIndexStart+=1;
        colIndexEnd-=1;

    }
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

    printSpiralMatrix(arr,rows,cols);


}
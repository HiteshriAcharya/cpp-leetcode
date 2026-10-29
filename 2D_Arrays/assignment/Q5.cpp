#include <iostream>
using namespace std;

#define SIZE 4

/**
 * 90: transpose & mirror row
 * 180: mirror row & mirror column
 * 270: transpose & mirror column
 */

 void rotate(int matrix[][SIZE], int n){

     // transpose
     for (int i = 0; i < n; i++)
     {
         for (int j = i + 1; j < n; j++)
         {

             swap(matrix[i][j], matrix[j][i]);
         }
     }

     // mirror
     int start = 0;
     int end = n - 1;

     while (start < end)
     {
         for (int i = 0; i < n; i++)
         {
             swap(matrix[i][start], matrix[i][end]);
         }

         start += 1;
         end -= 1;
     }
 }

int main(){
    
    int n = SIZE;
    int matrix[SIZE][SIZE] = {{ 5, 1, 9, 11 }, 
                               {2, 4, 8, 10}, 
                               {13, 3, 6, 7}, 
                               {15, 14, 12, 16}};

    rotate(matrix, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}
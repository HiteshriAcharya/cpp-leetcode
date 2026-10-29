#include <iostream>
#include <vector>
using namespace std;

int dx[8] = { 2,  1, -1, -2, -2, -1,  1,  2 };
int dy[8] = { 1,  2,  2,  1, -1, -2, -2, -1 };

void printVector(vector<vector<int>> &board, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

void knightMoves(int n, vector<vector<int>> &board, int movesLeft, int row, int col){

    if(row < 0 || row >= n || col < 0 || col >= n) return;

    if(board[row][col] != 0) return;

    board[row][col] = (n*n) - movesLeft;

    if(movesLeft == 1){
        printVector(board, n);
        cout << endl;
        board[row][col] = 0;
        return;
    }

    for(int i = 0; i < 8; i++){

        int nr = row + dx[i];
        int nc = col + dy[i];

        knightMoves(n, board, movesLeft-1, nr, nc);
    }

    board[row][col] = 0;
}

int main(){

    int n = 8;
    vector<vector<int>> board (n, vector<int> (n,0));
    knightMoves(n, board, n*n, 0, 0);
}
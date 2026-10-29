#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>> &board, string word, int r, int c, int idx){

    const int dr[4] = {1,-1,0,0};
    const int dc[4] = {0,0,1,-1};

    // OUT OF BOUNDS
    if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size()){
        return false;
    }

    // NOT THE CHAR
    if(board[r][c] != word[idx]){
        return false;
    }

    // ALL CHARS HAVE BEEN FOUND
    if(idx == word.size() - 1){
        return true;
    }

    char temp = board[r][c];
    board[r][c] = '#';

    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(dfs(board, word, nr, nc, idx + 1)){
            return true;
        }
    }

    board[r][c] = temp;
    return false;
}

bool exist(vector<vector<char>> &board, string word){

    int R = board.size();
    int C = board[0].size();

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(board[i][j] == word[0]){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){


}
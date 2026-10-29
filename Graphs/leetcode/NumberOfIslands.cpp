#include <iostream>
#include <vector>
using namespace std;

void dfs(int R, int C, int i, int j, vector<vector<char>> &grid, vector<vector<char>> &visited){

    if(i >= R || i < 0 || j >= C || j < 0) return;

    if(grid[i][j] != '1') return;

    if(visited[i][j] != '.') return;

    visited[i][j] = '#';

    int nr[4] = {1,-1,0,0};
    int nc[4] = {0,0,1,-1};

    for(int k = 0; k < 4; k++){
        
        int row = nr[k] + i;
        int col = nc[k] + j;

        dfs(R,C,row,col,grid,visited);
    }
}

int numIslands(vector<vector<char>> &grid){

    int R = grid.size();
    int C = grid[0].size();

    vector<vector<char>> visited(R, vector<char> (C, '.'));

    int islandCount = 0;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(visited[i][j] == '.' && grid[i][j] == '1'){
                islandCount += 1;
                dfs(R,C,i,j,grid,visited);
            }
        }
    }
    return islandCount;
}

int main(){

    vector<vector<char>> grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}};
    
    int result = numIslands(grid);
    cout << result << endl;
}
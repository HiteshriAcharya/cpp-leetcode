#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>> &grid, queue<pair<int,int>> &rottenOranges, int R, int C, int totalOranges){

    int numOfRottenOranges = 0;
    int minutes = 0;
    int nr[4] = {1,-1,0,0};
    int nc[4] = {0,0,1,-1};
 
    while(!rottenOranges.empty()){
        
        // IMPORTANT so we do not count the loops where all the oranges around
        // are already rotten
        
        bool rottedThisMinute = false; 

        int currQueueSize = rottenOranges.size();
        numOfRottenOranges += currQueueSize;

        for(int i = 0; i < currQueueSize; i++){

            int currRow = rottenOranges.front().first;
            int currCol = rottenOranges.front().second;
            rottenOranges.pop();

            for(int k = 0; k < 4; k++){

                int nextRow = currRow + nr[k];
                int nextCol = currCol + nc[k];

                if(nextRow >= 0 && nextRow < R && nextCol >= 0 && nextCol < C){
                    if(grid[nextRow][nextCol] == 1){
                        grid[nextRow][nextCol] = 2;
                        rottenOranges.push({nextRow,nextCol});
                        rottedThisMinute = true;
                    }
                }
            }
        }

        if(rottedThisMinute) minutes += 1;
    }

    if(totalOranges == numOfRottenOranges) return minutes;
    else return -1;
}

int orangesRotting(vector<vector<int>>& grid) {

    queue<pair<int,int>> rottenOranges;
    int R = grid.size();
    int C = grid[0].size();
    int totalOranges = 0;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(grid[i][j] != 0) totalOranges += 1;
            if(grid[i][j] == 2) rottenOranges.push({i,j});
        }
    }

    int minutes = bfs(grid, rottenOranges, R, C, totalOranges);
    return minutes;
}

int main(){

    vector<vector<int>> grid = {
    {2, 1, 1},
    {1, 1, 0},
    {0, 1, 1}};

    int result = orangesRotting(grid);

    cout << result << endl;

}
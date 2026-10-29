#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int islandPerimeter(vector<vector<int>> &grid){

    int R = grid.size();
    int C = grid[0].size();
    int perimeter = 0;

    vector<vector<char>> visited(R, vector<char> (C,0));

    const int dr[4] = {1,-1,0,0};
    const int dc[4] = {0,0,1,-1};

    int sr = -1;
    int sc = -1;

    for(int i = 0; i < R; i ++){
        for(int j = 0; j < C; j ++){
            if(grid[i][j] == 1){
                sr = i;
                sc = j;
                break;
            }
        }

        if(sr != -1) break;
    }

    if(sr == -1) return 0;

    stack<pair<int,int>> frontier;
    frontier.push({sr,sc});
    visited[sr][sc] = 1;

    while(!frontier.empty()){

        pair<int,int> current = frontier.top();
        frontier.pop();

        int r = current.first;
        int c = current.second;

        perimeter += 4;

        for(int k = 0; k < 4; k++){

            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1){

                perimeter -= 1;

                if (visited[nr][nc] != 1){
                    
                    frontier.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
    }

    return perimeter;
}

int main(){


}
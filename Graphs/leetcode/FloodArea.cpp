#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;


vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int colour){

    int R = image.size();
    int C = image[0].size();

    //INITIAL_STATE
    int initial_state = image[sr][sc];

    //FRONTIER
    stack<pair<int,int>> frontier;
    frontier.push({sr,sc});


    //VISITED
    vector<vector<char>> visited(R, vector<char>(C,0));
    visited[sr][sc] = 1;


    //ACTIONS. 
    const int dr[4] = {1,-1,0,0};
    const int dc[4] = {0,0,1,-1};

    while(!frontier.empty()){

        pair<int,int> current = frontier.top();
        frontier.pop();

        int r = current.first;
        int c = current.second;

        image[r][c] = colour;

        for(int k = 0; k < 4; k++){

            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < R && nc >= 0 && nc < C && visited[nr][nc] != 1 && image[nr][nc] == initial_state){

                frontier.push({nr,nc});
                visited[nr][nc] = 1;
            }
        }
    }

    return image;
}

int main(){


}
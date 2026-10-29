#include <iostream>
#include <vector>
using namespace std;

/**
 * We need to keep track of the cells that have been visited in this case.
 * This is because we should not be ping ponging between two cells forever.
 * 
 * In the grid ways question this does not happen because the rows and col 
 * are always increasing. There is no way to go back to the previous visited
 * cell
 */

void ways(vector<vector<int>> &maze, vector<vector<char>> &temp, string ans, int n, int row, int col){

    if(row < 0 || col < 0 || row >= n || col >= n) return;

    if(maze[row][col] == 0) return;
    if(temp[row][col] == '!') return;

    if(row == n-1 && col == n-1){

        cout << ans << endl;
        return;
    }

    temp[row][col] = '!';

    ways(maze, temp, ans + 'R', n, row, col+1); // right
    ways(maze, temp, ans + 'L', n, row, col-1); // left
    ways(maze, temp, ans + 'U', n, row-1, col); // up
    ways(maze, temp, ans + 'D', n, row+1, col); //down 


    temp[row][col] = '.';

}

int main(){

    vector<vector<int>> maze = {{1,0,0,0},
                                {1,1,0,1},
                                {1,1,0,0},
                                {0,1,1,1}};
    int n = 4;

    string ans;

    vector<vector<char>> temp(n, vector<char> (n, '.'));

    ways(maze, temp, ans, n, 0, 0);

}
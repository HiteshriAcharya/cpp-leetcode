#include <iostream>
#include <vector>
using namespace std;

/**
 * Can make it faster with DP
 */

int countUniquePaths(int m, int n, int r, int c){
    if(r >= m || c >= n) return 0;
    if(r == m-1 && c == n-1) return 1;
    return countUniquePaths(m, n, r+1, c) + countUniquePaths(m, n, r, c+1);
}

int uniquePaths(int m, int n) {

    return countUniquePaths(m,n,0,0);
}

int main(){
    int m = 3;
    int n = 7;
    cout << uniquePaths(m,n) << endl;
}
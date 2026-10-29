#include <iostream>
#include <vector>
using namespace std;

int ways(int r, int c, int m, int n, string pathways){

    // Base Case
    if(r == m-1 && c == n-1){
        cout << pathways << endl;
        return 1;
    }

    //Constraints
    if(r >= m) return 0;
    if(c >= n) return 0;

    int way1 = ways(r, c+1, m, n, pathways+'R');
    int way2 = ways(r+1, c, m, n, pathways+'D');

    return way1 + way2;
}

int main(){

    int m = 3;
    int n = 3;
    string pathways;

    int totalWays = ways(0,0,m,n, pathways);
    cout << totalWays << endl;
}
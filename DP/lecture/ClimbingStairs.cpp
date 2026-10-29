#include <iostream>
#include <vector>
using namespace std;

/**
 * O(2^n) time complexity
 */

/**
 * Firstly, must return 1 for n == 0. The range of n in the leetcode 
 * is 0 to 45. At n == 0, there is only 1 step. 
 * 
 * So since n == 0 return 1 and n == 1 returns 1, we do not need to keep n == 2
 * anymore. 
 */

int ways_rec(int n){

    if(n == 0) return 1;
    if(n == 1) return 1;

    return ways_rec(n-1) + ways_rec(n-2);
}

int ways_dp_memoization(int n, vector<int> &dp){

    if(n == 0) return 1;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];

    dp[n] = ways_dp_memoization(n-1, dp) + ways_dp_memoization(n-2, dp);
    return dp[n];
}

int ways_dp_tabulation(int n){

    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int ways_dp_tabulation_variation(int n){

    vector<int> dp(n+1, -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    return dp[n];
}

int main(){

    int n = 4;
    vector<int> dp(n+1, -1);
    cout << ways_rec(n) << endl;
    cout << ways_dp_memoization(n, dp) << endl;
    cout << ways_dp_tabulation(n) << endl;
    cout << ways_dp_tabulation_variation(n) << endl;
}
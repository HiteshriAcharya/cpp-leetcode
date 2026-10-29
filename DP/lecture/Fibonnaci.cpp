#include <iostream>
#include <vector>
using namespace std;

int fib_rec(int n){

    if(n == 1) return 1;
    if(n == 0) return 0;

    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_dp_memoization(int n, vector<int> &dp){

    if(n == 0) return 0;
    if(n == 1) return 1;

    if(dp[n] != -1) return dp[n];

    dp[n] = fib_dp_memoization(n-1, dp) + fib_dp_memoization(n-2, dp);
    return dp[n];
}

int fib_dp_tabulation(int n){

    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main(){

    int n = 6;
    vector<int> dp(n+1, -1);
    cout << fib_dp_memoization(n,dp) << endl;
    cout << fib_dp_tabulation(n) << endl;
}
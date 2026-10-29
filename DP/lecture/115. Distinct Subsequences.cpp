#include <iostream>
using namespace std;

int numDistinct_Mem(string s, 
                    string t, 
                    int n,
                    int m,
                    vector<vector<int>>& dp){

    if(n == 0 && m != 0){
        return 0;
    } else if(m == 0){
        return 1;
    } else if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(s[n-1] == t[m-1]){
        dp[n][m] = numDistinct_Mem(s,t,n-1,m-1,dp) + numDistinct_Mem(s,t,n-1,m,dp);
    } else{
        dp[n][m] = numDistinct_Mem(s,t,n-1,m,dp);
    }

    return dp[n][m];
}

int numDistinct(string s, string t) {

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return numDistinct_Mem(s,t, n, m, dp);
}

int main(){

    string s = "babgbag";
    string t = "bag";

    cout << numDistinct(s,t) << '\n';
}
#include <iostream>
using namespace std;

int longestCommonSubsequence_Mem(string& text1, 
                                 string& text2,
                                 int idx1,
                                 int idx2,
                                 vector<vector<int>>& dp){

    if(idx1 == 0 || idx2 == 0){
        return 0;
    } else if(dp[idx1][idx2] != -1){
        return dp[idx1][idx2];
    }

    if(text1[idx1-1] == text2[idx2-1]){
        dp[idx1][idx2] = 1 + longestCommonSubsequence_Mem(text1,text2, idx1-1, idx2-1, dp);
    } else{
        dp[idx1][idx2] = max(longestCommonSubsequence_Mem(text1,text2, idx1-1, idx2, dp),
                             longestCommonSubsequence_Mem(text1,text2, idx1, idx2-1, dp));
    }

    return dp[idx1][idx2];
}

int longestCommonSubsequence(string text1, string text2) {
    
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return longestCommonSubsequence_Mem(text1, text2, n, m, dp);
}

int main(){

    string text1 = "abcde";
    string text2 = "ace";

    cout << longestCommonSubsequence(text1, text2) << endl;
}
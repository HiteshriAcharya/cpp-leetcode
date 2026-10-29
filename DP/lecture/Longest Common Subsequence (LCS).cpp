#include <iostream>
#include <vector>
using namespace std;

/**
 * Method 1: Recursion
 * 
 * TC is O(2^n+m) and this is really bad!
 * 
 * The main logic is that we remove the last char from either of the strings
 * and try to run the recursion. There are overlapping problems for this. 
 * 
 */

 int lcsRecusion(string s, string t){
    int n = s.size();
    int m = t.size();

    if(n == 0 || m == 0) return 0;

    if(s[n-1] == t[m-1]){
        return 1 + lcsRecusion(s.substr(0, n-1), t.substr(1, m-1));
    } else{
        int result1 = lcsRecusion(s.substr(0, n-1), t);
        int result2 = lcsRecusion(s, t.substr(1, m-1));
        return max(result1, result2);
    }
 }


/**
 * Method 2: Memoization
 * 
 * TC is O(n*m)
 */

 int lcsMem(string s, string t, vector<vector<int>> dp){

    int n = s.size();
    int m = t.size();

    if(n == 0 || m == 0) return 0;

    if(dp[n][m] != 1){
        return dp[n][m];
    }

    if(s[n-1] == t[m-1]){
        dp[n][m] = 1 + lcsMem(s.substr(0, n-1), t.substr(1, m-1));
    } else{
        int result1 = lcsMem(s.substr(0, n-1), t);
        int result2 = lcsMem(s, t.substr(1, m-1));
        dp[n][m] = max(result1, result2);
    }

    return dp[n][m];
 }

/**
* Method 3: Tabulation
*/

int main(){

    string s = "abcde";
    string t = "ace";

    vector<vector<int>> dp(s.size(), vector<int> (t.size(), -1));
    cout << lcsRecusion(s,t) << endl;
    cout << lcsMem(s,t,dp) << endl;

}

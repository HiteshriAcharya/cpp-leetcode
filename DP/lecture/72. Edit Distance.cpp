#include <iostream>
using namespace std;

int minDistance(string word1, string word2) {

    // Convert word1 -> word2

    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // word2 is exhausted => word1 has extra characters
    // so delete all remaining characters from word1

    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }

    // word1 is exhausted => word2 still has characters left
    // so insert all remaining characters of word2 into word1

    for(int j = 0; j <= m; j++){
        dp[0][j] = j;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(word1[i-1] == word2[j-1]){

                // Characters already match, so no operation is needed.
                // Both characters are handled, so move back in both strings.
                dp[i][j] = dp[i-1][j-1];
            } else{
                dp[i][j] = 1 + min(

                    // DELETE word1[i-1]:
                    // remove the current character from word1.
                    // word1 moves back, but word2 stays at the same position.
                    dp[i-1][j], 
                    
                    min(

                        // INSERT word2[j-1] into word1:
                        // the inserted character matches the current character of word2.
                        // word1 stays at the same position, while word2 moves back.
                        dp[i][j-1], 

                        // REPLACE word1[i-1] with word2[j-1]:
                        // both current characters are now handled,
                        // so move back in both strings.
                        dp[i-1][j-1]));
            }
        }
    }

    return dp[n][m];
}

int main(){

    string word1 = "horse";
    string word2 = "ros";

    cout << minDistance(word1, word2) << endl;
}
#include <iostream>
using namespace std;

int longestPalindromeSubseq(string s) {
    
    int n = s.size();
    string s2(s.rbegin(), s.rend());

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i-1] == s2[j-1]){
                curr[j] = 1 + prev[j-1];
            } else{
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[n];
}

int main(){

    string s = "bbbab";
    cout << longestPalindromeSubseq(s) << endl;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * We have 128 ASCII values in the original ASCII and 256 in the extended ASCII
 * This questions includes everything, not just small letter characters.
 */

void printFreq(vector<int> freq){

    for(int i = 0; i < freq.size(); i++){
        cout << freq[i] << " ";
    }
    cout << endl;
}

int lengthOfLongestSubstring(string s) {

    if(s.empty()) return;

    vector<int> freq (128, 0);
    int start = 0;
    int maxLen = 1;
    freq[s[0]] += 1;

    for(int curr = 1; curr < s.length(); curr++){
        cout << "char is: " << s[curr] << endl;
        if(freq[s[curr]] == 0){
            freq[s[curr]] += 1;
            maxLen = max(maxLen, curr-start+1);
            printFreq(freq);
        } else{
            cout << "duplicate!" << endl;
            while(freq[s[curr]] != 0 && start < curr){
                cout << "removing " << s[start] << endl;
                freq[s[start]] -= 1;
                start += 1;
                printFreq(freq);
                cout << "now the start is at " << s[start] << endl;
            }
            freq[s[curr]] += 1;
        }
    }

    return maxLen;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
}
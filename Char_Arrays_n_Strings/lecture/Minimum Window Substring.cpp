#include <iostream>
#include <vector>
#include <string>
using namespace std;

string minWindow(string s, string t) {

    unordered_map<char, int> global;
    for(char c : t) global[c] += 1;

    int needed = global.size(); // unique characters

    int left = 0;
    int formed = 0;
    int bestStart = 0;
    int bestLen = INT32_MAX;
    
    unordered_map<char, int> curr;

    for(int right = 0; right < s.size(); right++){

        curr[s[right]] += 1;
        if(global.count(s[right]) && curr[s[right]] == global[s[right]]) formed += 1; 

        while(needed == formed){

            if(bestLen > right - left + 1){
                bestLen = right - left + 1;
                bestStart = left;
            }

            curr[s[left]] -= 1;
            if(global.count(s[left]) && curr[s[left]] < global[s[left]]) formed -= 1;
            left += 1;
        }
    }

    if (bestLen == INT32_MAX) return "";
    return s.substr(bestStart, bestLen);
}

int main(){

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = minWindow(s,t);

    cout << result << endl;
}
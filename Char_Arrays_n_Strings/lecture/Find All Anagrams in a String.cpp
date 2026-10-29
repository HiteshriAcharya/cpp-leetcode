#include <iostream>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {

    int windowSize = p.size();
    unordered_map<char, int> freq;
    vector<int> results;

    for(char c : p) freq[c] += 1;

    unordered_map<char, int> curr;
    for (int i = 0; i < windowSize; i++) curr[s[i]]++;

    if (curr == freq) results.push_back(0);

    for(int i = windowSize; i < s.size(); i++){

        curr[s[i]] += 1;
        curr[s[i - windowSize]] -= 1;

        if(curr[s[i - windowSize]] == 0) curr.erase(s[i - windowSize]);
        if(curr == freq) results.push_back(i - windowSize + 1);
    }

    return results;
}

int main(){
    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result = findAnagrams(s, p);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    cout << endl;
}
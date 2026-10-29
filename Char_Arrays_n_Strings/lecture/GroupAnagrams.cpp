#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> map;

    for(int i = 0; i < strs.size(); i++){
        string curr = strs[i];

        vector<int> freq(26,0);
        for(char c : curr){
            freq[c-'a']+=1;
        }

        string key = "";
        for(int i = 0; i < 26; i++) key += to_string(freq[i]) + "#"; 

        map[key].push_back(curr);
    }

    vector<vector<string>> ans;

    for(auto &[k,v] : map){
        ans.push_back(v);
    }

    return ans;
}

int main(){

}
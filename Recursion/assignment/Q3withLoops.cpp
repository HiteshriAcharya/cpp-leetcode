#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

long long countSubstrings(string s){

    unordered_map<char, long long> freq;
    for(char c: s){
        freq[c]++;
    }

    long long substrings = 0;

    for(auto &p : freq){
        long long m = p.second;
        substrings += m * (m+1)/2;
    }

    return substrings;
}

int main(){

    string s = "abcab";
    cout << countSubstrings(s) << endl;
}
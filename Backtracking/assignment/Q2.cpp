#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> keypad = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};


void combine(const string &digits, string combi, vector<string> &ans){

    if(digits.size() == 0){

        ans.push_back(combi);
        cout << combi << endl;
        return;
    }

    char c = digits[0];

    int index = c - '0';
    string letters = keypad[index];

    for(int i = 0; i < letters.size(); i++){
        combine(digits.substr(1, digits.size() - 1), combi + letters[i], ans);
    }

}

vector<string> letterCombinations(string digits) {

    vector<string> ans;
    string combi;

    combine(digits, combi, ans);

    return ans;

}


int main(){

    string digits = "23";
    vector<string> combinations = letterCombinations(digits);

}
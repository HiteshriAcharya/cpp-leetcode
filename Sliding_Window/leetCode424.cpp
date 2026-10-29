#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k){

    int left = 0;
    int max_substring_len = 0;
    vector<int> alphabet_list(26,0);

    for(int right = 0; right < s.length(); right++){

        alphabet_list[(int)(s[right] - 'A')] += 1;

        while((right-left+1) - *(max_element(alphabet_list.begin(), alphabet_list.end())) > k){ //max_element is time-consuming
            alphabet_list[(int)(s[left] - 'A')] -= 1;
            left += 1;
        }

        max_substring_len = max(max_substring_len, right-left+1);
        cout << "DEBUG: right = " << right << " left = " << left << " max_substring_len = " << max_substring_len << endl;
    }

    return max_substring_len;
}

int main(){

    string s = "ABAB";
    int k = 0;

    int result = characterReplacement(s,k);
    cout << result << endl;
}
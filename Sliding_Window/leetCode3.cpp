#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s){

    if(s.size() == 0){
        return 0;
    }

    vector<int> alphabet_list(256,0);
    int left = 0;
    int max_string_len = 0;

    for(int right = 0; right < s.size(); right++){

        if (alphabet_list[(int)s.at(right)] == 0){

            alphabet_list[(int)s.at(right)] += 1;

        } else{

            while (alphabet_list[(int)s.at(right)] != 0){
                // cout << "DEBUG: char = " << s.at(right) << " alphabet_list[(int)(s.at(right) - 'a')] " << alphabet_list[(int)(s.at(right) - 'a')] << endl;
                alphabet_list[(int)s.at(left)] = 0;
                left += 1;
            }

            alphabet_list[(int)s.at(right)] += 1;
        }

        max_string_len = max(max_string_len, right-left+1);
        // cout << "DEBUG: max_string_len = " << max_string_len << " for right: " << right << " and left: " << left << endl;
    }

    return max_string_len;
}

int main(){

    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;

}
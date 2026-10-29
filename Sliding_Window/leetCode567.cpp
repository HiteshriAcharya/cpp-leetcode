#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool checkInclusion(string s1, string s2){

    if(s1.length() > s2.length()){
        return false;
    }

    int window_size = s1.length();
    unordered_map<char,int> freq_s1;
    unordered_map<char,int> freq_window;
    

    for(char c: s1){
        freq_s1[c] += 1;
    }

    for(int i = 0; i < window_size; i++){

        freq_window[s2[i]] += 1;
    }

    if(freq_window == freq_s1){
        return true;
    }

    for(int i = window_size; i < s2.length(); i++){


        freq_window[s2[i-window_size]] -= 1;
        if(freq_window[s2[i-window_size]] == 0){
            freq_window.erase(s2[i-window_size]);               // This is very important because if the index of a key is zero, it is 
                                                                // counted as one of the keys, but actually it's no longer in the window
        }

        freq_window[s2[i]] += 1;

        if(freq_window == freq_s1){

            return true;
        }
    }

    return false;
}

int main(){

    string s1 = "ab";
    string s2 = "eidbaooo";

    bool result = checkInclusion(s1,s2);

    cout << result << endl;
}
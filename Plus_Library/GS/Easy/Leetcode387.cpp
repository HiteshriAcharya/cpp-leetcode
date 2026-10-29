#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {

    unordered_map<char,int> freq;
    for(char c : s) freq[c] += 1;
    
    int idx = 0;

    /**
     * Keep it simple, do not need to think of traversing a hashmap
     * becasue a hash map does not maintain order. Just traverse string
     * again!!
     */
    
    for(char c : s){
        if(freq[c] == 1) return idx;
        idx += 1;
    }

    return -1;
}

int main(){

    string s = "loveleetcode";
    int result = firstUniqChar(s);
    cout << result << endl;
}
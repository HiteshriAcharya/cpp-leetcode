#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

/**
 * Better implementation using only one hashmap!
 * Check out leetcode.
 */

void updateQueue(string &s, queue<int> &q, vector<int> &freq){
    while(!q.empty()){
        if(freq[s[q.front()] - 'a'] > 1){
            q.pop();
        } else {
            break;
        }
    }
}

int firstUniqChar(string s){

    queue<int> q;
    vector<int> freq(26,0);

    for(int i = 0; i < s.length(); i++){
        freq[s[i]-'a'] +=1;
        q.push(i);
    }

    for(int i = 0; i < s.length(); i++){
        updateQueue(s,q,freq);
    }

    if(q.empty()) return -1;
    else return q.front();
}
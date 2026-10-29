#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {

    if(s.size() != t.size()) return false;

    unordered_map<char,int> m;

    for(char c : s){
        m[c] += 1;
    }

    for(char c : t){
        if(m.count(c) == 1){
            m[c] -= 1;
            if(m[c] == 0) m.erase(c);
        } else{
            return false;
        }
    }

    return m.size() == 0;
}

int main(){

}
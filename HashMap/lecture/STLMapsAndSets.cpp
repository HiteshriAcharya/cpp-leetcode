/**
 * Unordered_maps : All operations ave O(1) and worst case O(n), for rehashing or search
 * Maps: All operations ave O(log n), used when order matters
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){

    unordered_map<string, int> m;
    unordered_set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(10);
    s.insert(4);
    s.insert(1);

    cout << s.size() << endl;
    // s.erase(3);

    if(s.find(3) != s.end()){
        cout << "3 exists" << endl;
    } else{
        cout << "3 does not exist" << endl;
    }

    for(auto el : s){
        cout << el << " ";
    }

    cout << endl;

    // m["China"] = 150;
    // m["India"] = 150;
    // m["US"] = 150;
    // m["Nepal"] = 150;

    // for(pair<string, int> country : m){
    //     cout << country.first << "," << country.second << endl;
    // }

    // m.erase("Nepal");

    // if(m.count("Nepal") == 1){
    //     cout << "Nepal exists" << endl;
    // } else{
    //     cout << "Nepal does not exist" << endl;
    // }

}
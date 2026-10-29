#include <iostream>
#include <unordered_map>
using namespace std;

class RandomizedSet {
    unordered_map<int, int> idx;
    vector<int> list;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(idx.find(val) != idx.end()) return false;
        list.push_back(val);
        idx[val] = list.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(idx.find(val) == idx.end()) return false;
        int index = idx[val];
        list[index] = list[list.size()-1];
        //swap(list[index],list[list.size()-1]);
        idx[list[index]] = index;
        list.pop_back();
        idx.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand()%(list.size());
        return list[randomIndex];
    }
};
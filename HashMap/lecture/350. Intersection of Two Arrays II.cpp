#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
    unordered_map<int,pair<int,int>> freq;
    unordered_set<int> s;
    vector<int> results;

    for(int i = 0; i < nums1.size(); i++){
        s.insert(nums1[i]);
        freq[nums1[i]].first += 1;
    }

    for(int i = 0; i < nums2.size(); i++){
        if(s.count(nums2[i])){
            freq[nums2[i]].second += 1;
        }
    }

    for(pair<int, pair<int,int>> el : freq){
        for(int i = 0; i < min(el.second.first, el.second.second); i++){
            results.push_back(el.first);
        }
    }

    return results;
}

int main(){

}
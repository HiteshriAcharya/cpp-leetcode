#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    unordered_set<int> s;
    vector<int> results;

    for(int i = 0; i < nums1.size(); i++){
        s.insert(nums1[i]);
    }

    for(int i = 0; i < nums2.size(); i++){
        if(s.count(nums2[i])){
            results.push_back(nums2[i]);
            s.erase(nums2[i]);
        }
    }

    return results;
}

int main(){

}
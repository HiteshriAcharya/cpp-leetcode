#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * 
 */

vector<int> majorityElement(vector<int>& nums) {

    unordered_map<int, int> m;
    vector<int> results;

    for(int i = 0; i < nums.size(); i++){
        m[nums[i]] += 1;
    }

    for(pair<int,int> el : m){
        if(el.second > nums.size()/3) results.push_back(el.first);
    }

    return results;
}

int main(){

}
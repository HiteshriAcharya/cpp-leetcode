#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int,int> m;
    vector<int> results;

    for(int i = 0; i < nums.size(); i++){

        int comp = target - nums[i];
        if(m.count(comp) == 1){
            results.push_back(m[comp]);
            results.push_back(i);
            return results;
        }

        m[nums[i]] = i;
    }

    return results;
}

int main(){


}
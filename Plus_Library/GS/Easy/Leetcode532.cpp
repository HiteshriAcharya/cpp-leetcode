#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findPairs(vector<int>& nums, int k) {

    unordered_map<int,int> values;
    int count = 0;

    for(int i = 0; i < nums.size(); i++) values[nums[i]] += 1;

    for(auto it = values.begin(); it != values.end(); it ++){
        int threshold = k == 0 ? 2 : 1;
        if(values[(it->first) + k] >= threshold){
            count += 1;
        }
    }

    return count;
}

int main(){

    vector<int> nums = {-1,-2,-3};
    int k = 1;

    int result = findPairs(nums, k);
    cout << result << endl;
}
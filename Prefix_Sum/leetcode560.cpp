#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int> &nums, int k){

    int currSum = 0;
    unordered_map<int,int> map;
    int count = 0;

    //map.insert({currSum,1}); // this takes more time!! 

    map[currSum]++;

    for(int i = 0; i < nums.size(); i++){

        currSum += nums[i];
        if(map.count(currSum - k)){
           // count += 1; // cannot just +=1 because there might be multiple subarrays
           count += map[currSum-k];
            cout << "DEBUG: currSum = " << currSum << " i = " << i << endl;
        }

        map[currSum]++;
    }

    return count;
}

int main(){

    vector<int> nums = {1,1,1};
    int k = 2;

    int result = subarraySum(nums, k);

    cout << result << endl;
}
#include <iostream>
#include <vector>
using namespace std;

int waysToSplitArray(vector<int> &nums){

    vector<int> leftSum(nums.size(),0);
    vector<int> rightSum(nums.size(),0);

    leftSum[0] = nums[0];
    for(int i = 1; i < nums.size(); i++) leftSum[i] = leftSum[i-1] + nums[i];

    rightSum[nums.size()-1] = 0;
    for(int i = nums.size()-2; i >= 0; i--) rightSum[i] = rightSum[i+1] + nums[i+1];

    int count = 0;
    for(int i = 0; i < nums.size()-1; i++){
        if(leftSum[i] >= rightSum[i]) count += 1;
    }

    return count;
}

int main(){

    vector<int> arr = {10,4,-8,7};
    int result = waysToSplitArray(arr);
    cout << result << endl;
}
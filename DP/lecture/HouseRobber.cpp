#include <iostream>
#include <vector>
using namespace std;

/**
 * The idea is that at every house, I can make an independent choice of
 * either skipping or robbing the house. The base cases will be if I have 0 houses,
 * return 0, 1 house, return value of 1 house and 2 houses will retuen hou
 */

int rob_rec(int n, vector<int> & nums){

    if(n == 0) return nums[0];
    if(n == 1) return max(nums[0], nums[1]); // need to check if want to rob house 0 or house 1 because cannot rob both

    return max(rob_rec(n-1, nums), (nums[n] + rob_rec(n-2, nums)));
}

int rob_dp_memoization(int n, vector<int> & nums, vector<int> & dp){

    if(n == 0) return nums[0];
    if(n == 1) return max(nums[0], nums[1]);

    if(dp[n] != -1) return dp[n];

    dp[n] = max(rob_dp_memoization(n-1, nums, dp), (nums[n] + rob_dp_memoization(n-2, nums, dp)));
    return dp[n];
}

int rob_dp_tabulation(vector<int> & nums){

    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0]; // VERY IMPORTANT FOR TABULATION!!!

    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); i ++) dp[i] = max(dp[i-1], (nums[i] + dp[i-2]));

    return dp[nums.size()-1];
}

int main(){

    vector<int> nums = {2,7,9,3,1};
    vector<int> dp(nums.size(), -1);
    cout << rob_rec(nums.size()-1, nums) << endl;
    cout << rob_dp_memoization(nums.size()-1, nums, dp) << endl;
    cout << rob_dp_tabulation(nums) << endl;
}
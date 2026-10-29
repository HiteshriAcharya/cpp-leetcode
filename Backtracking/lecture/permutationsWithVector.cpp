#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &output, vector<int> &nums, vector<int> &ans){

    if(nums.empty()){
        output.push_back(ans);
        return;
    }

    for(int i = 0; i < nums.size(); i++){

        int picked = nums[i];
        vector<int> newNums;
        newNums.reserve(nums.size()-1);


        // remake the newNums
        for(int j = 0; j < nums.size(); j++) if(nums[j] != picked) newNums.push_back(nums[j]);

        ans.push_back(picked);
        helper(output, newNums, ans);
        ans.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> output;
    vector<int> ans;
    helper(output, nums, ans);
    return output;
}

int main(){

    vector<int> nums = {1,2,3};
    vector<vector<int>> output = permute(nums);

    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[0].size(); j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
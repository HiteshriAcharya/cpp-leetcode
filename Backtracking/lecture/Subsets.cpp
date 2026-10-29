#include <iostream>
#include <vector>
using namespace std;

/**
 * Adding the '&' infront of the curr makes A LOT OF DIFFERENCE!
 * 
 * When we use &curr, 
 * Pass by reference + modify in place → usually need backtracking
 * 
 * When we use curr,
 * Pass by value / create new objects each call → usually no need to undo
 */

void collateSubsets_pass_by_val(int i, vector<int>& nums, vector<int> curr, vector<vector<int>> &result){

    if(nums.size() == i){
        result.push_back(curr);
        return;
    }

    collateSubsets_pass_by_val(i+1, nums, curr, result);
    curr.push_back(nums[i]);
    collateSubsets_pass_by_val(i+1, nums, curr, result);
}

/**
 * WAY BETTER in terms of time complexity! Not making a copy each time!
 * 
 * The recursion tree explores all subsets, and there are 2𝑛
 * of them — and building each one costs up to 𝑂(𝑛)
 * 
 * Copying a vector of size k takes O(k)
 */

void collateSubsets_pass_by_ref(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>> &result){

    if(nums.size() == i){
        result.push_back(curr);
        return;
    }

    collateSubsets_pass_by_ref(i+1, nums, curr, result);
    curr.push_back(nums[i]);
    collateSubsets_pass_by_ref(i+1, nums, curr, result);
    curr.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> curr;
    collateSubsets_pass_by_ref(0, nums, curr, result);
    return result;
}

int main(){

    vector<int> num = {1,2,3};
    vector<vector<int>> result = subsets(num);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j];
        }
        cout << endl;
    }
}



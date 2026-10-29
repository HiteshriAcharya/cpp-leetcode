#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> &nums){

    vector<int> leftSum(nums.size(), 0);
    vector<int> rightSum(nums.size(), 0);

    for(int i = 1; i < nums.size(); i++) leftSum[i] = leftSum[i-1] + nums[i-1];
    
    for(int i = nums.size()-2; i >= 0; i--) rightSum[i] = rightSum[i+1] + nums[i+1];
    
    for(int i = 0; i < nums.size(); i++){
        if(leftSum[i] == rightSum[i]) return i;
    }

    return -1;
}

int main(){

    vector<int> arr = {1,7,3,6,5,6};
    int result = pivotIndex(arr);
    cout << result << endl;

}
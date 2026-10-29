#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {

    int farthest = 0;

    for(int i = 0; i < nums.size(); i++){
        if(farthest < i) return false;
        farthest = max(farthest, i + nums[i]);
    }

    return true;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums) << endl;
}
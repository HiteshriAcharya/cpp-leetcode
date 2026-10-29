#include <iostream>
#include <vector>
using namespace std;

/**
 *  Use 2 ptr algorithm. ptr stays at the "upcoming" idx of the next 
 * non-zero number. Then just swap()
 */

void moveZeroes(vector<int>& nums) {

    int ptr = 0;

    for(int i = 0; i < nums.size(); i++){

        if(nums[i] != 0) swap(nums[i], nums[ptr++]);
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);

    for(int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;
}
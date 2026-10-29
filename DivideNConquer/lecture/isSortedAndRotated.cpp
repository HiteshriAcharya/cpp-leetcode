#include <iostream>
#include <vector>
using namespace std;

bool isRotatedAndSorted(vector<int> &nums){

    int drops = 0;
    int size = nums.size();

    for(int i = 0; i < size; i++){

        if(nums[i] > nums[(i+1) % size]){

            drops += 1;
        }

        if(drops > 1){

            return false;
        }

    }

    return true;
}

int main(){

    vector<int> nums = {100,99,1,};
    bool result = isRotatedAndSorted(nums);

    cout << result << endl;

}
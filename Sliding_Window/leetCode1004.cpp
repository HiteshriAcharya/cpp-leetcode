#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int> &nums, int k){

    int left = 0;
    int max_substring_len = 0;
    int onesAndZeros[2] = {0};
    

    for(int right = 0; right < nums.size(); right++){

        onesAndZeros[nums[right]] += 1;  // taking time; replace with zero count

        while(onesAndZeros[0] > k){

            onesAndZeros[nums[left]] -= 1;
            left +=1;
        }

        max_substring_len = max(max_substring_len, right-left+1);
    }

    return max_substring_len;
}

int main(){

    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    int result = longestOnes(nums,k);
    cout << result << endl;
}
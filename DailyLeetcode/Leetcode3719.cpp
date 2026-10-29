#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * This is too complex thinking!! NO! Just have 2 seperate hash sets and calculate the size
 */

// bool isBalanced(unordered_set<int> &values){

//     int evenCount = 0;
//     int oddCount = 0;

//     for(auto it = values.begin(); it != values.end(); it++){
//         int val = *it;
//         if(val%2==0) evenCount += 1;
//         else oddCount += 1;
//     }

//     if(evenCount == oddCount) return true;
//     else return false;
// }

int longestBalanced(vector<int>& nums) {

    unordered_set<int> even;
    unordered_set<int> odd;

    int longestSubstring = 0;
    int currSubstring = 0;

    for(int i = 0; i < nums.size(); i++){
        
        even.clear();
        odd.clear();

        if(nums[i]%2 == 0) even.insert(nums[i]);
        else odd.insert(nums[i]);
        
        for(int j = i+1; j < nums.size(); j++){

            if(nums[j]%2 == 0) even.insert(nums[j]);
            else odd.insert(nums[j]);

            if(even.size() == odd.size()) currSubstring = j-i+1;
            longestSubstring = max(longestSubstring, currSubstring);
        }
    }

    return longestSubstring;
}

int main(){

    vector<int> nums = {1,2,3,2};
    int result = longestBalanced(nums);
    cout << result << endl;
}


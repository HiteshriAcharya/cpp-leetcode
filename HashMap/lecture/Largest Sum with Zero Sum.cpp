#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * sum[i,j] = sum[j] - sum[i]
 * sum[j] - sum[i-1] = 0
 * sum[j] = sum[i-1]
 */

int largestSubWith0Sum(vector<int> arr){

    unordered_map<int, int> preSum; // key: sum, value: idx
    int sum = 0;
    int maxLength = 0;

    for(int i = 0; i < arr.size(); i++){

        sum += arr[i];

        if(preSum.count(sum)){
            int currLen = i - preSum[sum];
            maxLength = max(maxLength, currLen);
        } else{
            preSum[sum] = i;
        }
    }

    return maxLength;
}

int main(){

    vector<int> arr = {15, -2, 3, -8, 1, 7, 10};
    cout << "Largest subarray with sum 0: " << largestSubWith0Sum(arr) << endl;
}
#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{

    int left = 0;

    int curr_sum = 0;
    int min_window_length = INT32_MAX;

    for (int right = 0; right < nums.size(); right++)
    {

        curr_sum += nums[right];

        while (curr_sum >= target)
        {
            min_window_length = min(min_window_length, right - left + 1);
            curr_sum -= nums[left];
            left += 1;
        }
    }

    return (min_window_length == INT32_MAX) ? 0 : min_window_length;
}

int main(){

    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    int result = minSubArrayLen(target, nums);

    cout << result << endl;
}
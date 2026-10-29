#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * 
 * Instead of using a max heap to store all n elements and popping until the
 * kth largest is found, which takes another k log n time, we can use a min heap
 * approach! 
 * 
 * Bascially the final min heap of k elements that will remain, at the very top, 
 * would be the kth largest of the entire vector. In that min heap, it would be the smallest.
 * 
 * This would take O(n log k)
 */

int findKthLargest(vector<int>& nums, int k) {

    // priority_queue<int> pq(nums.begin(), nums.end());

    // for(int i = 0; i < k-1; i++) pq.pop();

    // return pq.top();

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0; i < nums.size(); i++){
        minHeap.push(nums[i]);
        if(minHeap.size() > k) minHeap.pop();
    }

    return minHeap.top();
}

int main(){

    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    cout << findKthLargest(nums,k) << endl;
}
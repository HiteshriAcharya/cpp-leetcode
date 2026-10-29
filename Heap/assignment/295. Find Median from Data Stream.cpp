#include <iostream>
#include <queue>
using namespace std;

/**
 * Border of lower half = largest element = maxHeap.top()
 * Border of upper half = smallest element = minHeap.top()
 * 
 * Max heap lets you remove the largest of the lower half in O(log n)
 * Min heap lets you remove the smallest of the upper half in O(log n)
 * 
 * That's why if the maxHeap is too large, we take the largest value
 * and shift it to the minHeap so the curr smallest value of all the larger values
 * will not get affected
 * 
 * And when the minHeap is too large, we take the smallest value and shift it to the max
 * Heap so the curr max of the maxHeap would not get affected.
 */

class MedianFinder {

private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(maxHeap.empty() || maxHeap.top() >= num) maxHeap.push(num);
        else minHeap.push(num);

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        
        if(maxHeap.size() == minHeap.size()){
            return ((double) maxHeap.top() + (double) minHeap.top()) / 2;
        } else if(maxHeap.size() > minHeap.size()){
            return (double) maxHeap.top();
        } else{
            return (double) minHeap.top();
        }
    }
};
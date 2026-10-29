#include <iostream>
#include <queue>
using namespace std;

/**
 * n/2 to n nodes are last level nodes. We do not run heapify for these indexes
 * because these nodes, strating with n/2, has no left or right children. 
 */

void heapify(vector<int>&arr, int parIdx, int n){

    int left = parIdx*2 + 1;
    int right = parIdx*2 + 2;
    int maxIdx = parIdx;

    if(left < n && arr[left] < arr[maxIdx]) maxIdx = left;
    if(right < n && arr[right] < arr[maxIdx]) maxIdx = right;

    if(maxIdx != parIdx){
        swap(arr[parIdx], arr[maxIdx]);
        heapify(arr, maxIdx, n);
    }
}

void heapSort(vector<int>& arr){

    int n = arr.size();

    // O(n * logn)

    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, i, n);
    }

    // O(n * logn)

    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main(){
    
    vector<int> arr = {1,4,2,5,3};
    heapSort(arr);

    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
}
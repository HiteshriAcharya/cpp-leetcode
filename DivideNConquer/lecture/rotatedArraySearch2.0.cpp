#include <iostream>
#include <vector>
using namespace std;

/**
 * Duplicates are allowed in this array.
 * 
 * This algorithm only has knowledge of 3 things; the start, mid and end idx.
 * 
 * The algorithm used for unqiue elements is that the start element would ALWAYS be smaller
 * then the mid if the mid lies on the left line because of the increasing trend.
 * 
 * However, if start == mid == end, nothing is learnt. If the boundaries are all equal, you can't 
 * tell which side is sorted so shrink the range.
 */

int rotatedBinarySearch(vector<int> arr, int start, int end, int target){

    // This is if we don't find the target. It will only reach this point in that case
    if(start > end){
        return -1;
    }

    int mid = start + ((end - start)/2);

    cout << "Start: " << start << " End: " << end << " Mid: " << mid << endl;

    if(arr[mid] == target){

        cout << "arr[mid]: " << arr[mid] << " mid: " << mid << endl;
        return mid;
    }

    /////////////////// KEY STUFF !!! ///////////////////
    
    if(arr[start] == arr[mid] && arr[mid] == arr[end]){
        return rotatedBinarySearch(arr, start+1, end-1, target);
    }
    
    if(arr[mid] > arr[start]){ // Mid lies on the left line 

        if(arr[start] <= target && arr[mid] > target){
            return rotatedBinarySearch(arr, start, mid-1, target); 
        } else{
            return rotatedBinarySearch(arr, mid + 1, end, target);
        }
    } else{ // Mid lies on the right line

        if(arr[mid] <= target && arr[end] >= target){
            return rotatedBinarySearch(arr, mid + 1, end, target);
        } else{
            return rotatedBinarySearch(arr, start, mid - 1, target);
        }
    }
}

int main(){

    vector<int> arr = {1,0,1,1,1};
    int target = 0;

    int idx = rotatedBinarySearch(arr, 0, arr.size()-1, target);

    cout << idx << endl;
}
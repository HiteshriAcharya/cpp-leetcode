#include <iostream>
#include <vector>
using namespace std;

/**
 * Need to add the "return" after each function call. 
 * 
 * Firstly, this is a recursive call, 
 * when you "return", it will exit that function call but not the entire function itself.
 * If you had a while loop or something, just the return at arr[mid]==target would have worked
 * just like a normal binary search function.
 * 
 * Secondly, when you just call the function recursively without returning, you are going deeper until
 * you hit the base case of arr[mid] == target but we are not storing the value anywhere. So the code 
 * will proceed until the last line of the function and end there.
 * 
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
    
    if(arr[mid] >= arr[start]){ // Mid lies on the left line 

        if(arr[start] <= target && arr[mid] >= target){
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

    vector<int> arr = {4,5,6,6,7,0,1,2,4,4};
    int target = 4;

    int idx = rotatedBinarySearch(arr, 0, arr.size()-1, target);

    cout << idx << endl;
}
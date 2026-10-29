#include <iostream>
#include <vector>
using namespace std;

/**
 * 
 * When we want to find the minimum in a rotated array, we want to
 * find the start point of the "second" line. 
 * 
 * The information we have is the start point of the "first" line, 
 * the mid which could be lying anywhere and the 
 * end point which is the end point of the "second" line.
 * 
 * To get to the start point of the "second" line, we have 
 * to use the fact of where the mid is lying. If the mid lies on 
 * the left, we will shift the start to mid+1 hoping that would be 
 * the start of the "second" line. 
 * 
 * If the mid already lies on the 
 * right, we shift the end to be mid (not mid+1) to narrow the search
 * of the start of the "second" line because we know it lies between the 
 * start of the arr to the mid 
 * 
 * Using the arr[end] is more informative than the arr[start]. This is
 * because arr[end] is guaranteed to lie on the "second" line but arr[start]
 * could lie on the "first" or "second" line. We don't know it for sure.
 */

int minInRotatedArrayUsingEnd(vector<int> arr){

    int start = 0;
    int end = arr.size()-1;

    while(start < end){

        int mid = start + ((end-start)/2);

        // the mid lies on the left so check the right
        if(arr[mid] > arr[end]){
            start = mid + 1;
        } else{ // the mid lies on the right 
            end = mid;
        }
    }

    return arr[start];
}

int minInRotatedArrayUsingStart(vector<int> arr){

    int start = 0;
    int end = arr.size() - 1;
    
    while(start < end){

        int mid = start + ((end-start)/2);

        if(arr[start] <= arr[mid] && arr[mid] <= arr[end]){
            cout << "DEBUG: returning this result" << endl;
            return arr[start];
        }

        //mid lies on the left line so search on the right
        if(arr[start] <= arr[mid]){
            cout << "DEBUG: start changed from " << start;
            start = mid + 1;
            cout << " to " << start << endl;
        } else{ // mid lies on the right 
            cout << "DEBUG: end changed from " << end;
            end = mid;
            cout << " to " << end << endl;
        }
    }

    return arr[start];
}

int main(){

    vector<int> arr = {3,1,2};

    int min = minInRotatedArrayUsingStart(arr);
    int min2 = minInRotatedArrayUsingEnd(arr);

    cout << min << endl;
    cout << min2 << endl;
}
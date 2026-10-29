#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end){

    vector<int> temp;    // temp vector to push the numbers in order
    int i = start;       // just a ptr to keep track of the left arr
    int j = mid+1;       // just a ptr to keep track of the right arr


    /**
     * This loop is for when both ptr are still valid
     * so I can traverse both at the same time and sort it
     */

    while(i <= mid && j <= end){

        if(arr[i] <= arr[j]){

            temp.push_back(arr[i++]);
        } else {

            temp.push_back(arr[j++]);
        }
    }

    /**
     * This is when the right arr predominantly was smaller
     * and everything got sorted but the left arr elements 
     * have not been sorted yet so just add the remaining in the 
     * temp vector
     */

    while(i <= mid){

        temp.push_back(arr[i++]);
    }

    /**
     * This is when the left arr predominantly was smaller
     * and everything got sorted but the right arr elements
     * have not been sorted yet so just add the remaining in the
     * temp vector
     */

    while(j <= end){

        temp.push_back(arr[j++]);
    }

    /**
     * Transfer the elements from the temp arr 
     * to the main arr
     */

    for(int idx=start, x=0; idx <= end; idx++){
        arr[idx] = temp[x++];
    }
}

void mergeSort(vector<int>& arr, int start, int end){

    if(start >= end){

        return;
    }

    int mid = start + ((end - start)/2);

    cout << "mergeSort left: " << start << " " << mid << endl;
    mergeSort(arr, start, mid);
    cout << "mergeSort right: " << mid + 1 << " " << end << endl;
    mergeSort(arr, mid+1, end);
    cout << start << " " << mid << " " << end << endl;
    merge(arr, start, mid, end);
     
}

void printArr(vector<int> arr){

    for(int i = 0; i < arr.size(); i++){

        cout << arr.at(i) << " ";
    }

    cout << endl;
}

int main(){

    vector<int> arr = {6,3,7,4,2,1};
    int size = arr.size();
    mergeSort(arr, 0, size-1);
    printArr(arr);
}
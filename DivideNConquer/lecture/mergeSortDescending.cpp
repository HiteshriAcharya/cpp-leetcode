#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){

    int i = start;
    int j = mid + 1;
    vector<int> temp;

    while(i <= mid && j <= end){
        
        if(arr[i] >= arr [j]){
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid){
        temp.push_back(arr[i++]);
    }

    while(j <= end){
        temp.push_back(arr[j++]);
    }

    for(int a = start, x = 0; a <= end; a++){

        arr[a] = temp[x++];

    }
}


void mergeSort(vector<int> &arr, int start, int end){

    if(start >= end){

        return;
    }

    int mid = start + ((end-start)/2);

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}

void printArr(vector<int> arr){

    for(int i = 0; i < arr.size(); i++){

        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){

    vector<int> input = {6, 3, 7, 4, 2, 1};
    int size = input.size();

    mergeSort(input, 0, size-1);

    printArr(input);

}
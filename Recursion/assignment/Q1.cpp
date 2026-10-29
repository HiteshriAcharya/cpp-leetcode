#include <iostream>
#include <vector>
using namespace std;

int recursiveBinarySearch(int start, int end, int key, vector<int>& arr){

    if(start > end){
        return -1;
    }

    int mid = (start+end)/2;

    if(arr[mid] < key){
        recursiveBinarySearch(mid+1, end, key, arr);
    } else if(arr[mid] > key){
        recursiveBinarySearch(start, mid-1, key, arr);
    } else{
        return mid;
    }
}

int main(){

    vector <int> arr = {1,2,3,4,5,6,7};
    int key = 5;
    int result = recursiveBinarySearch(0, arr.size()-1, key, arr);
    cout << result << endl;
}
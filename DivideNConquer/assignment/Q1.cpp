#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(vector<string> &dict, int start, int end, int mid){

    int leftPtr = start;
    int rightPtr = mid+1;

    vector<string> temp;

    while(leftPtr <= mid && rightPtr <= end){

        if(dict[leftPtr] <= dict[rightPtr]){
            temp.push_back(dict[leftPtr]);
            leftPtr += 1;
        } else{
            temp.push_back(dict[rightPtr]);
            rightPtr += 1;
        }
    }

    while(leftPtr <= mid){
        temp.push_back(dict[leftPtr]);
        leftPtr += 1;
    }

    while(rightPtr <= end){
        temp.push_back(dict[rightPtr]);
        rightPtr += 1;
    }

    for(int k = start, x = 0; k <= end; k++){
        dict[k] = temp[x++];
    }
}

void mergeSort(vector<string> &dict, int start, int end){

    if(start >= end){
        return;
    }

    int mid = start + ((end-start)/2);

    mergeSort(dict, start, mid);
    mergeSort(dict, mid+1, end);
    merge(dict, start, end, mid);
}

void printArr(vector<string> &dict){

    for(int i = 0; i < dict.size(); i++){

        cout << dict[i] << " ";
    }

    cout << endl;
}

int main(){

    vector<string> dict = {"sun", "earth", "mars", "mercury"};
    mergeSort(dict, 0, dict.size()-1);
    printArr(dict);
}
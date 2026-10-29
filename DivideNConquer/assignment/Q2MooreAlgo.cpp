#include <iostream>
#include <vector>
using namespace std;

/**
 * Using Moore's Majority Algorithm
 */

bool checkMajority(vector<int> &arr, int candidate){

    int count = 0;

    for(int i = 0; i < arr.size(); i++){

        if(arr[i] == arr[candidate]){
            count += 1;
        }
    }

    if(count >= arr.size()/2){
        return true;
    } else{
        return false;
    }
}

int MooreMajority(vector<int> &arr){

    int candidateIdx = 0;
    int count = 1;

    for(int i = 0; i < arr.size(); i++){

        if(arr[i] == arr[candidateIdx]){
            count += 1;
        } else {

            count -= 1;
        }

        if(count == 0){

            candidateIdx = i;
            count = 1;
        }
    }

    if(checkMajority(arr, candidateIdx)){
        return candidateIdx;
    } else{
        return -1;
    }
}

int main(){

    vector<int> arr = {3,2,3};
    int majority = arr[MooreMajority(arr)];

    cout << majority << endl;
}
#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> &arr){

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

void changeArr(vector<int> &arr, int i){

    if(i == arr.size()){
        printArr(arr);
        return;
    }

    arr[i] = (i+1);
    changeArr(arr, i+1);
    arr[i] -= 2;
}


int main(){

    vector<int> arr(5,0);
    changeArr(arr, 0);
    printArr(arr);
}
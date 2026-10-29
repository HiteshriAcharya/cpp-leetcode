#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end){

    int pivotIdx = end;
    int i = start - 1;
    
    for(int j = start; j < end; j++){

        if(arr[j] < arr[pivotIdx]){

            i+=1;
            swap(arr[i], arr[j]);
        }
    }

    i+=1;
    swap(arr[i], arr[pivotIdx]);
    pivotIdx = i;

    return pivotIdx;
}

void QS(vector<int> &arr, int start, int end){

    if(start >= end){

        return;
    }

    int pivotIdx = partition(arr, start, end);

    QS(arr, start, pivotIdx-1);
    QS(arr, pivotIdx+1, end);
}

void printArr(vector<int> arr)
{

    for (int i = 0; i < arr.size(); i++)
    {

        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){

    vector<int> arr = {3,2,1,7,10,9};
    QS(arr, 0, arr.size()-1);
    
    printArr(arr);

}
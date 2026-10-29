#include <iostream>
using namespace std;

void subarrayMax(int N, int *arr){

    int maxSum = INT32_MIN;
    int startIdx = 0;
    int endIdx = 0;
    int tempSum = 0;

    for(int i = 0; i < N; i++){

        tempSum += arr[i];
        if(maxSum < tempSum){
            maxSum = tempSum;
            endIdx = i;
        }
        if(tempSum < 0){

            tempSum = 0;
            startIdx = i + 1;
        }

    }

    cout << "Max subarray is from index " << startIdx << " to " << endIdx << " and the sum is " << maxSum;
}

int main(){

    int N;

    cout << "Enter N: ";
    cin >> N;

    int array[N];

    for (int i = 0; i < N; i++)
    {

        cout << "Enter element: ";
        cin >> array[i];
    }

    subarrayMax(N, array);
}
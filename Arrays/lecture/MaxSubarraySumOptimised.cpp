#include <iostream>
using namespace std;


void subarrayMax(int N, int *arr){

    int maxSum = INT32_MIN;
    int startIdx = 0;
    int endIdx = 0;
    int tempSum = 0;

    for(int i = 0; i < N; i++){

        tempSum = 0;

        for(int j = i; j < N; j++){

            tempSum += arr[j];

            if(maxSum < tempSum){
                maxSum = tempSum;
                startIdx = i;
                endIdx = j;
            }
        }
    }

    cout << "Max subarray is from index " << startIdx << " to " << endIdx << " and the sum is " << maxSum;

}

int main(){

    int N;

    cout << "Enter N: ";
    cin >> N;

    int array[N];

    for(int i = 0; i < N; i++){

        cout << "Enter element: ";
        cin >> array[i];
    }

    subarrayMax(N, array);


}
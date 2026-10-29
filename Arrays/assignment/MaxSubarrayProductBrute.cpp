#include <iostream>
using namespace std;

int maxProductBrute(int N, int *arr){

    int startIdx = 0;
    int endIdx = 0;

    int  maxProduct = INT32_MIN;
    int tempMax = 1;

    for(int i = 0; i < N; i++){

        tempMax = 1;

        for(int j = i; j < N; j++){

            tempMax *= arr[j];

            if(tempMax > maxProduct){

                maxProduct = tempMax;
                endIdx = j;
                startIdx = i;
            }
        }
    }

    cout << "Max subarray is from index " << startIdx << " to " << endIdx << " and the sum is " << maxProduct << endl;

    return maxProduct;
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

    int max = maxProductBrute(N, array);

    cout << "Maximum subarray product: " << max << endl;
}
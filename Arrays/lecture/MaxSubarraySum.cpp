#include <iostream>
using namespace std;

// Brute force method - when printing out the subarrays of each, also calculate the sum 

void maxSubarraySum(int *array, int size){

    int maxSum = INT64_MIN;
    int temp_sum = 0;
    int start_idx = 0;
    int end_idx = 0;

    for(int arr_idx = 0; arr_idx < size; arr_idx++){

        for(int i = arr_idx; i < size; i++ ){

            temp_sum = 0;

            for(int j = arr_idx; j <= i; j ++){

                temp_sum += array[j];

                if(temp_sum > maxSum){

                    start_idx = arr_idx;
                    end_idx = i;
                    maxSum = temp_sum;

                }

            }
        }
    }

    cout << "Maximum Subarray Sum is: " << maxSum << endl;
    cout << "Start index is: " << start_idx << " and end index is: " << end_idx;  

}

int main(){

    int size;
    
    cout << "Input size of array: ";
    cin >> size;

    int array[size];

    for(int i = 0; i < size; i++){

        cout << "Add an element to the array: ";
        cin >> array[i];
    }

    maxSubarraySum(array, size);

}
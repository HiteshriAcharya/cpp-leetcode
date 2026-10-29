#include <iostream>
using namespace std;

// 7 8 9 1 2 3 4 5 6

int rotatedArray(int N, int *arr, int target){

    int low_idx = 0;
    int high_idx = N-1;

    while(low_idx <= high_idx){

        int mid_idx = (low_idx + high_idx)/2;

        // did we find the answer?
        if(arr[mid_idx] == target){

            return mid_idx;
        }

        // is the first half sorted?
        else if(arr[low_idx] <= arr[mid_idx]){

            if (target < arr[mid_idx] && target >= arr[low_idx]){

                high_idx = mid_idx - 1;

            } else {

                low_idx = mid_idx + 1;
            }

        }

        // the second half is sorted 
        else{

            if(target > arr[mid_idx] && target <= arr[high_idx]){

                low_idx = mid_idx + 1;

            } else if (target < arr[mid_idx]){

                high_idx = mid_idx - 1;

            } else if(target > arr[mid_idx] && target >= arr[high_idx]){

                high_idx = mid_idx - 1;
            }

        }

    }

    return -1;
}

int main(){

    int N, target;

    cout << "Enter N: ";
    cin >> N;

    int array[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Enter element: ";
        cin >> array[i];
    }

    cout << "Enter target: ";
    cin >> target;

    int idx = rotatedArray(N, array, target);

    cout << "idx: " << idx << endl;
}
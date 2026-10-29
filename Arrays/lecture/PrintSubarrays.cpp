#include <iostream>
using namespace std;

// Time complexity is O(n^3) but with the help of strings, can bring the time complexity to O(n^2)

void printSubarrays(int *arr, int sizeArr){

    for(int i = 0; i < sizeArr; i++){

        for(int j = i; j < sizeArr; j++){

            for(int k = i; k <= j; k++){

                cout << arr[k];
            }

            cout << endl;

        }
    }

}

int main(){

    int sizeArr;

    cout << "Enter the size of your array: ";
    cin >> sizeArr;

    int arr[sizeArr];

    for (int i = 0; i < sizeArr; i++)
    {

        cout << "Enter value at index " << i << ": ";
        cin >> arr[i];
    }

    printSubarrays(arr, sizeArr);

}
#include <iostream>
using namespace std;

int minArray(int N, int *arr){

    int min_idx = 0;

    for(int i = 0; i < N; i++){

        cout << "DEBUG: arr[i]: " << arr[i] << endl;

        if(arr[i] < arr[min_idx]){

            min_idx = i;
        }
    }

    cout << "DEBUG: min_idx: " << min_idx << endl;
    return min_idx;
}

void selectionSort(int N, int *arr){

    int min_idx = 0;

    for(int i = 0; i < N-1; i++){

        min_idx = minArray(N - i, &arr[i]);
        cout << "DEBUG: arr[i]: " << arr[i] << " is going to be swapped with arr[min_idx]: " << arr[min_idx] << endl;
        swap(arr[i], arr[min_idx + i]);
    }

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

    selectionSort(N, array);

    for (int i = 0; i < N; i++)
    {
        cout << " " << array[i];
    }

    cout << endl;
}
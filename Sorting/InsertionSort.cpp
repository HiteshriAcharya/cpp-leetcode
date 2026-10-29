#include <iostream>
using namespace std;

void insertionSort(int N, int *arr){

    for(int i = 1; i < N; i++){

        int tempPos = i;

        for(int j = i-1; j >= 0; j--){

            if(arr[tempPos] < arr[j]){

                swap(arr[tempPos], arr[j]);
                tempPos = j;
            }
        }
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

    insertionSort(N, array);

    for (int i = 0; i < N; i++)
    {
        cout << " " << array[i];
    }

    cout << endl;
}
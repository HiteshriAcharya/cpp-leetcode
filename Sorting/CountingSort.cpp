#include <iostream>
using namespace std;

void countingSort(int N, int *arr){

    int freq[100000] = {0};

    int minVal = INT32_MAX;
    int maxVal = INT32_MIN;

    for(int i = 0; i < N; i++){

        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    for (int i = 0; i < N; i++){

        freq[arr[i]] += 1;
    }

    for(int i = minVal, j=0; i <= maxVal; i++){

        while(freq[i] != 0){

            arr[j++] = i;
            freq[i]--;
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

    countingSort(N, array);

    for (int i = 0; i < N; i++)
    {
        cout << " " << array[i];
    }

    cout << endl;
}
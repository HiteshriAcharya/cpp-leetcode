#include <iostream>
using namespace std;

//brute force method of time complexity O(n^2) => needs to be better than this

bool isDuplicate(int N, int *arr){

    int traversedArr[N];
    int numElementsTraversed = 0;

    for(int i = 0; i < N; i++){

        for(int j = 0; j < numElementsTraversed; j++){

            if(arr[i] == traversedArr[j]){

                return true;

            } 
        }

        numElementsTraversed += 1;
        traversedArr[i] = arr[i];
    }

    return false;

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

    bool duplicate = isDuplicate(N, array);

    cout << duplicate << endl;
}
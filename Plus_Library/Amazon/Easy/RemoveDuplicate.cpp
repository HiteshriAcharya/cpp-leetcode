#include <iostream>
using namespace std;

int removeDuplicate(int N, int *arr){

    int k = 0;

    for(int i = 0; i < N-1; i++){

        if(arr[i] == arr[i+1]){

             
            k +=1;
        }
    }

}

int main() {

    int N;

    cout << "Enter N: ";
    cin >> N;

    int array[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Enter element: ";
        cin >> array[i];
    }

    int k = removeDuplicate(N, array);
}
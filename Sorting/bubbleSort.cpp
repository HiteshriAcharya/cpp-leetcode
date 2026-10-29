#include <iostream>
using namespace std;

/** There is a little optimization when there is no need to swap (already sorted array)
 * By adding a bool isSwap, I will figure out if there was any swap in one entire inner
 * loop. If there wasn't, it means the array is already sorted and e can exit the code.
 */

void bubbleSort(int N, int *ptr){

    for(int i = 0; i < N-1; i++){

        bool isSwap = false; // need to reset

        for(int j = 0; j < N-i-1; j++){

            if(ptr[j] > ptr[j+1]){
                cout << "SWAP" << endl;
                swap(ptr[j], ptr[j+1]);
                isSwap = true;
            }
        }

        if (!isSwap)
        {
            cout << "RETURN" << endl;
            return;
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

    bubbleSort(N, array);

    cout << "Swapped array: ";

    for (int i = 0; i < N; i++)
    {
        cout << " " << array[i];
    }

    cout << endl;
}
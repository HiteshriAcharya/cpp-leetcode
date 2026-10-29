#include <iostream>
using namespace std;

void reverseArray(int *arr, int size){

    int *ptr = arr;
    int *ptr2 = arr + size -1;

    int temp = 0;

    while(ptr <= ptr2){                  //cannot keep the condition as ptr != ptr2 because in even sizes, ptrs will cross over => infinite loop

        // temp = *ptr;
        // *ptr = *ptr2;
        // *ptr2 = temp;

        swap(*ptr, *ptr2);              //in-built function in C++
        ptr +=1;
        ptr2-=1;

    }

}

int main(){

    int sizeArr;

    cout << "Enter the size of your array: ";
    cin >> sizeArr;

    int arr[sizeArr];

    for(int i = 0; i < sizeArr; i++){

        cout << "Enter value at index " << i << ": ";
        cin >> arr[i];
    }

    reverseArray(arr, sizeArr);

    for(int j = 0; j < sizeArr; j++){

        cout << arr[j] << " ";
    }

}

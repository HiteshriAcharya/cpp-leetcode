#include <iostream>
using namespace std;

void printArray(int arr[], int n){

   //cout << sizeof(arr) << endl; 

    cout << arr[0] << endl;
    cout << arr << endl;
    cout << *arr << endl;

    cout << arr[1] << endl;

    for(int i = 0; i <= 4; i++){

        cout << arr[i] ;
    }
}

int main(){

    int array[5] = {1,2,3,4,5};
    printArray(array, 5);
}
#include <iostream>
using namespace std;

int binarySearch(int *arr, int size, int key) {

    int start = 0;
    int end = size - 1;

    int mid = 0;

    while(start <= end){

        mid = (start+end)/2;

        if(key == arr[mid]){

            return mid;

        }else if(key < arr[mid]){

            end = mid - 1;

        }else{

            start = mid + 1;

        }
    }

    return -1;
}


int main()
{

    int sizeArr;

    cout << "Enter the size of your array: ";
    cin >> sizeArr;

    int arr[sizeArr];

    for (int i = 0; i < sizeArr; i++)
    {

        cout << "Enter value at index " << i << ": ";
        cin >> arr[i];
    }

    int key, index;

    cout << "Enter the number you are searching for: ";
    cin >> key;

    index = binarySearch(arr, sizeArr, key);

    cout << "Index of the value you are searching for is " << index << endl;
    
}

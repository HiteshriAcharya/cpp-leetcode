#include <iostream>
using namespace std;

bool isArraySorted(int *ptr, int size, int i){

    if(i == size-1){

        return true;
    }

    if(ptr[i] > ptr[i+1]){

        return false;
    }

    isArraySorted(ptr, size, i+1);
}

int main(){

    int ptr[5] = {0,0,0};
    int ptr2[5] = {1,2,4,3,5};

    bool result = isArraySorted(ptr, 5, 0);
    bool result2 = isArraySorted(ptr2, 5, 0);
    
    cout << result << endl;
    cout << result2 << endl;

}
#include <iostream>
#include <vector>
using namespace std;

void printIndexOfDups(vector<int> arr, int idx, int key){

    if(idx == arr.size()){      // do not exit at arr.size()-1 because you will
                                // skip the last element without checking
        cout << endl;
        return;
    }

    if(arr[idx] == key){
        cout << idx << " ";
    }

    printIndexOfDups(arr, idx+1, key);
}

int main(){

    vector<int> arr = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int key = 2;

    printIndexOfDups(arr, 0, key);

}
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * For each element in the array, find the FIRST element to its RIGHT that is strictly greater.
 */

void nextGreaterElement(vector<int>& arr, vector<int>& ans){

    int size = arr.size();
    stack<int> nextHigh;
    nextHigh.push(arr[size-1]);  
    ans[size-1] = -1;  // this is def -1 because there is no more number on the right for the last element

    // Traversing from the back to the front obviously
    for(int i = size-1; i >= 0; i--){

        // pop until you find an element which is higher
        while(!nextHigh.empty() && arr[i] >= nextHigh.top()){
            nextHigh.pop();
        }

        if(nextHigh.empty()){
            ans[i] = -1;
        } else{
            ans[i] = nextHigh.top();
        }

        nextHigh.push(arr[i]);
    }

}

int main(){

    vector<int> arr = {6,8,0,1,3};
    vector<int> ans (5,0);

    nextGreaterElement(arr, ans);

    for(int i = 0; i < ans.size(); i++){

        cout << ans[i] << " ";
    }

    cout << endl;
}
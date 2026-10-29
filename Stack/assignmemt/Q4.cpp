#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printArr(vector<int> arr){

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void firstMaxFromRight(vector<int> &right, vector<int> height, int size){

    stack<int> maxRight;
    right[size-1] = 0;
    maxRight.push(height[size-1]);

    for(int i = size-2; i >= 0; i--){

        while(!maxRight.empty() && height[i] > maxRight.top()) maxRight.pop();

        if(maxRight.empty()){
            right[i] = 0; //No element greater on the right greater
            maxRight.push(height[i]);
        } else{ 
            right[i] = maxRight.top();
        }
    }
}

void firstMaxFromLeft(vector<int> &left, vector<int> height, int size){
    stack<int> maxLeft;
    left[0] = 0;
    maxLeft.push(height[0]);

    for(int i = 1; i < size; i++){

        while(!maxLeft.empty() && height[i] > maxLeft.top()) maxLeft.pop();

        if(maxLeft.empty()){
            left[i] = 0; //No element greater on the left greater
            maxLeft.push(height[i]);
        } else{ 
            left[i] = maxLeft.top();
        }
    }
}

int trap(vector<int>& height) {

    int size = height.size();
    vector<int> right(size,0);
    vector<int> left(size,0);
    vector<int> newHeight(size,0);
    int area = 0;
    
    firstMaxFromRight(right, height, size);
    printArr(right);
    firstMaxFromLeft(left, height, size);
    printArr(left);

    for(int i = 0; i < size; i++){
        newHeight[i] = min(right[i], left[i]);
        if(newHeight[i] != 0) area +=  newHeight[i]-height[i];
    }

    printArr(newHeight);

    return area;
}

int main(){

    vector<int> height = {4,2,0,3,2,5};
    int result = trap(height);
    cout << result << endl;
}
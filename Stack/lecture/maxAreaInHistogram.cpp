#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nextSmallerLeft(vector<int>& left, vector<int>& histogram){

    stack<int> smallerLeft;
    smallerLeft.push(0); //no elements smaller on the left for the first element
    left[0] = -1;

    for(int i = 1; i < histogram.size(); i++){

        while(!smallerLeft.empty() && histogram[i] <= histogram[smallerLeft.top()]){
            smallerLeft.pop();
        }

        // there is no small element on the left
        if(smallerLeft.empty()){
            left[i] = -1;
        } else{
            left[i] = smallerLeft.top();
        }

        smallerLeft.push(i);
    }
}

void nextSmallerRight(vector<int>& right, vector<int>& histogram){

    stack<int> smallerRight;
    smallerRight.push(histogram.size()-1); //no elements smaller on the right for the last element
    right[histogram.size()-1] = histogram.size();

    for(int i = histogram.size()-2; i >= 0; i--){

        while(!smallerRight.empty() && histogram[i] <= histogram[smallerRight.top()]){
            smallerRight.pop();
        }

        // there is no small element on the right
        if(smallerRight.empty()){
            right[i] = histogram.size();
        }else {
            right[i] = smallerRight.top();
        }

        smallerRight.push(i);
    }

}

int largestRectangleArea(vector<int>& heights) {

    vector<int> leftSmaller(heights.size(), 0);
    vector<int> rightSmaller(heights.size(), 0);

    nextSmallerLeft(leftSmaller, heights);
    nextSmallerRight(rightSmaller, heights);

    for(int i = 0; i < heights.size(); i++){
        cout << leftSmaller[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < heights.size(); i++){
        cout << rightSmaller[i] << " ";
    }

    cout << endl;

    int maxArea = 0;
    int currArea = 0;

    for(int i = 0; i < heights.size(); i++){

        currArea = heights[i] * (rightSmaller[i] - leftSmaller[i] - 1);

        if(maxArea < currArea) maxArea = currArea;
    }

    return maxArea;
}

int main(){

    vector<int> histogram = {1,1};

    int maxHeight = largestRectangleArea(histogram);
    cout << maxHeight << endl;

}
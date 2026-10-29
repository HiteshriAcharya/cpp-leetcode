#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> height){

    int maxWater = 0;
    int tempMax = 0;

    int startIdx = 0;
    int endIdx = height.size() - 1;

    while(startIdx < endIdx){

        tempMax = min(height.at(startIdx), height.at(endIdx)) * (endIdx-startIdx);
        maxWater = max(maxWater, tempMax);

        cout << "DEBUG: tempMax = " << tempMax << " and maxWater = " << maxWater << endl;

        if(height.at(startIdx) > height.at(endIdx)){
            endIdx -= 1;
        } else {
            startIdx += 1;
        }
    }

    return maxWater;
}

int main(){

    int size;

    cout << "Enter size: ";
    cin >> size;

    vector<int> input(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " th element: ";
        cin >> input[i];
    }

    int result = maxArea(input);

    cout << result << endl;
}
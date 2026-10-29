#include <iostream>
using namespace std;

int trappedWater(int N, int *arr){

    int totalWater = 0;
    int leftMax[N];
    int rightMax[N];

    int tempLeftMax = INT32_MIN;
    int tempRightMax = INT32_MIN;
    int minMax = 0;
    int waterLevelDiff = 0;

    for(int i = 0; i < N; i++){

        tempLeftMax = max(tempLeftMax, arr[i]);
        leftMax[i] = tempLeftMax;
        cout << "DEBUG: arr[i]: " << arr[i] << " leftMax[i]: " << leftMax[i] << endl;
    }

    for(int i = N-1; i > 0; i--){

        tempRightMax = max(tempRightMax, arr[i]);
        rightMax[i] = tempRightMax;
        cout << "DEBUG: arr[i]: " << arr[i] << " rightMax[i]: " << rightMax[i] << endl;
    }

    for(int i = 0; i < N; i ++){

        minMax = min(leftMax[i], rightMax[i]);
        waterLevelDiff = minMax - arr[i];
        totalWater += (waterLevelDiff < 0) ? 0 : waterLevelDiff;
        cout << "DEBUG: minMax: " << minMax << " waterLevelDiff: " << waterLevelDiff << " totalWater: " << totalWater << endl;
    }

    return totalWater;

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

    int totalWater = trappedWater(N, array);

    cout << "Total trapped rainwater: " << totalWater;

}
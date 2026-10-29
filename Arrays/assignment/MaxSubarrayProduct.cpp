#include <iostream>
using namespace std;

int maxProduct(int N, int *arr){

    /** This will not work because unlike the 
     * previous example of maximum subarray sum
     * where negative values are NEVER wanted, 
     * they could be wanted here. We cannot just 
     * check for the values after because the
     * negative value could be useful even at the end
     */

    // int maxProduct = INT32_MIN;
    // int tempProduct = 1;

    // int tempStartIdx = 0;
    // int endIdx = 0;
    // int startIdx = 0;

    // for(int i = 0; i < N; i++){

    //     tempProduct *= arr[i];

    //     if(maxProduct < tempProduct){
    //         maxProduct = tempProduct;
    //         endIdx = i;
    //         startIdx = tempStartIdx;
    //     }

    //     if (tempProduct < 0)
    //     {
    //         if (i != N-1 && arr[i + 1] > 0){

    //             tempStartIdx = i + 1;
    //             tempProduct = 1;
    //         }
    //     }
    // }

    // cout << "Start index: " << startIdx << " and end index: " << endIdx << endl;

    // return maxProduct;


    int maxProduct = arr[0];
   
    int currMax = arr[0];
    int currMin = arr[0];

    for(int i = 1; i < N; i++){

        int temp = max(arr[i], max(arr[i] * currMax, arr[i] * currMin));

        currMin = min(arr[i], min(arr[i] * currMax, arr[i] * currMin));

        cout << "currMin: " << currMin << endl;

        currMax = temp;

        cout << "currMax: " << currMax << endl;

        maxProduct = max(maxProduct, currMax);

        cout << "maxProduct: " << maxProduct << endl;
    }

    return maxProduct;
    
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

    int max = maxProduct(N, array);

    cout << "Maximum subarray product: " << max << endl;

}
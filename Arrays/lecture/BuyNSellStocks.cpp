#include <iostream>
using namespace std;

void buyNSell(int N, int *arr){

    int buyDay = 0;
    int sellDay = 0;
    int maxProfit = 0;
    int tempProfit = 0;

    for(int i = 1; i < N; i++){

        tempProfit = arr[i] - arr[buyDay];

        if(tempProfit < 0){
            buyDay = i;
        }

        if(maxProfit < tempProfit){
            maxProfit = tempProfit;
            sellDay = i;
        }
    }

    if(maxProfit == 0){

        cout << "Max profit is 0";
    } else {

        cout << "You can buy at " << buyDay << " and sell at " << sellDay << " and profit " << maxProfit;
    }
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
    
    buyNSell(N, array);

}
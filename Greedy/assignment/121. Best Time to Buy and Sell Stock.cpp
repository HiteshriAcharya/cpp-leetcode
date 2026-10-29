#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {

    int profit = 0;
    int currProfit = 0;
    int buy = 0;

    for(int i = 1; i < prices.size(); i ++){

        currProfit = prices[i] - prices[buy];
        if(currProfit < 0) buy = i;
        else profit = max(profit, currProfit);
    }

    return profit;
}

int main(){
    vector<int> prices = {7,6,4,3,1};
    cout << maxProfit(prices) << endl;
}
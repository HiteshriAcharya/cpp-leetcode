#include <iostream>
using namespace std;

int cutRod_Mem(vector<int>& price,
               vector<vector<int>>& dp,
               int idx,
               int amount){

    if(amount == 0){
        return 0;
    } else if(idx == 0){
        return amount * price[0]; // it is * here due to logic; when idx == 0, the only piece length available is 1. 
    } else if(dp[amount][idx] != -1){
        return dp[amount][idx];
    }

    int cut = 0;
    int skip = cutRod_Mem(price, dp, idx - 1, amount);

    if(idx + 1 <= amount){
        cut = price[idx] + cutRod_Mem(price, dp, idx, amount - (idx+1));
    }

    return dp[amount][idx] = max(cut, skip);
}

int cutRod(vector<int>& price, int n){

    vector<vector<int>> dp(n + 1, vector<int>(price.size(), -1));
    return cutRod_Mem(price, dp, price.size() - 1, n);
}

int main(){

    vector<int> price{1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;

    cout << cutRod(price, n) << endl;
}
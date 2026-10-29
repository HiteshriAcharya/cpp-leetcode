#include <iostream>
using namespace std;

/**
 * It is important to understand the meaning of the dp array
 * 
 * At dp[n][W], it is the max value we can hold with n items and W capacity
 * 
 * The answer we need to find is at n capacity and W capacity, what is the max value
 * To find this, we need to look at the sub problems that help us find this answer
 * 
 */

// TC : O(2^n)
double knapsack01_Rec(vector<vector<int>>& items, int W, int n){

    // Base Case
    if(n == 0 || W == 0) return 0;

    if(items[n-1][1] <= W){
        
        double include = knapsack01_Rec(items, W - items[n-1][1], n-1) + items[n-1][0];
        double exclude = knapsack01_Rec(items, W, n-1);

        return max(include, exclude);

    } else{
        return knapsack01_Rec(items, W, n-1);
    }
}

// TC : O(n x W)
// SC : O(n x W) + O(n) for the rec stack
double knapsack01_Mem(vector<vector<int>>& items, vector<vector<int>>& dp, int W, int n){

    // Base Case
    if(n == 0 || W == 0) return 0;
    else if(dp[n][W] != -1) return dp[n][W];

    if(items[n-1][1] <= W){
        
        double include = knapsack01_Mem(items, dp, W - items[n-1][1], n-1) + items[n-1][0];
        double exclude = knapsack01_Mem(items, dp, W, n-1);

        return dp[n][W] = max(include, exclude);

    } else{
        return dp[n][W] = knapsack01_Mem(items,dp, W, n-1);
    }
}

// TC : O(n x W)
// SC : O(n x W)
double knapsack01_Tab(vector<vector<int>>& items, int W, int n){

    // Initialise to '0' instead of '-1' because unlike recussion, we do not 
    // check here dp[n][W] != -1. We directly compute

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < W + 1; j++){

            int val = items[i-1][0];
            int wt = items[i-1][1];

            if(wt <= j){
                
                double include = dp[i-1][j - wt] + val;
                double exclude = dp[i-1][j];

                dp[i][j] = max(include, exclude);

            } else{

                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main(){

    vector<vector<int>> items = {{20,2},
                                 {30,3},
                                 {50,4},
                                 {60,5},
                                 {100,9}};

    int W = 10;

    cout << knapsack01_Rec(items, W, items.size()) << endl;

    vector<vector<int>> dp(items.size() + 1, vector<int>(W + 1, -1));

    cout << knapsack01_Mem(items, dp, W, items.size()) << endl;

    cout << knapsack01_Tab(items, W, items.size()) << endl;
    
}
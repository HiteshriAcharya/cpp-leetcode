#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 
 * Space complexity = depth of ONE path => O(n + W/minWeight) == O(max(n, W/minWeight))
 * 
 * Time complexity  = total number of paths/calls explored => O(2^(n + W/minWeight))
 * 
 * skip can happen at most n times
 * take can happen at most about W / minWeight times along one path
 * 
 * O(n + W/minWeight)
 */

int unboundedKnapsack_Rec(vector<vector<int>>& items, int idx, int W){

    if(idx == 0) return (W/items[0][1]) * items[0][0];

    if(items[idx][1] <= W){

        int take = items[idx][0] + unboundedKnapsack_Rec(items, idx, W - items[idx][1]);
        int skip = unboundedKnapsack_Rec(items, idx - 1, W);

        return max(take, skip);

    } else{
        return unboundedKnapsack_Rec(items, idx - 1, W);
    }
}

int unboundedKnapsack_Mem(){

}

int main(){

    vector<vector<int>> items = {
    {4, 2},
    {5, 3}};
    
    int W = 7;

    cout << unboundedKnapsack_Rec(items, items.size() - 1, W) << endl;

    vector<vector<int>> dp()
}
#include <iostream>
#include <vector>
using namespace std;

/**
 * The main trick in here to make it O(n) is that we do numCoins += amount/coins[i]; 
 * This helps to "use" as many of the coins[i] as possible in one go.
 * For example if our amount is 41, it will stop at 20 and add 2 as expected
 * and the remaining will be 1.
 */

int coinChange(vector<int>& coins, int amount) {
    
    sort(coins.begin(), coins.end(), greater<int>());
    int numCoins = 0;

    for(int i = 0; i < coins.size() && amount > 0; i++){

        if(coins[i] <= amount){
            numCoins += amount/coins[i];  
            cout << "DEBUG: amount: " << amount << " , numCoins: "  << numCoins << " , coins[i]: " << coins[i] << endl;            
            amount = amount%coins[i];
            cout << "DEBUG: Remaining: " << amount << endl;
        }
    }

    cout << "DEBUG: Final: " << amount << endl;
    return numCoins;
}

int main(){
    vector<int> coins = {186,419,83,408};
    int amount = 6249;
    cout << coinChange(coins,amount) << endl;
}
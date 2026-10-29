#include <iostream>
#include <vector>
using namespace std;

/**
 * MAIN IDEA : This is a greedy problem!
 * 
 * If starting from start and moving forward, the tank becomes negative at station i, 
 * then every station between start and i also fails.
 * 
 * If any point in time s fails, none of the pumps between s and i can be starting points!
 * 
 * This is how we are able to achieve O(n) and dont have to be O(n^2)
 */

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    
    int tank = 0;    // how much fuel we currently have if we start from "start"
    int total = 0;   // how much fuel in total 
    int start = 0;

    for(int i = 0; i < gas.size(); i++){

        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;

        if(tank < 0){
            start = i + 1;
            tank = 0;
        }
    }

    return total < 0 ? -1 : start;
}

int main(){

    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << canCompleteCircuit(gas, cost) << endl;
}


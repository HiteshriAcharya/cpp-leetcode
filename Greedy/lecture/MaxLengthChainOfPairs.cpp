#include <iostream>
#include <vector>
using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {

    sort(pairs.begin(), pairs.end(), 
        [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

    int numPairs = 1;
    int end = pairs[0][1];

    for(int i = 1; i < pairs.size(); i++){
        if(pairs[i][0] > end){
            numPairs += 1;
            end = pairs[i][1];
        }
    }

    return numPairs;
}

int main(){

    vector<vector<int>> pairs = {{1,2}, {2,3}, {3,4}};
    cout << findLongestChain(pairs) << endl;
}
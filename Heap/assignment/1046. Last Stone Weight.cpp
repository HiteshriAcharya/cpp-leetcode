#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& stones) {

    priority_queue<int> pq(stones.begin(), stones.end());

    while(pq.size() > 1){

        int max1 = pq.top();
        pq.pop();

        int max2 = pq.top();
        pq.pop();

        if(max1 != max2) pq.push(max1-max2);
    }

    if(pq.size() == 1) return pq.top();
    else return 0;
}

int main(){

    vector<int> stones = {2,7,4,1,8,1};
    cout << lastStoneWeight(stones) << endl;;
}
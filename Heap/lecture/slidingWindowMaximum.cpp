#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    // obj.first is value and obj.second is idx
    // Like this because by default, it 
    
    priority_queue<pair<int,int>> pq;
    vector<int> results;

    for(int i = 0; i < k; i++){
        pq.push(make_pair(nums[i], i));
    }

    results.push_back(pq.top().first);

    for(int i = k; i < nums.size(); i++){
        while(!pq.empty() && pq.top().second <= i-k){
            pq.pop();
        }

        pq.push(make_pair(nums[i],i));
        results.push_back(pq.top().first);
    }

    return results;
}

int main(){

}
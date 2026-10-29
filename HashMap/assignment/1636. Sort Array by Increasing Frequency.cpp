#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {

    unordered_map<int,int> freq;

    for(int i = 0; i < nums.size(); i++){
        freq[nums[i]] += 1;
    }

    sort(nums.begin(), nums.end(), [&](int a, int b){
        if(freq[a] == freq[b]){
            return a > b; // same freq: bigger number first
        } else{
            return freq[a] < freq[b]; // smaller freq first
        }
    });

    return nums;
}

int main(){

}
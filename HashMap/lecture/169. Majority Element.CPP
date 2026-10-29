#include <iostream>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {

    unordered_map<int, int> m;

    for(int i = 0; i < nums.size(); i++){

        if(m.count(nums[i]) == 1){
            m[nums[i]] += 1;
        } else{
            m[nums[i]] = 1;
        }
    }

    int major = -1;

    for(pair<int,int> el : m){
        if(el.second > nums.size()/2){
            major = el.first;
            return major;
        }
    }

    return major;
}

int main(){

}
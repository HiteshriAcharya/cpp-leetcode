#include <iostream>
#include <vector>
using namespace std;

int maxActivities(vector<int> start, vector<int> end){

    int count = 1; // starts from 1 because can perform the first activity REGARDLESS!
    int currEnd = end[0];

    for(int i = 1; i < start.size(); i++){
        if(start[i] >= currEnd){
            count +=1;
            currEnd = end[i]; // we have to include the previous non-overlapping slot so this update can only happen in the if block!!
        }
    }

    return count;
}

int main(){

    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};
    cout << maxActivities(start, end) << endl;
}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    vector<vector<int>> results;

    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    });

    int currStart = intervals[0][0];
    int currEnd = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++){
        if(currEnd >= intervals[i][0]){
            currEnd = max(currEnd, intervals[i][1]);
        } else{
            results.push_back({currStart, currEnd});
            currStart = intervals[i][0];
            currEnd = intervals[i][1];
        }
    }
    results.push_back({currStart, currEnd});

    return results;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> results = merge(intervals);

    for(int i = 0; i < results.size(); i++){
        for(int j = 0; j < results[0].size(); j++){
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}
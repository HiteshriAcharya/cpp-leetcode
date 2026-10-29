#include <iostream>
#include <vector>
using namespace std;

int fractionalKnapsack(vector<int> val, vector<int> weight, int totalWeight){

    vector<pair<float, int>> ratio(val.size(), make_pair(0.0,0));
    int ans = 0;
    
    for(int i = 0; i < val.size(); i++){
        double r = (double) val[i] / (double) weight[i];
        ratio[i].first = r;
        ratio[i].second = i;
    }

    sort(ratio.begin(), ratio.end(), [](pair<float,int> a, pair<float,int> b) {
        return a.first > b.first;
    });

    for(int i = 0; i < ratio.size(); i++){
        int idx = ratio[i].second;
        if(totalWeight >= weight[idx]){
            ans += val[idx];
            totalWeight -= weight[idx];
        }else{
            ans += ratio[i].first * totalWeight;
            totalWeight = 0;
            break;
        }
    }

    return ans;
}

int main(){

    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};
    int totalWeight = 50;

    cout << fractionalKnapsack(val, wt, totalWeight) << endl;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// obj.first is idx and obj.second is num_of_soldiers

struct ComparePair{
    bool operator () (pair<int, int> &p1, pair<int, int> &p2){
        if(p1.second == p2.second) return p1.first > p2.first;
        else return p1.second > p2.second;
    }
};

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

    vector<pair<int,int>> rows;
    vector<int> results;
        
    for(int i = 0; i < mat.size(); i++){
        int count = 0;
        for(int j = 0; j < mat[i].size() && mat[i][j] == 1; j++){
            count += 1;
        }
        rows.push_back(make_pair(i,count));
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, ComparePair> pq(rows.begin(), rows.end());

    for(int i = 0; i < k; i++){
        results.push_back(pq.top().first);
        pq.pop();
    }

    return results;
}

int main(){

    vector<vector<int>> mat = {{1,1,0,0,0},
                               {1,1,1,1,0},
                               {1,0,0,0,0},
                               {1,1,0,0,0},
                               {1,1,1,1,1}};
    int k = 3;
    
    vector<int> results = kWeakestRows(mat, k);

    for(int i = 0; i < results.size(); i++) cout << results[i] << " ";
    cout << endl;
}
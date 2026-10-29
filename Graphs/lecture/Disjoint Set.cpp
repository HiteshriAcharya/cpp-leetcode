#include <iostream>
#include <vector>
using namespace std;

class DisjointSet{
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n){
        this->n = n;

        parent.resize(n);
        rank.resize(n, 0);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;
        return find(parent[x]);
    }

    void unionByRank(int a, int b){

        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){
            parent[parB] = parA; // A is the default parent
            rank[parA] += 1;
        } else if(rank[parA] > rank[parB]){
            parent[parB] = parA;
        } else{
            parent[parA] = parB;
        }
    }
};

int main(){
    DisjointSet dj(6);
    dj.unionByRank(0,2);
    cout << dj. find(2) << endl;
}
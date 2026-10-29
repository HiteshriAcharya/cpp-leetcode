#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Car{

public:

    int idx;
    int distSq;

    Car(int idx, int distSq){
        this->idx = idx;
        this->distSq = distSq;
    }

    bool operator < (const Car &obj) const{
        return this->distSq > obj.distSq; // minheap
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    vector<Car> cars;

    for(int i = 0; i < points.size(); i++){
        int distSq = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        cars.emplace_back(i,distSq);
    }

    priority_queue<Car> pq(cars.begin(), cars.end());

    vector<vector<int>> result;

    for(int i = 0; i < k; i++){
        result.push_back(points[pq.top().idx]);
        pq.pop();
    }

    return result;
}

int main(){

    vector<vector<int>> positions = {{3,3}, {5,-1}, {-2,4}};
    int k = 2;

    vector<vector<int>> result = kClosest(positions, k);

    for(int i = 0; i < result.size(); i++) cout << result[i][0] << "," << result[i][1] << endl;
}
#include <iostream>
#include <queue>
using namespace std;


int main(){

    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    pq.push(10);
    pq.push(9);
    pq.push(3);
    pq.push(1);

    minHeap.push(1);
    minHeap.push(5);
    minHeap.push(8);

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;

    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    cout << endl;

}
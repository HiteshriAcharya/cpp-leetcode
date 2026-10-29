#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {

    vector<int> freq(26,0);

    for(int i = 0; i < tasks.size(); i++){
        freq[tasks[i] - 'A'] += 1;
    }

    priority_queue<int> pq;

    for(int f : freq){
        if(f > 0) pq.push(f);
    }

    int minCPUCount = 0;

    while(!pq.empty()){

        vector<int> temp;
        int cycle = n+1;

        while(cycle > 0 && !pq.empty()){
            
            int freq = pq.top();
            pq.pop();

            cycle -= 1;
            freq -= 1;
            minCPUCount += 1;

            if(freq > 0) temp.push_back(freq);
        }

        for(int t : temp) pq.push(t);

        // This is to fill the remaining slots with idle time
        if(!pq.empty()) minCPUCount += cycle;
    }

    return minCPUCount;
}

int main(){

    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    cout << leastInterval(tasks, n) << endl;
}
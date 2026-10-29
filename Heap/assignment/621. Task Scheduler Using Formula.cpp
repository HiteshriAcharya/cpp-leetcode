#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {

    vector<int> freq(26,0);

    for(int i = 0; i < tasks.size(); i++){
        freq[tasks[i] - 'A'] += 1;
    }

    int maxFreq;
    int countMaxFreq;

    for(int f : freq){
        if(f > maxFreq){
            maxFreq = f;
            countMaxFreq = 1;
        }
        else if(f == maxFreq) countMaxFreq += 1;
    }

    int numOfIntervals = maxFreq - 1;
    int minCPUCount = numOfIntervals * (n + 1) + countMaxFreq;

    return max(minCPUCount, (int)tasks.size());
}

int main(){

    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    cout << leastInterval(tasks, n) << endl;
}
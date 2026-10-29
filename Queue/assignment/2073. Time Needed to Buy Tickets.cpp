#include <iostream>
#include <queue>
using namespace std;

/**
 * This takes a lot of time. The TC is O(sum of tickets) in the worst case and not O(n)
 */

int timeRequiredToBuy(vector<int>& tickets, int k) {

    queue<pair<int,int>> q;
    int time = 0;

    for(int i = 0; i < tickets.size(); i++){
        q.push({tickets[i],i});
    }

    while(!q.empty()){

        pair<int,int> curr = q.front();
        q.pop();
        int currTickets = curr.first;
        int idx = curr.second;

        currTickets -= 1;
        time += 1;

        if(idx == k && currTickets == 0) return time;

        if(currTickets > 0) q.push({currTickets,idx});
    }

    return time;
}

/**
 * This solution is better as it uses math. The number of total rounds allowed is
 * tickets[k] rounds. We need to find how many people will also be buying the 
 * tickets at the same time. 
 * 
 * There is 2 cases, when i is <= k and when i is > k. 
 * 
 * When i <= k, these are all the people who would def need to be involved in the 
 * purchasing round.
 */

int timeRequiredToBuy2(vector<int>& tickets, int k){

    int time = 0;

    for(int i = 0; i < tickets.size(); i++){

        if(i <= k) time += min(tickets[i], tickets[k]);
        else time += min(tickets[i], tickets[k] -1); // one round lesser for the people after k
    }

    return time;
}

int main(){

    vector<int> tickets = {5,1,1,1};              
    int k = 0;
    cout << timeRequiredToBuy2(tickets,k) << endl;
}
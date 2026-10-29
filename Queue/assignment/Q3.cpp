#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q, int k){

    stack<int> temp;

    for(int i = 0; i < k; i++){
        temp.push(q.front());
        q.pop();
    }

    while(!temp.empty()){
        q.push(temp.top());
        temp.pop();
    }

    for(int i = 0; i < q.size()-k; i++){
        q.push(q.front());
        q.pop();
    }
}



int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    reverseQueue(q,k);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}
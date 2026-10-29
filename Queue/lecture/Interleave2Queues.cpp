#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int> q){

    queue<int> temp;
    int size = q.size();

    for(int i = 0; i < size/2; i++){
        temp.push(q.front());
        q.pop();
    }

    while(!temp.empty()){
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
}

int main(){


}
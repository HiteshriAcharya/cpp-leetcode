#include <iostream>
#include <stack>
using namespace std;

class MinStack{

    stack<pair<int,int>> s;
    int currMin;

public:

    MinStack(){
        currMin = INT_MAX;
    }

    void push(int val){
        if(currMin > val){
            s.push({val, val});
            currMin = val;
        } else{
            s.push({val,currMin});
        }
    }

    void pop(){
        if(s.top().second == currMin){
            s.pop();
            if(s.empty()) currMin = INT_MAX;   // VERY IMPORTANT! WHAT IF THIS IS THE LAST ELEMENT YOU POPPED!!
            else currMin = s.top().second;
        } else s.pop();
    }

    int top(){
        return s.top().first;
    }

    int getMin(){
        return currMin;
    }
};
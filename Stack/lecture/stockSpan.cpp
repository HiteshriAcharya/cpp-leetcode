#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * How far back can I go until I hit a day where the price was strictly higher than today?
 * 
 * The span is not blocked by the global maximum — it is blocked by the nearest higher price.
 * 
 * It is about the nearest larger element on the left.
 */

void stockSpan(vector<int>& stock, vector<int>& span){

    stack<int> prevHigh; // Stores the idx and not the value
    prevHigh.push(0); //Push the idx
    span.at(0) = 1; // There so no element greater from the left for the first element obviously

    // Now, we want to find the MAX but from the LEFT 
    for(int i = 1; i < stock.size(); i++){

        // Keep removing until you find a element greater
        while(!prevHigh.empty() && stock[prevHigh.top()] <= stock.at(i)){
            prevHigh.pop();
        }

        // There is NO previous day to the left with a higher price than today.
        // stack empty ⇒ nothing on the left is greater
        // today is greater than or equal to ALL previous days
        
        if(prevHigh.empty()){
            span.at(i) = i + 1;
        } else{
            span.at(i) = i - prevHigh.top();
        }
        prevHigh.push(i);
    }
}

int main(){

    vector<int> stock = {100,80,60,70,60,85,100};
    vector<int> span(7,0);

    stockSpan(stock, span);

    for(int i = 0; i < span.size(); i++){

        cout << span.at(i) << " ";
    }
    cout << endl;
}
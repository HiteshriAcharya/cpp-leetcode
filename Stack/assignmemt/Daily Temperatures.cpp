#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {

    int size = temperatures.size();

    stack<int> temp;
    vector<int> output(size, 0);

    temp.push(size-1);
    output[size-1] = 0;

    for(int i = size-2; i >= 0; i--){

        while(!temp.empty() && temperatures[i] >= temperatures[temp.top()]) temp.pop();

        if(temp.empty()) output[i] = 0;
        else output[i] = temp.top() - i;

        temp.push(i);
    }

    return output;
}

int main(){

    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> output = dailyTemperatures(temperatures);

    for(int i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }

    cout << endl;
}
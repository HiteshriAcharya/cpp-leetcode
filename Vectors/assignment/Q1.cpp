#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findErrorNums(vector<int> nums){
    
    vector<int> result(2,-1);
    vector<int> counter(nums.size()+1,0);

    for(int i = 0; i < nums.size(); i++){

        counter[nums.at(i)] += 1;
    }

    for(int i = 1; i <= nums.size(); i++){

        if(counter.at(i) == 0){

            result[1] = i;

        }

        if(counter.at(i) == 2){

            result[0] = i;
        }
    }

    return result;


}

int main(){

    int size;

    cout << "Enter size: ";
    cin >> size;

    vector<int> input(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " th element: ";
        cin >> input[i];
    }

    vector<int> result = findErrorNums(input);

    cout << result[0] << " " << result[1] << endl;
}
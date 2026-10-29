#include <iostream>
#include <vector>
using namespace std;

int SingleNumber(vector <int> nums){

    int result = nums.at(0);

    for(int i = 1; i < nums.size(); i ++){

        result = result ^ nums.at(i);
    }

    return result;
}


int main(){

    vector <int> nums;
    int size;

    cout << "Size of the vector: ";
    cin >> size;

    for(int i = 0; i < size; i++){

        int element;
        cout << "Enter number: ";
        cin >> element;

        nums.push_back(element);
    }

    int result = SingleNumber(nums);
}
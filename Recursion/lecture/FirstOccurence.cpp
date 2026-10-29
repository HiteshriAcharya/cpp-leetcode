#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector <int> vec, int n, int i){

    if(i == vec.size()){
        return -1;
    }

    if(vec[i] == n){

        return i;
    }

    return firstOccurrence(vec, n, i+1);
}

int main(){

    vector<int> vec = {1,2,3,3,3,4};
    cout << firstOccurrence(vec, 4, 0) << endl;

}
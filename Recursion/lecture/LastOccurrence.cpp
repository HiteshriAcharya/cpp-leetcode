#include <iostream>
#include <vector>
using namespace std;

int lastOccurrence(vector<int> vect, int n, int i){

    if(i == -1){
        return -1;
    }

    if(vect.at(i) == n){
        return i;
    }

    return lastOccurrence(vect, n, i-1);
    
}

int lastOccurrenceACMethod(vector<int> vect, int n, int i){

    if(i == vect.size()){
        return -1;
    }

    int idxFound = lastOccurrenceACMethod(vect, n, i+1);
    if(idxFound == -1 && vect.at(i) == n){

        return i;
    }

    return idxFound;
}

int main(){

    vector<int> vect = {1,2,4};
    int result = lastOccurrence(vect, 3, vect.size() -1);
    cout << result << endl;
}
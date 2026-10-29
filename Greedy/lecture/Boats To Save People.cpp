#include <iostream>
#include <vector>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {

    sort(people.begin(), people.end());
    int boatCount = 0;
    int left = 0;
    int right = people.size() - 1;

    while(left <= right){ // must be <= because need to account for the person in the middle
        if(people[left] + people[right] <= limit) left += 1; // if left + right can make a pair, decrement both pointers but only add 1 boat!!
        right -= 1; // if left + right does not make a pair, right is too large, it cannot make a pair with the smallest element, goes alone!!
        boatCount += 1;   
    }

    return boatCount;
}

int main(){
    vector<int> people = {1,2,2}; 
    int limit = 3;
    cout << numRescueBoats(people, limit) << endl;
}
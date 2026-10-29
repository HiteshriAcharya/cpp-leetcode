#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * The base would be everything is 'a' because it could be that the 'a's are in 
 * the front. We would then loop from the back and check what is the min, can i fit 
 * a 'z'? If i cannot fit a 'z', it means i can directly just have the character.
 */

string getSmallestString(int n, int k) {

    string result (n, 'a');
    k -= n;

    for(int i = n-1; i >= 0 && k >= 0; i--){
        int add = min(25,k);
        result[i] += add;
        k -= add;
    }

    return result;
}

int main(){

    int n = 5;
    int k = 73;

    cout << getSmallestString(n,k) << endl;
}

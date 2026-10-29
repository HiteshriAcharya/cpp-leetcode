#include <iostream>
#include <string>
using namespace std;

void towerOfHanoi(int n, string source, string helper, string destination){

    if(n == 0){
        return;
    }

    towerOfHanoi(n-1, source, destination, helper);
    cout << n << " is transferred from " << source << " to " << destination << endl;
    towerOfHanoi(n-1, helper, source, destination);

}

int main(){

    int n = 2;
    towerOfHanoi(n, "S", "H", "D");

}
#include <iostream>
using namespace std;

int fillTiles(int n){

    if(n == 0 || n == 1){

        return 1;
    }

    return fillTiles(n-1) + fillTiles(n-2);
}

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    int ways = fillTiles(n);

    cout << ways << endl;
}
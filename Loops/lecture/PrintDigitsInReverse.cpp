#include <iostream>
using namespace std;

int main(){

    int n;

    cout << "Enter n: ";
    cin >> n;

    int i = n;

    while(i > 0){

        i = i % 10;
        cout << i;
        i = i / 10;
    }
}
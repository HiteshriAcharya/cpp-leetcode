#include <iostream>
using namespace std;

int clearLastBits(int num, int x){

    int mask = -1 << x;
    num = num & mask;

    return num;
}

int main(){

    int num,x;

    cout << "Enter num: ";
    cin >> num;

    cout << "Enter x: ";
    cin >> x;

    num = clearLastBits(num,x);

    cout << num << endl;
}
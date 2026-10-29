#include <iostream>
using namespace std;

int GetBit(int num, int x){

    int mask = 1 << x;
    num = num & mask;

    return num;

}

int SetBit(int num, int x){

    int mask = 1 << x;
    num = num | mask;

    return num;
}

int ClearBit(int num, int x){

    int mask = ~(1 << x);

    num = num & mask;

    return num;
}

int main(){

    int num, x;

    cout << "Enter num: ";
    cin >> num;

    cout << "Enter x: ";
    cin >> x;

    //num = GetBit(num,x);
    // num = SetBit(num, x);
     num = ClearBit(num, x);

    cout << num << endl;
}
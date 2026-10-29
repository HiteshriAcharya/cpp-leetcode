#include <iostream>
using namespace std;

int UpdateBit(int num, int x, int val){

    int mask = ~(1 << x);
    num = num & mask;

    mask = val << x;
    num = num | mask;

    return num;
}
    

int main(){

    int num, x, val;

    cout << "Enter num, x and val: ";
    cin >> num;
    cin >> x;
    cin >> val;

    num = UpdateBit(num, x, val);

    cout << num << endl;
}
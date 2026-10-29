#include <iostream>
using namespace std;

int ClearBitsFromItoJ(int i, int j, int num){

    int mask1 = -1 << (j+1);
    cout << "DEBUG: mask1 = " << mask1 << endl;

    int mask2 = ~(-1 << i);
    cout << "DEBUG: mask2 = " << mask2 << endl;

    int mainMask = mask1 | mask2;
    cout << "DEBUG: mainMask = " << mainMask << endl;

    int result = num & mainMask;

    return result;
}

int main(){

    int i,j,num;

    cout << "Enter start pos, i: ";
    cin >> i;

    cout << "Enter end pos, j: ";
    cin >> j;

    cout << "Enter num: ";
    cin >> num;

    int result = ClearBitsFromItoJ(i, j, num);

    cout << result << endl;
}
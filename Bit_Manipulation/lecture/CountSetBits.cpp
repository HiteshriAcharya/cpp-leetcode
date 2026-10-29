#include <iostream>
using namespace std;

/**
 * Maybe this question might not work for -ve numbers
 */

int countSetBits2(int num)
{
    int size = sizeof(num) * 8; // total number of bits
    cout << "DEBUG: size= " << size << endl;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        int mask = 1 << i;
        int add = ((num & mask) > 0) ? 1 : 0; // take note of precedence
        count += add;
    }

    return count;
}

/**
 * This function would only work for positive values.
 * This is because most systems will preserve the signed
 * bit so regardless of right shifting, it will never
 * approach 0. Hence, this is an infinite loop.
 * So if num is -1 (all 1s), shifting right keeps 
 * inserting a 1 at the left, and it stays -1 forever
 */

int countSetBits(int num){

    int count = 0;

    while(num != 0){

        count += (num & 1);
        num = num >> 1;

    }

    return count;
}

int main(){

    int num;

    cout << "Enter num: ";
    cin >> num;

    //int count = countSetBits(num);
    int count2 = countSetBits2(num);
    //cout << count << endl;
    cout << count2 << endl;

}
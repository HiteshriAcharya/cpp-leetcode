#include <iostream>
using namespace std;

bool isPalindrome(int n){

    int num = n;
    int sum = 0;

    while(num > 0){

        sum = (10*sum) + (num % 10);
        num /= 10;

    }

    if(sum == n){

        return true;
    } else {

        return false;
    }


}

int main(){

    int n;
    cout << "Enter a number n: ";
    cin >> n;

    if(isPalindrome(n)){

        cout << n << " is a Palindrome" << endl;
    } else {

        cout << n << " is not a Palindrome" << endl;
    }


}
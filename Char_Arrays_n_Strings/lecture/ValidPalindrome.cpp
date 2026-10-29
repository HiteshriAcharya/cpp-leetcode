#include <iostream>
using namespace std;

int main(){

    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    cin.ignore();

    char str[size + 1];

    cout << "Enter string: ";
    cin.getline(str, size + 1);

    bool isPalindrome = true;

    int start = 0;
    int end = size-1;

    while(start <= end){

        if(str[start] != str[end]){

            cout << str[start] << " and " << str[end] << endl;
            cout << "Exiting..." << endl;
            isPalindrome = false;
            break;
        } 
        start+=1;
        end-=1;
    }
    cout << isPalindrome << endl;
}
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

    int start = 0;
    int end = size-1;

    while(start <= end){

        swap(str[start], str[end]);
        start+=1;
        end-=1;
    }

    for(int i = 0; i < size; i++){

        cout << str[i];
    }

    cout << endl;
}
#include <iostream>
using namespace std;

int main(){

    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    cin.ignore();

    char str[size+1];

    cout << "Enter string: ";
    cin.getline(str, size+1);

    for(int i = 0; i < size; i++){

        if(str[i] >= 'a' && str[i] <= 'z'){

            // This is assuming we know the numbers. What if we don't??
            // str[i] = str[i] - 32;

            str[i] = 'A' + (str[i] - 'a');
        }

        cout << str[i];
    }

    cout << endl;
}
#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a number n: ";
    cin >> n;

    int first = 0;
    int second = 1;

    int temp;

    cout << "0" << endl;
    cout << "1" << endl;

    for(int i = 0; i < n-2; i+=1){
        
        cout << first+second << endl;

        temp = second;
        second = second + first;
        first = temp;
    }
}
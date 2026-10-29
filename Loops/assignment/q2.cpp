#include <iostream>
using namespace std;

int main(){

    int n;

    cout << "Enter a number n: ";
    cin >> n;

    int m;

    cout << "Enter a number m you want the multiplication table to be till: ";
    cin >> m;

    int i = 1;

    while(i <= m){

        cout << i << "*" << n << "= " << i*n << endl;

        i +=1;
    }
}
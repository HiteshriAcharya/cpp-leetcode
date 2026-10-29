#include <iostream>
using namespace std;

int main(){

    while(1){

        int n;
        cout << "Enter a number that is not a multiple of 10: ";
        cin >>  n;

        if(n %10 == 0){

            cout<< "You have entered a multiple of 10. Exiting loop..." << endl;
            break;
        }
    }
}
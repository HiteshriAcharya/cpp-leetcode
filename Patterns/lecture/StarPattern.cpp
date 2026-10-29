#include <iostream>
using namespace std;

int main(){

    int row = 4;

    for (int i = 1; i <= row; i+=1){

        for(int j = 1; j<= i; j+=1 ){

            cout << "* " ;
        }

        cout << endl;
    }
}
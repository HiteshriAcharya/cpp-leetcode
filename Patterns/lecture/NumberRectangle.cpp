#include <iostream>
using namespace std;

int main(){

    int row = 5;
    int col = 10;

    for(int i = 1; i <=row; i+=1 ){

        for(int j = 1; j <= col; j+=1){

            cout << j << " ";
        }

        cout << endl;
    }
}
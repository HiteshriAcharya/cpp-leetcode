#include <iostream>
using namespace std;

int main(){

    int row = 7;
    int col = row;

    for(int i = 1; i <= row; i +=1){
        for(int j = col; j>= 1; j-=1){
            cout << "* ";
        }

        col-=1;
        cout << endl;
    }
}
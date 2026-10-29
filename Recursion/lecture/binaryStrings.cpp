#include <iostream>
using namespace std;

void printBinaryString(int n, string ans, int lastPlace){

    if(n==0){

        cout << ans << endl;
        return;  // stop execution of a function early
    }

    if(lastPlace == 0){
        printBinaryString(n-1,ans + '0', 0);
        printBinaryString(n-1, ans + '1', 1);
    } else {
        printBinaryString(n - 1, ans + '0', 0);
    }
}

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    string ans; 
    printBinaryString(n, ans, 0);

}
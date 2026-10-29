#include <iostream>
using namespace std;

char charAfterThis(char input){

    if(input == 'z'){

        return 'a';
    } else {

        return input+1;
    }


}

int main(){

    char input;
    cout << "Enter a char: ";
    cin >> input;

    cout << "The char after " << input << " is: " << charAfterThis(input) << endl;

}
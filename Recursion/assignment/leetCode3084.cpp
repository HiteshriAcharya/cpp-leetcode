#include <iostream>
#include <string>
using namespace std;

long long countSubstrings(string s, char c){

    long long cCount = 0;
    long long substrings = 0;

    for(char i : s){
        
        if(i == c){
            cCount += 1;
        }
    }

    cout << "DEBUG: cCount = " << cCount << endl;

    substrings = cCount * (cCount + 1) / 2; // Do not use this "cCount * ((cCount + 1)/2)" 
                                            // This causes the equation within the brackets to be solved first
                                            // This is an int division and its doing an implicit floor to the result

    return substrings;
}

int main(){

    string s = "bbbbiz";
    char c = 'b';

    long long result = countSubstrings(s,c);
    cout << result << endl;
}
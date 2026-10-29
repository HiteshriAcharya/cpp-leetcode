#include <iostream>
#include <string>
using namespace std;

/**
 * NOTE: You do not need to always check if the characters + frequency of characters
 * are the same. It might be counterproductive and not necessary. Check what you need 
 * first and do not jump to always use this.abort
 * 
 * @brief: First check same length, and then check same word or not. Then have 2
 * int variables to store the index of the differing characters. The edge case is 
 * firstly, if there are more than 2 differences and secondly, if there is only one
 * difference. At the end, check if "swapping" (not really) makes it the same
 */

bool CanSwap(string str, string str2){

    if(str.length() != str2.length()){
        return false;
    }

    if(str == str2){
        return true;
    }


    int firstDiff = -1;
    int secondDiff = -1;

    for(int i = 0; i < str.length(); i++){

        if(firstDiff == -1){
            firstDiff = i;
        } else if(secondDiff == -1){
            secondDiff = i;
        } else {

            return false;
        }
    }

    if(secondDiff == -1){
        return false;
    }

    return (str[firstDiff] == str2[secondDiff] && str[secondDiff] == str2[firstDiff]);

}

int main(){

    string str, str2;

    cout << "Enter first string: ";
    getline(cin, str);

    cout << "Enter second string: ";
    getline(cin, str2);

    bool result = CanSwap(str,str2);
    cout << "Result: " << result << endl;
}
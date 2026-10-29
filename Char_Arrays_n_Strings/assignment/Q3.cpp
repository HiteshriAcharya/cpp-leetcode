#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool IsClose(string str, string str2){

    if(str.length() != str2.length()){

        return false;
    }

    int count[26] = {0};
    int count2[26] = {0};

    for(char c : str){
        count[c -'a'] +=1;
    }

    for(char c2 : str2){
        count2[c2 - 'a'] +=1;
    }

    // Check of the ** SAME ** characters are present
    // Do not need to check if the characters have the same frequency because
    // that is taken of later
    for(int i = 0; i < 26; i++){
        if((count[i] > 0 && count2[i] == 0) || (count[i] == 0 && count2[i] > 0)){
            return false;
        }
    }

    sort(count, count+26);
    sort(count2, count2 + 26);

    for(int i = 0; i < 26; i++){
        if(count[i] != count2[i]){
            return false;
        }
    }

    return true;
}

int main(){

    string str, str2;
    cout << "Enter string 1: ";
    getline(cin, str);

    cout << "Enter string 2: ";
    getline(cin, str2);

    bool result = IsClose(str, str2);

    cout << result << endl;
}
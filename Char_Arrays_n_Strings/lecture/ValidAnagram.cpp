#include <iostream> 
#include <string>
using namespace std;

bool isValidAnagram(string str1, string str2){

    int count[26] = {0};

    if(str1.length() != str2.length()){

        return false;
    }

    for(int i = 0; i < str1.length(); i++){

        int index = str1.at(i) - 'a';
        count[index] += 1;
    }

    for (int j = 0; j < str2.length(); j++){

        int index = str2.at(j) - 'a';
        if(count[index] == 0){
            return false;
        }
        count[index] -= 1;
    }

    return true;
}

int main(){

    string str1,str2;
    cout << "Enter first string: ";
    getline(cin, str1);

    cout << "Enter second string: ";
    getline(cin, str2);

    bool result = isValidAnagram(str1,str2);

    cout << result << endl;
}
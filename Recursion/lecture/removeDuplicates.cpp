#include <iostream>
using namespace std;

string removeDuplicate(string input, string result, int i, bool *map){

    if(i == input.length()){

        return result;
    }

    if(map[(int)input.at(i) - 97] == 0){
        
        result += input.at(i);
        map[(int)input.at(i)-97] = 1;
    } 

    return removeDuplicate(input, result, i+1, map);
}

int main(){

    string input;

    cout << "Enter a string: ";
    cin >> input;

    bool map[26] = {0};

    string result;

    int i = 0;

    result = removeDuplicate(input, result, i, map);

    cout << result << endl;
}
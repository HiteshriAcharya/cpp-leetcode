#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string getHint(string secret, string guess) {

    unordered_map<char,int> freq;

    int len = secret.size();
    int bull = 0;
    int cow = 0;

    for(int i = 0; i < len; i++){
        if(secret[i] == guess[i]){
            bull += 1;
        } else{
            freq[secret[i]] += 1;
        }
    }

    for(int i = 0; i < len; i++){
        if(secret[i] != guess[i] && freq.count(guess[i]) == 1){
            cow += 1;
            freq[guess[i]] -= 1;
            if(freq[guess[i]] == 0) freq.erase(guess[i]);
        }
    }

    return to_string(bull) + "A" + to_string(cow) + "B";
}

int main(){

    string secret = "1807";
    string guess = "7810";

    cout << getHint(secret, guess) << endl;
}
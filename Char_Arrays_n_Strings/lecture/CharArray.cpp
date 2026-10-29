#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main(){

    char str[100] = "bro ";
    char str2[100] = "Sup dawgs";

    // strcat(str, str2);
    // cout << str << endl;

    // strcpy(str, str2);
    // cout << str << endl;

    cout << str << " and " << str2 << endl;
    cout << strcmp(str,str2) << endl;

    cout << strcasecmp(str,str2) << endl;

    

    // char work[5] = "code";
    // char work2[] = {'c', 'o', 'd', 'e', '\0'};
    // cout << strlen(work) << endl;
    // cout << strlen(work2) << endl;

    // char enterWord[30];
    // cin >> enterWord; // ignores whitespaces
    // cout << "Word: " << enterWord << endl;

    // char sentence[30];
    // cin.getline(sentence, 30, '*');
    // cout << "Word: " << sentence[0] << endl;
    // cout << "Length of string: " << strlen(sentence) << endl;
}
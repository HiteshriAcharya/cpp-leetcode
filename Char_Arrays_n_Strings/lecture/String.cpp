#include <iostream>
#include <string>
using namespace std;

int main(){

    string str = "hello";
    cout << str << endl;
    str = "yellow";
    cout << str << endl;

    string str2;
    getline(cin,str2);
    cout << str2 << endl;

    cout << str2[0] << endl;
    cout << str2.at(1) << endl;

    string str3 = "apna college";

    for(int i = 0; i < str3.length(); i++){

        cout << str3[i] << "-";
    }

    cout << endl;

    string str4 = "apna college 2";

    for(char ch : str4){
        cout << ch << "-";
    }

    cout << endl;

    cout << str2.substr(4,4) << endl;

    string str5 = "I love C++ and Java cause C++ is amazing";

    cout << str5.find("C++",10) << endl;
}
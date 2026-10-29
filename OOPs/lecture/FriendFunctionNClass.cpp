#include <iostream>
#include <string>
using namespace std;

class A{

    string secret = "secret info";
    friend class B;
    friend void revealSecret(A &obj);
};

class B{
public:
    void showClassASecret(A &obj){
        cout << obj.secret << endl;
    }
};

void revealSecret(A &obj){
    cout << obj.secret << endl;
}

int main(){

    B obj1;
    A obj2;

    obj1.showClassASecret(obj2);
}
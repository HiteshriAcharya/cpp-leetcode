#include <iostream>
using namespace std;

class User{

private:

    string password;
    int ID;

public:
    string username;

    //Constructor
    User(int ID){
        
        // "this" is a special ptr that points
        // to the current obj. It is basically
        // doing *(this).ID

        this->ID = ID;
    }

    //Getter

    string getPassword(){

        return password;
    }

    //Setter

    void setPassword(string password){

        this->password = password;
    }

};

int main(){

    User u1(1);
    u1.username = "hiteshrii";
    u1.setPassword("password");
    cout << u1.getPassword() << endl;
}
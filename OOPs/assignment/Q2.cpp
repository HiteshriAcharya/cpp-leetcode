#include <iostream>
using namespace std;

class BankAccount{

private:
    int accountNumber;
    double balance;

public:

    BankAccount(int accountNumber, double balance){
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(double depositAmount){

        balance += depositAmount;
    }

    void withdraw(double withdrawAmount){

        if(withdrawAmount <= balance){

            balance -= withdrawAmount;
        } else {

            cout << "Enable to withdraw. Insufficient funds";
        }
    }

    double getBalance(){

        return balance;
    }
};

int main(){

    BankAccount b1(1, 1000);

    b1.deposit(0.50);
    cout << "Your balance is: $" << b1.getBalance() << endl;

    b1.withdraw(500);
    cout << "Your balance is: $" << b1.getBalance() << endl;
}
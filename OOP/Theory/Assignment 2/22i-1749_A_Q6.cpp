/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include<iostream>
using namespace std;
class Account{          //class
private:
    float balance;
public:             //member funs
    Account(float=0);
    void deposit(float);
    bool withdraw(float);
    float inquire();

};

Account::Account(float a){  //constructer
    this->balance = a;
}
void Account::deposit(float a){     //deposit
    this->balance += a;
}
bool Account::withdraw(float a){        //withdraw
    if(a > balance){
        cout<<"You cant withdraw more money then you have, so we charge you 5 dollars penalty"<<endl;
        this->balance -= 5;
        return false;
    }else{
        this->balance -=a;
        return true;
    }
}
float Account::inquire(){           //balance chekc
    return balance;
}
int main(){
    Account A1;
    cout<<A1.inquire()<<endl;
    A1.deposit(50);
    A1.withdraw(51);
    cout<<A1.inquire()<<endl;
    A1.withdraw(5);
    cout<<A1.inquire()<<endl;
return 0;
}

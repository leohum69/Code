#include "Employee.h"

    Employee::Employee(string na,string ro){
        this->name = na;
        this->role = ro;
    }
    void Employee::Dowork(){
        cout<<"The Employee is Doig its Task"<<endl;
        if(rand()%2)
            cout<<"Work Done!"<<endl;
        else
            cout<<"Work Failed :("<<endl;
    }
    string Employee::get_na(){
        return this->name;
    }
    string Employee::get_ro(){
        return this->role;
    }
    Employee::~Employee(){

    }
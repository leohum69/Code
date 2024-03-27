/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include <iostream>
using namespace std;
class Employee{             //class
private:
    char *name;
    double salary;
public:                     //member functions
    Employee(char * =NULL,double = 0);
    char* getName() const;
    double getSalary() const;
    ~Employee();
};

Employee::Employee(char* n,double s){           //constructer
    this->name = n;
    this->salary = s;
    cout<<"New employee has been created."<<endl;
}
char * Employee::getName() const{       //getter
    return name;
}
double Employee::getSalary() const{     //getter
    return salary;
}
Employee::~Employee(){                  //destrtuctor
    delete []name;
    cout<<"Thank you for testing Class Employee."<<endl;
}

int main(){
    char * n=new char[100];
    double s=0;
    cout<<"Creating a new employee."<<endl;
    cout<<"Please type the name: ";
    cin.get(n,100);
    cin.ignore();
    cout<<"Please specify the salary: ";
    cin>>s;
    while(s<0){
        cout<<"Error"<<endl;
        cin>>s;
    }
    Employee E1(n,s);
    cout<<"Name of employee: "<<E1.getName()<<endl;
    cout<<"Salary: "<<E1.getSalary()<<endl;



return 0;
}

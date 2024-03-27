/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include<iostream>
using namespace std;
class Employee2{            //class
private:
    char * name;
    float HourlyWage;
    float WorkedHours;
    float ExtraHours;
public:             //member funs
    Employee2();
    float wageCalculator();
};
Employee2::Employee2(){             //cosntructer
    this->name = new char[100];
}
float Employee2::wageCalculator(){              //wage cal
    cout<<"Please enter employee's name then press Enter : ";
    cin.get(name,100);
    cin.ignore();
    cout<<"Please enter hourly wage then press Enter : ";
    cin>>HourlyWage;
    while(HourlyWage <= 0){
        cout<<"Error, Enter again: ";
        cin>>HourlyWage;
    }
    cout<<"Please enter hours worked then press Enter : ";
    cin>>WorkedHours;
    while(WorkedHours <= 0){
        cout<<"Error, Enter again: ";
        cin>>WorkedHours;
    }
    float temp = WorkedHours;
    ExtraHours=0;
    if(WorkedHours >40){
        ExtraHours = WorkedHours - 40;
        WorkedHours = 40;
    }
    float total=0;
    total += (WorkedHours * HourlyWage);
    total += (ExtraHours * 1.5 * HourlyWage);
    cout<<"Paycheck for employee "<<name<<endl;
    cout<<"Hours worked: "<< temp<<endl;
    cout<<"Hourly wage: "<<HourlyWage<<endl;
    if(temp > 40){
        cout<<"Overtime hours: "<<ExtraHours<<endl;
        cout<<"Overtime hourly wage: "<<(1.5 * HourlyWage)<<endl;
    }
    return total;
}

int main(){
    Employee2 E1;
    float total = E1.wageCalculator();
    cout<<"\nTotal Payment : "<<total<<endl;


return 0;
}

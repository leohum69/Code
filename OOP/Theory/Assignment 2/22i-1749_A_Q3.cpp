/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include<iostream>
using namespace std;
class FlightInfo{           //class
private:
    int FlightNumber;
    char* Destination;
    float Distance;
    float fuel;
    void calFuel();
public:                 //member funs
    FlightInfo();
    void feedInfo();
    void showInfo() const;
    float getFuel() const;
    ~FlightInfo();
};

FlightInfo::FlightInfo(){       //constructer
    this->Destination = new char[100];
}
void FlightInfo::calFuel(){             //fuel calculate
    if(this->Distance <= 1000){
        this->fuel = 500;
    }else if(this->Distance > 1000 && Distance <= 2000){
        this->fuel = 1100;
    }else if(this->Distance > 2000){
       this->fuel = 2200;
    }
}
void FlightInfo::feedInfo(){        //info feed
    cout<<"Enter Flight Number: ";
    cin>>FlightNumber;
    while(FlightNumber <= 0){
        cout<<"Error, Enter again: ";
        cin>>FlightNumber;
    }
    cout<<"Enter Destination: ";
    cin.ignore();
    cin.get(Destination,100);
    cout<<"Enter Distance: ";
    cin>>Distance;
    while(Distance <= 0){
        cout<<"Error, Enter again: ";
        cin>>Distance;
    }
    calFuel();
}
void FlightInfo::showInfo() const{          //print
    cout<<"FlightNumber : "<<FlightNumber<<endl;
    cout<<"Destination : "<<Destination<<endl;
    cout<<"Distance : "<<Distance<<endl;
    cout<<"Fuel : "<<fuel<<endl;
}
float FlightInfo::getFuel() const{          //fuel getter
    return fuel;
}
FlightInfo::~FlightInfo(){              //destructor
    delete []Destination;
}
int main(){
    FlightInfo f1;
    f1.feedInfo();
    cout<<"fuel"<<f1.getFuel()<<endl;
    f1.showInfo();


return 0;
}

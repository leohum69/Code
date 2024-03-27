/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include<iostream>
using namespace std;
class Car{          //class
private:
    float fuel;
    float effie;
public:         //member functions
    Car(float);
    void drive(float);
    void tank(float);
    float getFuelLevel();
};
Car::Car(float a){          //constructer
    this->fuel=0;
    this->effie=a;
}
void Car::tank(float a){        //for fueling
    this->fuel += a;
}
float Car::getFuelLevel(){      //fuel getter
    return fuel;
}
void Car::drive(float a){       //drive function
    float ez=0;
    ez = a / effie;
    this->fuel -= ez;
}

int main(){
    Car myBeemer(29);
 cout<<myBeemer.getFuelLevel()<<endl;
 myBeemer.tank(20);
 cout<<myBeemer.getFuelLevel()<<endl;
 myBeemer.drive(100);
 cout<< myBeemer.getFuelLevel()<<endl;
return 0;
}

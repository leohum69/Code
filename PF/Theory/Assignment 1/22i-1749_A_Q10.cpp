/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)
*/
#include <iostream>
using namespace std;

int main(){

    const float ONDEMAND_COST=3,RESERVED_COST=2,SPOT_COST=0.5;      //Declaration of constants
    float ondemand_num,reserved_num,spot_num;                       //Declaration of variables
    float ondemand,reserved,spot;
    int monthly_time = 30*24;           //hours in month = total hours in month * hours in a day

    cout<<"How many On-demand machines you own: ";
    cin>>ondemand_num;
    cout<<"How many Reserved machines you own: ";
    cin>>reserved_num;
    cout<<"How many Spot machines your own: ";      //Taking values
    cin>>spot_num;

    ondemand = ondemand_num * ONDEMAND_COST * monthly_time;
    reserved= reserved_num * RESERVED_COST * monthly_time;
    spot= spot_num * SPOT_COST * monthly_time;              //just multiplying
    cout<<endl;
    cout<<"Cost of On-demand instances: $"<<ondemand<<endl;
    cout<<"Cost of Reserved instances: $"<<reserved<<endl;
    cout<<"Cost of Spot instances: $"<<spot<<endl;

    cout<<endl;

    cout<<"Total Monthly Cost of AWS Machines: $"<<( ondemand + reserved + spot )<<endl;     //Displaying values





return 0;
}

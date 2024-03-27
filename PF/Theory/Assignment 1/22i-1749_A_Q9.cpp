/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)
*/
#include <iostream>

using namespace std;

int main (){

    const float OMG_MARGIN=3.68,DEALER=7.00,IFEM=4.76;      //declaration of constants
    float pet_levy_perc,cos,sales_tax_perc,pet_levy,sales_tax;      //declaration of variables
    float finals;

    cout<<"Enter MOGAS PSO Weighted Average cost of supply: ";
    cin>>cos;
    cout<<"Enter Petroleum Levy: ";
    cin>>pet_levy_perc;
    cout<<"Sales Tax %: ";
    cin>>sales_tax_perc;

    pet_levy= (pet_levy_perc * cos)/100;

    sales_tax= (sales_tax_perc * cos)/100;


    finals= cos + IFEM + OMG_MARGIN + DEALER + pet_levy + sales_tax;        //just calculating the values :3

    cout<<"Max Ex-Depot Sale Price = "<<finals<<endl;











return 0;
}

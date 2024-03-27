/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)

*/

#include <iostream>

using namespace std;

int main()
{
   int x,thir,twfou,eigh,twe,six,temp; //Declaration of variables


   cout<<"Enter numbers: ";
   cin>>x;                             //Taking value in variable

   thir=x/30;
   twfou=(x-(thir*30))/24;
   eigh=(x-(thir*30)-(twfou*24))/18;
   twe=(x-(thir*30)-(twfou*24)-(eigh*18))/12;
   six=(x-(thir*30)-(twfou*24)-(eigh*18)-(twe*12))/6;
   temp=(x-(thir*30)-(twfou*24)-(eigh*18)-(twe*12)-(six*6)); //Distributing value in variables

   cout<<"Thirty Package: "<<thir<<endl;
   cout<<"Twenty-four Package : "<<twfou<<endl;
   cout<<"eighteen Package : "<<eigh<<endl;
   cout<<"twelve Package : "<<twe<<endl;
   cout<<"six Package : "<<six<<endl;
   cout<<"remain Package: "<<temp<<endl; //Displaying Values



    return 0;
}

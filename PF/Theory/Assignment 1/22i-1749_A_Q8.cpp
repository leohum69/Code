/*
Name: Mirza Humayun Masood
Roll No: I22-1749
Class: BS-CY(A)
*/
#include<iostream>
using namespace std;

int main(){

    string name;
    int roll;
    string clas;

    const int IICT_CH=1,PF_CH=4,LA_CH=3,CAL_CH=3,PS_CH=3,ENG_CH=3; // declarations of credit hours and variables
    int iict_marks,pf_marks,la_marks,cal_marks,ps_marks,eng_marks;
    const int OOP_CH=4,DLD_CH=4,DE_CH=3,IS_CH=3,CPS_CH=3;
    int oop_marks,dld_marks,de_marks,is_marks,cps_marks;
    int first,second,both;
    int gpa;





    cout<<"Enter your Name: ";              //taking input
    cin>>name;
    cout<<"Enter your Roll Number: I22-";
    cin>>roll;
    cout<<"Enter your class: ";
    cin>>clas;

    cout<<"Enter marks of First semester subjects."<<endl<<endl;        //first semester

    cout<<"Enter your marks in grade points in IICT: ";             //taking marks in grade points
    cin>>iict_marks;
    cout<<"Enter your marks in in grade points Programming Fundamentals: ";
    cin>>pf_marks;
    cout<<"Enter your marks in grade points in Linear Algebra: ";
    cin>>la_marks;
    cout<<"Enter your marks in grade points in Calculus: ";
    cin>>cal_marks;
    cout<<"Enter your marks in grade points in Pak Studies: ";
    cin>>ps_marks;
    cout<<"Enter your marks in grade points in English: ";
    cin>>eng_marks;

    cout<<endl;

    cout<<"Enter marks of Second semester subjects."<<endl<<endl;       //second semester

    cout<<"Enter your marks in grade points in  Object Oriented Programming: ";
    cin>>oop_marks;
    cout<<"Enter your marks in grade points in Digital Logic Design: ";
    cin>>dld_marks;
    cout<<"Enter your marks in grade points in Differential Equations: ";
    cin>>de_marks;
    cout<<"Enter your marks in grade points in Islamiat Studies: ";
    cin>>is_marks;
    cout<<"Enter your marks in grade points in Communication and Presentation Skills: ";
    cin>>cps_marks;

    cout<<endl;         //calculations



    first= ((iict_marks * IICT_CH) + (pf_marks * PF_CH) + (cal_marks * CAL_CH) + (la_marks * LA_CH) + (ps_marks * PS_CH) + (eng_marks * ENG_CH) )/(IICT_CH + PF_CH + CAL_CH + LA_CH + PS_CH + ENG_CH);

    second = ((oop_marks * OOP_CH) + (dld_marks * DLD_CH) + (de_marks * DE_CH) + (is_marks * IS_CH) + (cps_marks * CPS_CH))/(OOP_CH + DLD_CH + DE_CH + IS_CH + CPS_CH);

   both =  ((iict_marks * IICT_CH) + (pf_marks * PF_CH) + (cal_marks * CAL_CH) + (la_marks * LA_CH) + (ps_marks * PS_CH) + (eng_marks * ENG_CH) + (oop_marks * OOP_CH) + (dld_marks * DLD_CH) + (de_marks * DE_CH) + (is_marks * IS_CH) + (cps_marks * CPS_CH))/(IICT_CH + PF_CH + CAL_CH + LA_CH + PS_CH + ENG_CH + OOP_CH + DLD_CH + DE_CH + IS_CH + CPS_CH);



    cout<<"Semester GPA of First Semester: "<<first<<endl<<endl;
    cout<<"Semester GPA of Second Semester: "<<second<<endl<<endl;

    cout<<"Total CGPA: "<<both<<endl;




return 0;
}

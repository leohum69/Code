/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include<iostream>
#include <cstring>
#include"iots.cpp"
#include"doctor.cpp"
#include"patient.cpp"
#include"RMC2.cpp"
#include"EHR.cpp"
#include <fstream>
using namespace std;
//{1,2,1,3,1,2,1,1,2,3}
void Patientstuff(patient *p,doctor *d);
void Doctorstuff(rmc2 &r);
int main(){
    srand(time(0));
    int arrays[10][3]={{0,-1,-1},{2,1,-1},{4,-1,-1},{4,3,2},{1,-1,-1},{2,1,-1},{1,-1,-1},{1,-1,-1},{3,2,-1},{4,3,2}};
    patient temp2;
    patient parr[10];
    doctor darr[5];
    doctor temp;
    ifstream ifile("E:\\fast\\oop\\proj\\files\\docs.dat",ios::binary);
    for(int i=0 ; i < 5 ;i++){
        ifile.read((char *)&temp, sizeof(temp));
        darr[i] = temp;
    }
    ifile.close();
    ifstream isfile("E:\\fast\\oop\\proj\\files\\patient.dat",ios::binary);
    for(int i=0 ; i < 10 ;i++){
        isfile.read((char *)&temp2, sizeof(temp2));
        parr[i] = temp2;
    }
    isfile.close();

    for(int i=0 ; i < 10 ; i++){
        parr[i].setdocs(darr);
        parr[i].decrypt();
    }
    rmc2 r1(darr,parr);
    bool run = true;
    int choice = 69;
    do{
    cout<<"Welcome To Our App!"<<endl;
    cout<<endl;
    cout<<"1 - Patient Menu"<<endl;
    cout<<"2 - Doctor Menu"<<endl;
    cout<<"3 - Exit."<<endl;
    cin>>choice;
    while(choice > 3 || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    switch(choice){
        case 1:
            Patientstuff(parr,darr);
        break;
        case 2:
            Doctorstuff(r1);
        break;
        case 3:
            run = false;
        break;
    }
    }while(run);
    return 0;

}
void Patientstuff(patient *p,doctor *d){
    bool go = true;
    char name[30];
    char pass[30];
    int idx = -1;
    bool yes = false;
    char chk;
    int choice;
    bool akhri = true;
    cin.ignore();
    do{
    cout<<"Enter Name: ";
    cin.getline(name,30);
    for(int i=0; i<10;i++){
        if(strcmp(name , p[i].getname()) == 0)
            {idx = i;}
    }
    if(idx != -1){
        cout<<"Enter Password: ";
        cin.getline(pass,30);
        if(strcmp(pass , p[idx].getpass())==0){
            yes = true;
        }
    }
    if(yes != true || idx == -1){
        cout<<"Invalid Credeintials Entered"<<endl;
        cout<<"Do you want to Enter again ?"<<endl;
        chk = cin.get();
        if(chk == 'y' || chk == 'Y'){
            idx = -1;
            yes == false;
            cin.ignore();
            continue;
        }else{
            go = false;
        }
    }else{
        do{
        cout<<"Enter Choice: "<<endl;
        cout<<"1 - Set appointment with your Doctors"<<endl;
        cout<<"2 - Search For a new Doctor"<<endl;
        cout<<"3 - View You IOT"<<endl;
        cout<<"4 - View Your EHR"<<endl;
        cout<<"5 - View The Requests"<<endl;
        cout<<"6 - Make Call"<<endl;
        cout<<"7 - Exit"<<endl;
        cin>>choice;
        while(choice > 7 || choice < 1){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice;
        }
        switch(choice){
        case 1:
            p[idx].setapt();
        break;
        case 2:
            p[idx].addnewdocplz(d);
        break;
        case 3:
            p[idx].getiot().print();
            for(int i=0 ; i<10;i++){
                p[i].getiot().Update();
            }
        break;
        case 4:
            p[idx].viewehr();
        break;
        case 5:
            p[idx].chkreqs(d);
        break;
        case 6:
            p[idx].call();
        break;
        case 7:
            akhri = false;
            go = false;
        break;
        }
        }while(akhri);
    }
    }while(go);
}
void Doctorstuff(rmc2 &r){
    bool go = true;
    char name[30];
    char pass[30];
    int idx = -1;
    bool yes = false;
    char chk;
    int choice;
    bool akhri = true;
    cin.ignore();
    do{
    cout<<"Enter Name: ";
    cin.getline(name,30);
    for(int i=0; i<10;i++){
        if(strcmp(name , r.getdoc()[i].getname()) == 0)
            {idx = i;}
    }
    if(idx != -1){
        cout<<"Enter Password: ";
        cin.getline(pass,30);
        if(strcmp(pass , r.getdoc()[idx].getpass())==0){
            yes = true;
        }
    }
    if(yes != true || idx == -1){
        cout<<"Invalid Credeintials Entered"<<endl;
        cout<<"Do you want to Enter again ?"<<endl;
        chk = cin.get();
        if(chk == 'y' || chk == 'Y'){
            idx = -1;
            yes == false;
            cin.ignore();
            continue;
        }else{
            go = false;
        }
    }else{
        do{
        cout<<"Enter Choice: "<<endl;
        cout<<"1 - Check Appointment Requests"<<endl;
        cout<<"2 - View Previous Consultations of Patients"<<endl;
        cout<<"3 - Search for Some Specific things of Patient"<<endl;
        cout<<"4 - Request for Edit"<<endl;
        cout<<"5 - Edit Patient EHR"<<endl;
        cout<<"6 - See IOT data Of Patients"<<endl;
        cout<<"7 - Exit"<<endl;
        cin>>choice;
        while(choice > 7 || choice < 1){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice;
        }
        switch(choice){
        case 1:
            r.apointchk(idx);
        break;
        case 2:
            r.chkcnslthist(idx);
        break;
        case 3:
            r.randomdata(idx);
        break;
        case 4:
            r.Requestfordata(idx);
        break;
        case 5:
            r.editehr(idx);
        break;
        case 6:
            r.chkiot(idx);
        break;
        case 7:
            akhri = false;
            go = false;
        break;
        }
        }while(akhri);
    }
    }while(go);
}

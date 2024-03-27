/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include "RMC2.h"

rmc2::rmc2(doctor* d,patient* p){
    this->docs = d;
    this->pats = p;
}
rmc2::~rmc2(){

}
void rmc2::apointchk(int docidx){
    int *arr;
    int choice,choice2;
    int j=0;
    int k=1;
    for(int i=0 ; i < 10 ; i++){
        cout<<this->docs[docidx].senreqdoc()[i]<<" ";
        if(this->docs[docidx].senreqdoc()[i] == 1 ){
            j++;
        }
    }
    if(j == 0){
        cout<<"No Requests Found :D."<<endl;
    }else{
        arr = new int[j];
        cout<<"Appointments Requests are given Below"<<endl;
        for(int i=0 ; i < 10;i++){
            if(this->docs[docidx].senreqdoc()[i] == 1){
                cout<<k<<" - "<<this->pats[i].getname()<<", age = "<<this->pats[i].getage()<<endl;
                arr[k-1] = this->pats[i].getid();
                k++;
            }
        }
        cout<<"Select the Patient to Approve or Reject : ";
        cin>>choice;
        while(choice > k-1 || choice < 1){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice;
        }
        cout<<"1 - Approve"<<endl;
        cout<<"2 - Reject"<<endl;
        cin>>choice2;
        while((choice2 < 1) || (choice2 > 2)){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice2;
        }
        if(choice2 == 1)
            this->docs[docidx].senreqdoc()[choice - 1] = 2;
        else
            this->docs[docidx].senreqdoc()[choice - 1] = 0;
    }
}
doctor* rmc2::getdoc(){
    return this->docs;
}
void rmc2::chkcnslthist(int docidx){
    int choice;
    cout<<"Available Doctors"<<endl;
    for(int i=0 ; i < 10 ; i++){
        cout<<i+1<<" - "<<this->pats[i].getname()<<", age = "<<this->pats[i].getage()<<endl;
    }
    cin>>choice;
    while(choice > 10 || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    cout<<"The Previous Consulation History from respective Doctor is Given: "<<endl;
    for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++)
        cout<<this->pats[choice-1].getehr()[i].getConsult()<<"\t"<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
}
void rmc2::randomdata(int docidx){
    int choice,choice2;
    cout<<"Available Doctors"<<endl;
    for(int i=0 ; i < 10 ; i++){
        cout<<i+1<<" - "<<this->pats[i].getname()<<", age = "<<this->pats[i].getage()<<endl;
    }
    cin>>choice;
    while(choice > 10 || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    cout<<"What You want to See in Patient:"<<endl;
    cout<<"1 - Consultations"<<endl;
    cout<<"2 - Prescription"<<endl;
    cout<<"3 - Recommendation"<<endl;
    cout<<"4 - Diet"<<endl;
    cout<<"5 - Allergies"<<endl;
    cout<<"6 - Regular Medication"<<endl;
    cout<<"7 - Chronic Disease"<<endl;
    cout<<"8 - Previous Appointments Made with Doctor"<<endl;
    cout<<"9 - See All"<<endl;
    cin>>choice2;
    while(choice2 > 9 || choice2 < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice2;
    }
    switch(choice2){
        case 1:
            for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++)
                cout<<this->pats[choice-1].getehr()[i].getConsult()<<"\t"<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
        break;
        case 2:
            for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++)
                cout<<this->pats[choice-1].getehr()[i].getPrescription()<<"\t"<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
        break;
        case 3:
            for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++)
                cout<<this->pats[choice-1].getehr()[i].getRecommendation()<<"\t"<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
        break;
        case 4:
            for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++)
                cout<<this->pats[choice-1].getehr()[i].getDietry()<<"\t"<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
        break;
        case 5:
            for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++)
                cout<<this->pats[choice-1].getehr()[i].getAllergy()<<"\t"<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
        break;
        case 6:
            for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++)
                cout<<this->pats[choice-1].getehr()[i].getRegu_med()<<"\t"<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
        break;
        case 7:
            for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++)
                cout<<this->pats[choice-1].getehr()[i].getChron()<<"\t"<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
        break;
        case 8:
            for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++){
                cout<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
                this->pats[choice-1].getehr()[i].viewapoints();
            }
        break;
        case 9:
            for(int i=0 ; i < this->pats[choice-1].getnumberofdocs();i++){
                cout<<"Doc Name = "<<this->pats[choice-1].getehr()[i].getname()<<endl;
                this->pats[choice-1].getehr()[i].display();
                cout<<endl;
            }
        break;
    }
}
void rmc2::Requestfordata(int docidx){
    int choice;
    cout<<"Available Patients"<<endl;
    for(int i=0 ; i < 10 ; i++){
        cout<<i+1<<" - "<<this->pats[i].getname()<<", age = "<<this->pats[i].getage()<<endl;
    }
    cin>>choice;
    while(choice > 10 || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    if(this->pats[choice-1].getrewaliarr()[docidx] != 1){
        this->pats[choice-1].getrewaliarr()[docidx] = 1;
        cout<<"Request Sent Successfully"<<endl;
    }else{
        cout<<"Edit Request is Already Made, wait For Response..."<<endl<<endl;
    }
}
void rmc2::editehr(int docidx){
    bool chk = false;
int choice,choice2,choice3,choice4;
    char dat[256];
    cout<<"Available Patients"<<endl;
    for(int i=0 ; i < 10 ; i++){
        cout<<i+1<<" - "<<this->pats[i].getname()<<", age = "<<this->pats[i].getage()<<endl;
    }
    cin>>choice;
    while(choice > 10 || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    if(this->pats[choice-1].getrewaliarr()[docidx] == 2)
        chk = true;
    if(chk){
        cout<<"What You want to Add in Patient:"<<endl;
        cout<<"1 - Consultations"<<endl;
        cout<<"2 - Prescription"<<endl;
        cout<<"3 - Recommendation"<<endl;
        cout<<"4 - Diet"<<endl;
        cout<<"5 - Allergies"<<endl;
        cout<<"6 - Regular Medication"<<endl;
        cout<<"7 - Chronic Disease"<<endl;
        cin>>choice2;
        while(choice2 > 7 || choice2 < 1){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice2;
        }
        cout<<"Which Doctor's Respective Ehr you want to Upgrade?"<<endl;
        for(int i=0; i < this->pats[choice-1].getnumberofdocs() ; i++){
            cout<<i+1<<" - "<<this->pats[choice-1].getdocarr()[i]->getname()<<", Doctor of "<<this->pats[choice-1].getdocarr()[i]->getspec()<<endl;
        }
        cin>>choice3;
        while(choice3 > this->pats[choice-1].getnumberofdocs() || choice3 < 1){
            cout<<"Invalid Input"<<endl;
            cout<<"Enter Again : ";
            cin>>choice3;
        }
        switch(choice2){
            case 1:
                cin.ignore();
                cout<<"Add Consultation : ";
                cin.getline(dat,256);
                this->pats[choice-1].getehr()[choice3-1].updateConsult(dat);
            break;
            case 2:
                cin.ignore();
                cout<<"Add Prescription : ";
                cin.getline(dat,256);
                this->pats[choice-1].getehr()[choice3-1].updatePrescription(dat);

            break;
            case 3:
                cin.ignore();
                cout<<"Add Recommendation : ";
                cin.getline(dat,256);
                this->pats[choice-1].getehr()[choice3-1].updateRecommendation(dat);
            break;
            case 4:
                cin.ignore();
                cout<<"Add Diet : ";
                cin.getline(dat,256);
                this->pats[choice-1].getehr()[choice3-1].updateDietry(dat);
            break;
            case 5:
                cin.ignore();
                cout<<"Add Allergies : ";
                cin.getline(dat,256);
                this->pats[choice-1].getehr()[choice3-1].updateAllergy(dat);
            break;
            case 6:
                cin.ignore();
                cout<<"Add Regular Medication : ";
                cin.getline(dat,256);
                this->pats[choice-1].getehr()[choice3-1].updateReguMed(dat);
            break;
            case 7:
                cin.ignore();
                cout<<"Add Chronic Disease : ";
                cin.getline(dat,256);
                this->pats[choice-1].getehr()[choice3-1].updateChron(dat);
            break;
        }
        this->pats[choice-1].encrypt();
        this->pats[choice-1].getehr()->writeehr(pats[choice-1].getehr(),pats[choice-1].getehrpath(),pats[choice-1].getnumberofdocs());
        this->pats[choice-1].decrypt();
    }else{
        cout<<"Not Accessed..."<<endl;
    }
}
void rmc2::chkiot(int docidx){
    int choice;
    cout<<"Available Patients"<<endl;
    for(int i=0 ; i < 10 ; i++){
        cout<<i+1<<" - "<<this->pats[i].getname()<<", age = "<<this->pats[i].getage()<<endl;
    }
    cin>>choice;
    while(choice > 10 || choice < 1){
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Again : ";
        cin>>choice;
    }
    this->pats[choice-1].getiot().print();
    for(int i=0 ; i<10;i++){
        this->pats[i].getiot().Update();
    }
}


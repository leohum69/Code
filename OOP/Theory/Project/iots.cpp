/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include "iots.h"

IOTS::IOTS(char na[],float temp,float sug,int pul,float bmi,int os, int ubp,int lbp){
    this->tempreture = temp;
    this->sugar = sug;
    this->pulse = pul;
    this->BMI = bmi;
    this->oxy_sat = os;
    this->BP[0] = ubp;
    this->BP[1] = lbp;
    int i=0;
    while(na[i]!='\0'){
        this->name[i] = na[i];
        i++;
    }
    this->name[i] = '\0';
}
IOTS::~IOTS(){

}
void IOTS::Update(){
    float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3));
    int ve = rand() % 2;
    if(ve)
        this->tempreture += x;
    else
        this->tempreture -= x;
    x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3));
    ve = rand() % 2;
    if(ve)
        this->sugar += x;
    else
        this->sugar -= x;
    x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2));
    ve = rand() % 2;
    if(ve)
        this->BMI += x;
    else
        this->BMI -= x;
    x = rand() % 5;
    ve = rand() % 2;
    if(ve)
        this->pulse += x;
    else
        this->pulse -= x;
    x = rand() % 3;
    ve = rand() % 2;
    if(ve)
        this->BP[0] += x;
    else
        this->BP[0] -= x;
    x = rand() % 3;

    ve = rand() % 2;
    if(ve)
        this->BP[1] += x;
    else
        this->BP[1] -= x;

    IOTS temp;
    temp = *this;
    ofstream ofile("iots.dat",ios::binary | ios::app);
    ofile.write((char *)&temp, sizeof(temp));
    ofile.close();

}
IOTS& IOTS::Update2(){
    IOTS* temper = new IOTS;
    int i=0;
    while(this->name[i]!='\0'){
         (*temper).name[i] = this->name[i];
        i++;
    }
    (*temper).name[i] = '\0';
    float x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3));
    int ve = rand() % 2;
    if(ve)
        (*temper).tempreture += x;
    else
        (*temper).tempreture -= x;
    x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/3));
    ve = rand() % 2;
    if(ve)
        (*temper).sugar += x;
    else
        (*temper).sugar -= x;
    x = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/2));
    ve = rand() % 2;
    if(ve)
        (*temper).BMI += x;
    else
        (*temper).BMI -= x;
    x = rand() % 5;
    ve = rand() % 2;
    if(ve)
        (*temper).pulse += x;
    else
        (*temper).pulse -= x;
    x = rand() % 3;
    ve = rand() % 2;
    if(ve)
        (*temper).BP[0] += x;
    else
        (*temper).BP[0] -= x;
    x = rand() % 3;

    ve = rand() % 2;
    if(ve)
        (*temper).BP[1] += x;
    else
        (*temper).BP[1] -= x;

    return *temper;

}
void IOTS::operator=(IOTS& is){
    this->BMI = is.BMI;
    this->BP[0] = is.BP[0];
    this->BP[1] = is.BP[1];
    this->oxy_sat = is.oxy_sat;
    this->pulse = is.pulse;
    this->sugar = is.sugar;
    this->tempreture = is.tempreture;
    int i=0;
    while(is.name[i]!='\0'){
        this->name[i] = is.name[i];
        i++;
    }
    this->name[i] = '\0';
}
void IOTS::readiot(char fp[]){
    IOTS temp;
    ifstream ifile(fp,ios::binary);
    while(!ifile.eof()){
        ifile.read((char *)&temp, sizeof(temp));
    }
    ifile.close();
    *this = temp;
}
void IOTS::setname(char n[]){
    int i=0;
    while(n[i]!='\0'){
        this->name[i] = n[i];
        i++;
    }
    this->name[i] = '\0';
}
float IOTS::gettemp(){
    return tempreture;
}
float IOTS::getsug(){
    return sugar;
}
int IOTS::getpul(){
    return pulse;
}
float IOTS::getbmi(){
    return BMI;
}
int IOTS::getos(){
    return oxy_sat;
}
int IOTS::getubp(){
    return BP[0];
}
int IOTS::getlbp(){
    return BP[1];
}
void IOTS::print(){
    cout<<"Temperature : "<<this->tempreture<<endl;
    cout<<"Sugar Level : "<<this->sugar<<endl;
    cout<<"Pulse : "<<this->pulse<<endl;
    cout<<"BMI : "<<this->BMI<<endl;
    cout<<"Oxygen Saturation : "<<this->oxy_sat<<endl;
    cout<<"BP "<<this->BP[0]<<" / "<<this->BP[1]<<endl;
}




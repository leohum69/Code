#include <iostream>

    Costumer::Costumer(string name){
        this->c_name=name;
        this->bill = 0;
        this->branch = '\0';
    }

    Costumer::~Costumer(){

    }
    void Costumer::setcname(string y){
        this->c_name = y;
    }
    string Costumer::getcname(){
        return this->c_name;
    }
    void Costumer::setbill(int x){
        this->bill = x;
    }
    void Costumer::setbranch(string p){
        this->branch = p;
    }
    int Costumer::getbill(){
        return this->bill;
    }
    string Costumer::getbranch(){
        return this->branch;
    }

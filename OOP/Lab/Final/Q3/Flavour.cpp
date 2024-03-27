#include "Flavour.h"

    Flavour::Flavour(string na,int s,int m,int h){
        this->name =  na;
        this->price_s = s;
        this->price_m = m;
        this->price_h = h;
    }
    void Flavour::set_na(string na){
        this->name =  na;
    }
    void Flavour::set_s(int s){
        this->price_s = s;
    }
    void Flavour::set_m(int m){
        this->price_m = m;
    }
    void Flavour::set_h(int h){
        this->price_h = h;
    }
    int Flavour::get_s(){
        return this->price_s;
    }
    int Flavour::get_m(){
        return this->price_m;
    }
    int Flavour::get_h(){
        return this->price_h;
    }
    string Flavour::get_name(){
        return this->name;
    }
    Flavour::~Flavour(){

    }
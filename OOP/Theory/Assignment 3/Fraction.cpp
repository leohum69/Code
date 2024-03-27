/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include <iostream>
#include "Fraction.h"
using namespace std;


Fraction::Fraction(){   // cnstrcter
    this->numer = 0;
    this->denomer = 1;
}
Fraction::Fraction(int num){
    this->numer = num;
    this->denomer = 1;
}
Fraction::Fraction(int num, int denum){
    this->numer = num;
    this->denomer = denum;
    if(this->denomer < 0){
        this->denomer = this->denomer * -1;
        this->numer = this->numer * -1;
    }
    int x;
    if(this->numer > 0)
        x = gcd(this->numer , this->denomer);
    else
        x = gcd((this->numer*-1) , this->denomer);
    this->numer = this->numer / x;
    this->denomer = this->denomer / x;
}
Fraction::Fraction(const Fraction& obj){
    this->numer = obj.numer;
    this->denomer = obj.denomer;
}
int Fraction::getNumerator() const{     //getters
    return this->numer;
}
int Fraction::getDenominator() const{
    return this->denomer;
}
void Fraction::display() const{         //display
    cout<<this->numer <<" / "<<this->denomer<<endl;
}
Fraction Fraction::operator+(const Fraction& obj){          //arthemetic operator
    Fraction temp;
    int n,d,gc;
    n = (this->numer * obj.denomer) + (obj.numer * this->denomer);
    d = this->denomer * obj.denomer;
    if(n > 0)
        gc = gcd(n , d);
    else
        gc = gcd(-n , d);
    n = n/gc;
    d = d/gc;
    temp.numer = n;
    temp.denomer = d;
    return temp;
}
Fraction Fraction::operator-(const Fraction& obj){
    Fraction temp;
    int n,d,gc;
    n = (this->numer * obj.denomer) - (obj.numer * this->denomer);
    d = this->denomer * obj.denomer;
    if(n > 0)
        gc = gcd(n , d);
    else
        gc = gcd(-n , d);
    n = n/gc;
    d = d/gc;
    temp.numer = n;
    temp.denomer = d;
    return temp;
}
Fraction Fraction::operator*(const Fraction& obj){
    Fraction temp;
    temp.numer = this->numer * obj.numer;
    temp.denomer = this->denomer * obj.denomer;
    int gc;
     if(temp.numer > 0)
        gc = gcd(temp.numer , temp.denomer);
    else
        gc = gcd(-temp.numer , temp.denomer);
    temp.numer = temp.numer/gc;
    temp.denomer = temp.denomer/gc;
    return temp;
}
Fraction Fraction::operator/(const Fraction& obj){
    Fraction temp;
    temp.numer = this->numer * obj.denomer;
    temp.denomer = this->denomer * obj.numer;
    int gc;
     if(temp.numer > 0)
        gc = gcd(temp.numer , temp.denomer);
    else
        gc = gcd(-temp.numer , temp.denomer);
    temp.numer = temp.numer/gc;
    temp.denomer = temp.denomer/gc;
    return temp;
}
Fraction& Fraction::operator+=(const Fraction& obj){
    int n,d,gc;
    n = (this->numer * obj.denomer) + (obj.numer * this->denomer);
    d = this->denomer * obj.denomer;
    if(n > 0)
        gc = gcd(n , d);
    else
        gc = gcd(-n , d);
    n = n/gc;
    d = d/gc;
    this->numer = n;
    this->denomer = d;
    return *this;
}
Fraction& Fraction::operator-=(const Fraction& obj){
    int n,d,gc;
    n = (this->numer * obj.denomer) - (obj.numer * this->denomer);
    d = this->denomer * obj.denomer;
    if(n > 0)
        gc = gcd(n , d);
    else
        gc = gcd(-n , d);
    n = n/gc;
    d = d/gc;
    this->numer = n;
    this->denomer = d;
    return *this;
}
Fraction& Fraction::operator*=(const Fraction& obj){
    this->numer = this->numer * obj.numer;
    this->denomer = this->denomer * obj.denomer;
    int gc;
     if(this->numer > 0)
        gc = gcd(this->numer , this->denomer);
    else
        gc = gcd(-this->numer , this->denomer);
    this->numer = this->numer/gc;
    this->denomer = this->denomer/gc;
    return *this;
}
Fraction& Fraction::operator/=(const Fraction& obj){
    this->numer = this->numer * obj.denomer;
    this->denomer = this->denomer * obj.numer;
    int gc;
     if(this->numer > 0)
        gc = gcd(this->numer , this->denomer);
    else
        gc = gcd(-this->numer , this->denomer);
    this->numer = this->numer/gc;
    this->denomer = this->denomer/gc;
    return *this;
}
ostream& operator<<(ostream& out, const Fraction& f){           //cout cin
    out<<f.numer;
    out<<" / ";
    out<<f.denomer;
    out<<endl;
    return out;
}
istream& operator>>(istream& in, Fraction& f){
    cout<<"Enter Numerator: ";
    in>>f.numer;
    cout<<"Enter Denumerator: ";
    in>>f.denomer;
    return in;
}
bool Fraction::operator==(const Fraction& obj){     //relational operators
    if(this->numer == obj.numer && this->denomer == obj.denomer)
        return true;
    else
        return false;
}
bool Fraction::operator!=(const Fraction& obj){
        if(this->numer == obj.numer && this->denomer == obj.denomer)
        return false;
    else
        return true;
}
bool Fraction::operator<(const Fraction& obj){
    double x,y;
    x = static_cast<double>(this->numer) / static_cast<double>(this->denomer);
    y = static_cast<double>(obj.numer) / static_cast<double>(obj.denomer);
    if(x < y)
        return true;
    else
        return false;
}
bool Fraction::operator>(const Fraction& obj){
    double x,y;
    x = static_cast<double>(this->numer) / static_cast<double>(this->denomer);
    y = static_cast<double>(obj.numer) / static_cast<double>(obj.denomer);
    if(x > y)
        return true;
    else
        return false;
}
bool Fraction::operator<=(const Fraction& obj){
    double x,y;
    x = static_cast<double>(this->numer) / static_cast<double>(this->denomer);
    y = static_cast<double>(obj.numer) / static_cast<double>(obj.denomer);
    if(x <= y)
        return true;
    else
        return false;
}
bool Fraction::operator>=(const Fraction& obj){
    double x,y;
    x = static_cast<double>(this->numer) / static_cast<double>(this->denomer);
    y = static_cast<double>(obj.numer) / static_cast<double>(obj.denomer);
    if(x >= y)
        return true;
    else
        return false;
}
Fraction Fraction::operator++(){            //increment decrement
    this->numer++;
    this->denomer++;
    return *this;
}
Fraction Fraction::operator++(int){
    Fraction temp;
    temp.numer = this->numer;
    temp.denomer = this->denomer;
    this->numer++;
    this->denomer++;
    return temp;
}
Fraction Fraction::operator--(){
    this->numer--;
    this->denomer--;
    return *this;
}
Fraction Fraction::operator--(int){
    Fraction temp;
    temp.numer = this->numer;
    temp.denomer = this->denomer;
    this->numer--;
    this->denomer--;
    return temp;
}
bool Fraction::operator&&(const Fraction& obj){     //logical
    int x = this->numer * this->denomer;
    int y = obj.numer * obj.denomer;

    return x&&y;
}
bool Fraction::operator||(const Fraction& obj){
    int x = this->numer * this->denomer;
    int y = obj.numer * obj.denomer;

    return x||y;
}
int Fraction::operator[](int i) const{      //subscipt
    if(i == 0){
        return this->numer;
    }else if(i == 1){
        return this->denomer;
    }else{
        cout<<"Wrong Index Given"<<endl;
        return 0;
    }
}
int Fraction::operator()(int i) const{          //drmiani bracket
    if(i == 0){
        return this->numer;
    }else if(i == 1){
        return this->denomer;
    }else{
        cout<<"Wrong Index Given"<<endl;
        return 0;
    }
}
Fraction* Fraction::operator&(){        //adress operator
    return this;
}
Fraction Fraction::operator->(){        //object operator
    return *this;
}
Fraction Fraction::operator->*(Fraction x){     //idk bout this xD
    Fraction temp;
    temp.numer = x.numer;
    temp.denomer = x.denomer;
    return temp;
}

Fraction::~Fraction(){      //destructer

}

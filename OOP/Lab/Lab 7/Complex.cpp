/*
 * Complex.cpp
 *
 *  Created on: Mar 8, 2023
 *      Author: lab
 */

#include "Complex.h"

Complex::Complex(double r, double i):Real(r),Comp(i){

}
Complex::Complex(Complex & copy){
	this->Real=copy.Real;
	this->Comp=copy.Comp;
}

double Complex::getComp() const {
	return Comp;
}

void Complex::setComp(double comp) {
	this->Comp = comp;
}

double Complex::getReal() const {
	return Real;
}

void Complex::setReal(double real) {
	this->Real = real;
}
Complex Complex::addComplex( double r){
	this->Real = this->Real + r;
	return *this;
}
Complex Complex::addComplex(Complex &c1){
	this->Real = this->Real + c1.Real;
	this->Comp= this->Comp+ c1.Comp;
	return *this;
}
Complex Complex::subComplex( double r){
	this->Real = this->Real - r;
	return *this;
}
Complex Complex::subComplex(Complex &c1){
	this->Real = this->Real - c1.Real;
	this->Comp= this->Comp - c1.Comp;
	return *this;
}
Complex Complex::mulComplex(double n){
	this->Real = this->Real * n;
	this->Comp= this->Comp * n;
	return *this;
}
Complex Complex::mulComplex(Complex &c1){
	this->Real = (this->Real * c1.Real) - (this->Comp * c1.Comp);
	this->Comp = (this->Real * c1.Comp) + (this->Comp * c1.Real);
	return *this;

}

Complex::~Complex() {
	// TODO Auto-generated destructor stub
}


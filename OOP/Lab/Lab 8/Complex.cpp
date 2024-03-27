/*
 * Complex.cpp
 *
 *  Created on: Mar 8, 2023
 *      Author: lab
 */

#include "Complex.h"
Complex::Complex(){
	Real=0;
	Comp=0;
}
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
Complex addComplex(Complex &c1,Complex &c2){
	Complex c3(0,0);
	c3.Real = c1.Real + c2.Real;
	c3.Comp= c1.Comp+ c2.Comp;
	return c3;
}
Complex subComplex(Complex &c1,Complex &c2){
	Complex c3(0,0);
	c3.Real = c1.Real - c2.Real;
	c3.Comp = c1.Comp - c2.Comp;
	return c3;
}

Complex mulComplex(Complex &c1,Complex &c2){
	Complex c3(0,0);
	c3.Real = (c1.Real * c2.Real) - (c1.Comp * c2.Comp);
	c3.Comp = (c1.Real * c2.Comp) + (c1.Comp * c2.Real);
	return c3;

}

Complex::~Complex() {
	// TODO Auto-generated destructor stub
}

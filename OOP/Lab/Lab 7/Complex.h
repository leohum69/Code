/*
 * Complex.h
 *
 *  Created on: Mar 8, 2023
 *      Author: lab
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex {
	double Real;
	double Comp;
public:
	Complex(double r, double i);
	Complex(Complex & copy) ;
	virtual ~Complex();
	double getComp() const;
	void setComp(double comp);
	double getReal() const;
	void setReal(double real);
	Complex addComplex( double r);
	Complex addComplex(Complex &c1);
	Complex subComplex(double r);
	Complex subComplex(Complex &c1);
	Complex mulComplex(double n);
	Complex mulComplex(Complex &c1);
};

#endif /* COMPLEX_H_ */

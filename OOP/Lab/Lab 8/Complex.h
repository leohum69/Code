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
	Complex();
	Complex(double r, double i);
	Complex(Complex & copy) ;
	virtual ~Complex();
	double getComp() const;
	void setComp(double comp);
	double getReal() const;
	void setReal(double real);
	friend Complex addComplex(Complex &c1,Complex &c2);
	friend Complex subComplex(Complex &c1,Complex &c2);
	friend Complex mulComplex(Complex &c1,Complex &c2);
};

#endif /* COMPLEX_H_ */

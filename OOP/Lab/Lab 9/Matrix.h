/*
 * Matrix.h
 *
 *  Created on: Mar 22, 2023
 *      Author: lab
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
using namespace std;

class Matrix {
	int **arr;
	int rows;
	int columns;
public:
	Matrix(int,int);
	Matrix operator+(int);
	Matrix operator-(int);
	Matrix operator+(const Matrix &obj);
	Matrix operator-(const Matrix &obj);
	void operator=(const Matrix &obj);
	bool operator==(const Matrix &obj);
	void setvals();
	void print();
	virtual ~Matrix();
};

#endif /* MATRIX_H_ */

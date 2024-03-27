/*
 * Matrix.cpp
 *
 *  Created on: Mar 22, 2023
 *      Author: lab
 */

#include "Matrix.h"
Matrix::Matrix(int r,int c) {
	this->rows = r;
	this->columns = c;
	this->arr = new int*[this->rows];
	for(int i=0;i<this->rows;i++){
		this->arr[i] = new int[this->columns];
	}
}
void Matrix::setvals(){
	for(int i=0; i<this->rows;i++){
		for(int j=0; j <this->columns ;j++){
			cout<<"Enter the "<<i<<"th and "<<j<<"th element:";
			cin>>this->arr[i][j];
		}
	}
}
void Matrix::print(){
	for(int i=0; i<this->rows;i++){
		for(int j=0; j <this->columns ;j++){
			cout<<this->arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
Matrix Matrix::operator+(int a){
	Matrix temp(this->rows , this->columns);
	for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				temp.arr[i][j] = this->arr[i][j] + a;
			}
		}
	return temp;
}
Matrix Matrix::operator-(int a){
	Matrix temp(this->rows , this->columns);
	for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				temp.arr[i][j] = this->arr[i][j] - a;
			}
		}
	return temp;
}
Matrix Matrix::operator+(const Matrix &obj){
	Matrix temp(obj.rows,obj.columns);
	if(this->rows == obj.rows && this->columns == obj.columns){
		for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				temp.arr[i][j] = this->arr[i][j] + obj.arr[i][j];
			}
		}
	}else{
		for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				temp.arr[i][j] = -1;
			}
		}
	}
	cout<<"Error"<<endl;
	return temp;
}
Matrix Matrix::operator-(const Matrix &obj){
	Matrix temp(obj.rows,obj.columns);
	if(this->rows == obj.rows && this->columns == obj.columns){
		for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				temp.arr[i][j] = this->arr[i][j] - obj.arr[i][j];
			}
		}
	}else{
		for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				temp.arr[i][j] = -1;
			}
		}
	}
	cout<<"Error"<<endl;
	return temp;
}
void Matrix::operator=(const Matrix &obj){
	for(int i=0;i < this->rows ; i++)
		delete []this->arr[i];
	delete []this->arr;
	this->rows = obj.rows;
	this->columns = obj.columns;
	this->arr = new int*[this->rows];
	for(int i=0;i<this->rows;i++){
		this->arr[i] = new int[this->columns];
	}
	for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				this->arr[i][j] = obj.arr[i][j];
			}
		}
}
bool Matrix::operator==(const Matrix &obj){
	bool chk = false;
	if(this->rows == obj.rows && this->columns == obj.columns){
		chk = true;
	}
	if(chk == true){
		for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				if(this->arr[i][j] == obj.arr[i][j]){
					chk = chk && true;
				}else{
					chk = chk && false;
				}
			}
		}
	}
	return chk;
}



Matrix::~Matrix() {
	for(int i=0;i < this->rows ; i++)
		delete []this->arr[i];
	delete []this->arr;
}


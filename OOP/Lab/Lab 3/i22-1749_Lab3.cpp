//============================================================================
// Name        : Lab03.cpp
// Author      : Mirza Humayun Masood
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
using namespace std;
int* CalculateSum(int **p1, int m,int n);
string Diagonal(int** matrix ,int rows,int columns);
int** MatrixSum(int** MatrixA, int** MatrixB,int m,int n);
void ThreeD (int*** ptr, int pages, int rows, int columns);
int*** Square(int ***mat, int pages, int rows, int columns);

int main() {
	//p1
/*
	int **ptr1=new int*[4];
	  for (int i=0;i<4;i++){

	  ptr1[i]=new int [4];

	  }
	  for (int i=0;i<4;i++){

	    for(int j=0;j<4;j++){

	        ptr1[i][j]=2;
	        cout<<ptr1[i][j]<<" ";

	    }
	  }
	  CalculateSum(ptr1,4,4);
	  */
	//p2
	/*
	  int **matrix=new int*[3];
	      for (int i=0;i<4;i++){

	        matrix[i]=new int[3];
	      }
	      matrix[0][0]=1;
	      matrix[0][1]=2;
	      matrix[0][2]=3;
	      matrix[1][0]=0;
	      matrix[1][1]=3;
	      matrix[1][2]=4;
	      matrix[2][0]=0;
	      matrix[2][1]=0;
	      matrix[2][2]=10;
	      Diagonal(matrix,3,3);
	      */
	//p3
	/*  int **matrix1=new int*[3];
  for (int i=0;i<3;i++){

    matrix1[i]=new int[3];
  }
  matrix1[0][0]=1;
  matrix1[0][1]=2;
  matrix1[0][2]=3;
  matrix1[1][0]=0;
  matrix1[1][1]=3;
  matrix1[1][2]=4;
  matrix1[2][0]=0;
  matrix1[2][1]=0;
  matrix1[2][2]=10;
  int **matrix2=new int*[3];
  for (int i=0;i<3;i++){

    matrix2[i]=new int[3];
  }
  matrix2[0][0]=1;
  matrix2[0][1]=0;
  matrix2[0][2]=0;
  matrix2[1][0]=1;
  matrix2[1][1]=2;
  matrix2[1][2]=0;
  matrix2[2][0]=10;
  matrix2[2][1]=4;
  matrix2[2][2]=10;
	MatrixSum(matrix1,matrix2,3,3);
  */
	//p4
	/*int ***p1=0;
	ThreeD(p1,3,3,3);*/
	//p5
	/*
	int ***p2;
	p2= new int**[3];
		for(int i=0;i<3;i++){
			p2[i]=new int*[3];
			for(int j=0;j<3;j++){
				p2[i][j]=new int[3];
				for(int k=0;k<3;k++){
					p2[i][j][k]=5;
				}
			}
		}

	int ***p3= Square(p2,3,3,3);



	return 0;*/
}
int* CalculateSum(int **p1, int m,int n){
	int sum=0;
	int *ptr=new int[m];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			sum+=*(*(p1+i)+j);
		}
		*(ptr+i)=sum;
		sum=0;
	}
	return ptr;

}
string Diagonal(int** matrix ,int rows,int columns){
	bool cc=true;
	for(int i=0;i<rows;i++){
		for(int j=0;j<i;j++){
			if(*(*(matrix+i)+j)==0){
				cc=cc && true;
			}else{
				cc=cc && false;
			}
		}
	}
	if(cc==true)
		return "upper";
	else
		return "notupper";

}
int** MatrixSum(int** MatrixA, int** MatrixB,int m,int n){
	int **mat3=new int*[m];
	for(int i=0;i<m;i++){
		*(mat3+i)=new int[n];
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			*(*(mat3+i)+j)=0;
			*(*(mat3+i)+j)= *(*(MatrixA+i)+j) + *(*(MatrixB+i)+j);
		}
	}
	return mat3;

}
void ThreeD (int*** ptr, int pages, int rows, int columns){
	ptr= new int**[pages];
	for(int i=0;i<pages;i++){
		ptr[i]=new int*[rows];
		for(int j=0;j<rows;j++){
			ptr[i][j]=new int[columns];
		}
	}

}
int*** Square(int ***mat, int pages, int rows, int columns){
	int ***ptr= new int**[pages];
	for(int i=0;i<pages;i++){
		ptr[i]=new int*[rows];
		for(int j=0;j<rows;j++){
			ptr[i][j]=new int[columns];
		}
	}

	for(int i=0;i<pages;i++){
		for(int j=0;j<rows;j++){
			for(int k=0;k<columns;k++){
				*(*(*(ptr+i)+j)+k)=(*(*(*(mat+i)+j)+k)) * (*(*(*(mat+i)+j)+k));
			}
		}
	}
	return ptr;

}


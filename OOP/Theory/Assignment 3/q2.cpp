/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Matrix{       //class

    int **arr;          //orivate data members
	int rows;
	int columns;
public:
	Matrix(int=2,int=2);        //cnstrctr
	Matrix& operator++();       //operators
	Matrix operator++(int);
	Matrix operator+(const Matrix &obj);
	Matrix operator-(const Matrix &obj);
	Matrix& operator=(const Matrix &obj);
	Matrix operator*(int);
	Matrix operator*(const Matrix &obj);
	bool operator==(const Matrix &obj);
	void setvals();         //for setting values
	void print();           //print the matrix
	virtual ~Matrix();      //destructer
};

Matrix::Matrix(int r,int c) {       //cnstrctr
	this->rows = r;
	this->columns = c;
	this->arr = new int*[this->rows];
	for(int i=0;i<this->rows;i++){
		this->arr[i] = new int[this->columns];
		for(int j=0;j<this->columns;j++){
            this->arr[i][j]=0;
		}
	}
}
void Matrix::setvals(){         //set values
    char str[100];
    int i=0,j=0;
    cout<<"Enter Integers to enter in matrix (comma seprated, no comma after last number): ";       //comma seprated
    cin.ignore();
    cin.get(str,100);
    int iter=0,c=0;
    while(str[iter] != '\0'){
        if(str[iter] == ','){
            c++;
        }
        iter++;
    }
    if(c != ((this->columns * this->rows)-1)){
        cout<<"Error"<<endl;
        exit(0);
    }
    char del[]=",";
    char *token = strtok(str,del);      //strtok zindabad
    while(token){
        //cout<<i<<" "<<j<<endl;
        this->arr[i][j] = atoi(token);
        if(j<this->columns-1)
            j++;
        else{
            i++;
            j=0;
        }
        //cout<<this->arr[i][j]<<" ";
        //cout<<token<<endl;
        token = strtok(NULL,del);
    }
}
void Matrix::print(){       //print
	for(int i=0; i<this->rows;i++){
		for(int j=0; j <this->columns ;j++){
			cout<<this->arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
Matrix& Matrix::operator++(){           //++ operators
	for(int i=0; i<this->rows;i++){
        for(int j=0; j <this->columns ;j++){
            this->arr[i][j] = this->arr[i][j] + 1;
        }
    }
    return *this;
}
Matrix Matrix::operator++(int){         //post inc ++ operator xD
    Matrix temp(this->rows, this->columns);
	for(int i=0; i<this->rows;i++){
        for(int j=0; j <this->columns ;j++){
            temp.arr[i][j] = this->arr[i][j];
            this->arr[i][j]++;
        }
    }
    return temp;
}

Matrix Matrix::operator+(const Matrix &obj){        //+ operator
	Matrix temp(obj.rows,obj.columns);
	if(this->rows == obj.rows && this->columns == obj.columns){
		for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				temp.arr[i][j] = this->arr[i][j] + obj.arr[i][j];
			}
		}
		return temp;
	}else{
        cout<<"Invalid operation"<<endl;
        exit(EXIT_FAILURE);
	}
}
Matrix Matrix::operator-(const Matrix &obj){        //- operator
	Matrix temp(obj.rows,obj.columns);
	if(this->rows == obj.rows && this->columns == obj.columns){
		for(int i=0; i<this->rows;i++){
			for(int j=0; j <this->columns ;j++){
				temp.arr[i][j] = this->arr[i][j] - obj.arr[i][j];
			}
		}
        return temp;
	}else{
         cout<<"Invalid operation"<<endl;
         exit(EXIT_FAILURE);
	}
}
Matrix Matrix::operator*(int x){        //multiply with scaler
    Matrix temp(this->rows,this->columns);
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->columns;j++){
            temp.arr[i][j] = x * this->arr[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator*(const Matrix &obj){        //matrix multiplication
    Matrix temp(this->rows,obj.columns);
    if(this->columns == obj.rows){
        int x=0;
        for(int i=0;i<this->rows;i++){
            for(int j=0;j<obj.columns;j++){
                x=0;
                for(int k=0;k<this->columns;k++){
                    x = x + (this->arr[i][k] * obj.arr[k][j]);
                }
                temp.arr[i][j] = x;
            }
        }
        return temp;
    }else{
        cout<<"Invalid Operation"<<endl;
    }
}
Matrix& Matrix::operator=(const Matrix &obj){       //assignment
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
    return *this;
}
bool Matrix::operator==(const Matrix &obj){         //== operator
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

Matrix::~Matrix() {         //destrcter
	for(int i=0;i < this->rows ; i++)
		delete []this->arr[i];
	delete []this->arr;
}
int main(){         //main as it was given in assignment :3
    int r,c,x;
    cout<<"Please enter the rows of matrix 1: ";
    cin>>r;
    while(r<=0){
        cout<<"Error Enter Again : ";
        cin>>r;
    }
    cout<<"Please enter the columns of matrix 1: ";
    cin>>c;
    while(c<=0){
        cout<<"Error Enter Again : ";
        cin>>c;
    }
    Matrix M1(r,c);
    M1.setvals();
        cout<<"Please enter the rows of matrix 2: ";
    cin>>r;
    while(r<=0){
        cout<<"Error Enter Again : ";
        cin>>r;
    }
    cout<<"Please enter the columns of matrix 2: ";
    cin>>c;
    while(c<=0){
        cout<<"Error Enter Again : ";
        cin>>c;
    }
    Matrix M2(r,c);
    M2.setvals();
    cout<<"Displaying matrix 1: "<<endl;
    M1.print();
    cout<<"Displaying matrix 2: "<<endl;
    M2.print();
    cout<<"Performing matrix1+matrix 2:"<<endl;
    (M1+M2).print();
    cout<<"Performing matrix1-matrix 2:"<<endl;
    (M1-M2).print();
    cout<<"Peforming matrix1 * scalar"<<endl;
    cout<<"Enter Scaler: ";
    cin>>x;
    (M1 * x).print();
    cout<<"Peforming matrix2 * scalar"<<endl;
    cout<<"Enter Scaler: ";
    cin>>x;
    (M2 * x).print();
    cout<<"Peforming matrix1 * matrix2"<<endl;
    (M1 * M2).print();
    cout<<"Performing matrix1 == matrix2:"<<endl;
    (M1 == M2);
    cout<<endl;
    cout<<"Copying matrix1 into a new matrix object, matrix3"<<endl;
    cout<<"Displaying matrix 3:"<<endl;
    Matrix M3(2,2);
    M3.print();
    cout<<"Now performing matrix3=matrix1"<<endl;
    M3 = M1;
    cout<<"Displaying matrix 3:"<<endl;
    M3.print();
    cout<<"Updating matrix 1 as follows:"<<endl;
    M1.setvals();
    cout<<endl;
    M1.print();
    cout<<"Displaying matrix3 again:"<<endl;
    M3.print();
    cout<<"Demo of assignment operator complete."<<endl;
    cout<<endl<<"Performing matrix1++"<<endl;
    M1++;
    M1.print();
    cout<<"Performing ++matrix2:"<<endl;
    ++M2;
    M2.print();
    cout<<"Performing matrix3 = ++matrix1:"<<endl;
    M3 = ++M1;
    cout<<"Updated M1:"<<endl;
    M1.print();
    cout<<"Updated M3:"<<endl;
    M3.print();
    cout<<"Performing matrix3 = matrix1++:"<<endl;
    M3 = M1++;
    cout<<"Updated M1:"<<endl;
    M1.print();
    cout<<"Updated M3:"<<endl;
    M3.print();
    cout<<"Destroying all matrices:"<<endl;
    return 0;
}

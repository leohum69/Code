#include <iostream>
#include <ctime>
using namespace std;

int fun1(int *ptr,int size);
void fun2(int *ptr,int size);
void fun3(int *ptr,int size);

int main(){
	srand(time(0));
	int size=0;
	int choice=0;
	int pp=0;
	cout<<"Enter The Size of matrix: ";
	cin>>size;
	
	int mat[size][size]={0};
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			mat[i][j]= rand()%10;
		}
	}
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	do{
		cout<<"Enter Your Choice: "<<endl;
		cout<<"Press 1 to tell the type of Matrix."<<endl;
		cout<<"Press 2 to add the matrix with itself."<<endl;
		cout<<"Press 3 to Apply Filter."<<endl;
		cout<<"Press 0 to Exit."<<endl;
		cin>>choice;
		
		if(choice==1){
			pp=fun1(&mat[0][0],size);
			switch(pp){
				case 0:
					cout<<"The Matrix is Null."<<endl;
					break;
				case 1:
					cout<<"The Matrix is Diagonal."<<endl;
					break;
				case 2:
					cout<<"The Matrix is Square."<<endl;
					break;
			}
		}else if(choice==2){
			fun2(&mat[0][0],size);
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					cout<<mat[i][j]<<" ";
				}
				cout<<endl;
			}
		}else if(choice==3){
			fun3(&mat[0][0],size);
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					cout<<mat[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		
	}while(choice!=0);
	
	return 0;
}
int fun1(int *ptr,int size){
	bool a=true;
	bool b=true;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(*((ptr + (i*size))+j)==0){
				a = a && true;
			}else{
				a= a && false;
			}
		}	
	}
	if(a==true){
		return 0;
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(i==j){
				continue;
			}else if(*((ptr + (i*size))+j)==0){
				b= b && true;
			}else{
				b= b && false;
			}
		}
	}
	if(b==true){
		return 1;
	}
	else{
		return 2;
	}
	
}

void fun2(int *ptr,int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			*((ptr + (i*size))+j)=*((ptr + (i*size))+j)*2;
		}
	}
	
}
void fun3(int *ptr,int size){
	for(int j=1;j<size;j++){
		*(ptr+j)=0;	
	}
	for(int j=0;j<size-1;j++){
		*((ptr+size)+j)=0;	
	}
}


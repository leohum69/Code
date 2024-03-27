#include <iostream>
using namespace std;

int great(int,int);
int great(int,int,int);
int great(int,int,int,int);


int main(){
	int x;
	int a,b,c,d,gr;

	cout<<"***Welcome to Calculate largest Number Program***"<<endl;
	cout<<"   1.  Press 1 to calculate the largest number among 2 numbers."<<endl;
	cout<<"   2.  Press 2 to calculate the largest number among 3 numbers."<<endl;
	cout<<"   3.  Press 3 to calculate the largest number among 4 numbers."<<endl;
	
	cin>>x;

	switch(x){
		case 1:
			cout<<"Enter First Number: ";
			cin>>a;
			cout<<"Enter Second Number: ";
			cin>>b;
			gr=great(a,b);
			break;
		case 2:
			cout<<"Enter First Number: ";
			cin>>a;
			cout<<"Enter Second Number: ";
			cin>>b;
			cout<<"Enter Third Number: ";
			cin>>c;
			gr=great(a,b,c);
			break;
		case 3:
			cout<<"Enter First Number: ";
			cin>>a;
			cout<<"Enter Second Number: ";
			cin>>b;
			cout<<"Enter Third Number: ";
			cin>>c;
			cout<<"Enter Fourth Number: ";
			cin>>d;
			gr=great(a,b,c,d);
			break;
		default:
			cout<<"Invalid Input"<<endl;
			break;
	
	
	}
	cout<<"The Greater Number was :"<<gr<<endl;


return 0;
}
int great(int a,int b){
	if(a>b){
		return a;
	}else if(b>a){
		return b;
	}
}

int great(int a,int b,int c){
	if(a>b && a>c){
		return a;
	}else if(b>a && b>c){
		return b;
	}else if(c>a && c>b){
		return c;
	}
}

int great(int a,int b,int c,int d){
	if(a>b && a>c && a>d){
		return a;
	}else if(b>a && b>c && b>d){
		return b;
	}else if(c>a && c>b && c>d){
		return c;
	}else if(d>a && d>b && d>c){
		return d;
	}
}







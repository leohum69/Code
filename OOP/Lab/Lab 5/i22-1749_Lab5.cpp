//============================================================================
// Name        : Lab05.cpp
// Author      : Mirza Humayun Masood
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int pow(int b,int e);
void help(char ch,int lines, int start,int i);
void help2(char ch,int lines, int start,int i);
void PrintScreen5(char ch,int lines, int start);
int product(int a, int b);
void Pattern2(int a,int b,int c);
void helpp(int a,int b,int c,int i);
bool SubString(char str1[], char str12[], int length1, int length2);
int fittest (int number);
void ff(int *a,int i,int n);
int *f2(int *a,int n);

//int main() {
	//q1
	//cout<<pow(5,3);
	//q2
	//help('*',5,1,4);
	//help2('*',5,1,4);
	//q3
	//cout<<product(0,1);
	//q4
	//helpp(5,1,4,0);
	//q5
	//cout<<SubString("bat","table",3,5);
	//q6
//	cout<<fittest(1);


	//return 0;
//}

int pow(int b,int e){
	if(e==0){
		return 1;
	}
	if(e==1){
		return b;
	}
	return b * pow(b,e-1);
}
void help(char ch,int lines, int start,int i){
	if(start>lines){
		return;
	}

	PrintScreen5(' ',lines,start);
	PrintScreen5(ch,lines,i);
	cout<<endl;
	help(ch,lines-1,start,i-2);

}
void help2(char ch,int lines, int start,int i){
	if(start>lines){
			return;
	}
	PrintScreen5(' ',lines,i);
	PrintScreen5(ch,lines,start);
	cout<<endl;
	help2(ch,lines,start+1,i-1);
}
void PrintScreen5(char ch,int lines, int start){
	if(start==lines){
		return;
	}
	cout<<ch;
	PrintScreen5(ch,lines,start+1);
}
int product(int a, int b){
	if(b==0){
		return 0;
	}
	return a + product(a,b-1);
}
void Pattern2(int a,int b,int c){
	if(c==a){
		return;
	}
	cout<<static_cast<char>(64+b)<<" ";
	Pattern2(a,b+1,c+1);
}
void helpp(int a,int b,int c,int i){
	if(i==a){
		return;
	}
	Pattern2(a,b,c);
	cout<<endl;
	helpp(a,b+i+1,c-1,i+1);
}
bool SubString(char str1[], char str12[], int length1, int length2){
	if(str1[0]=='\0'){
		return 1;
	}else if(str12[0]=='\0'){
		return 0;
	}
	if(str1[0]==str12[0]){
		return SubString(++str1,++str12,length1-1,length2-1);
	}else{
		return SubString(str1,++str12,length1,length2-1);
	}


}

int fittest (int number){
	int a[number]={0};
	ff(a,0,number);
	int *p= f2(a,number);
	if(number==p[0]){
		return 1;
	}else{
		return 0;
	}


}
void ff(int *a,int i,int n){
	if(i==n){
		return;
	}
	a[i]=i+1;
	ff(a,i+1,n);
}
int *f2(int *a,int n){
	if(n==0){
		return a;
	}
	int *p=new int[n];
	for(int i=0,j=0;i<n;i=i+2,j++){
		p[i]=a[j];
	}
	return f2(p,n-1);
}



#include<iostream>
using namespace std;

void fun(char a[],char p,int x);

int main(){

	char str[100]="";
	char p;
	cout<<"Enter Character:";
	cin>>p;
	cin.ignore();
	cout<<"Enter String: ";
	cin.get(str,100);
	
	fun(str,p,100);



return 0;
}

void fun(char a[],char p,int x){
	int counter=0;
	for(int i=0;i<x;i++){
		if(a[i]==p){
			counter++;
		}
	}
	cout<<"The Occurence of "<<p<<" is "<<counter<<endl;
}

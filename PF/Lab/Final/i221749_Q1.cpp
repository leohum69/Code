#include <iostream>
#include <cmath>
using namespace std;

bool check(long long a);

int B2D(long long a);
long long D2B(long long a);

int main(){
	long long input=0;
	cout<<"Enter A number: ";
	cin>>input;
	
	if(check(input)==false){
		cout<<"The Converted Number is :"<<D2B(input)<<endl;
	}else{
		cout<<"The Converted Number is :"<<B2D(input)<<endl;
	}

	return 0;
}
bool check(long long a){
	long long x=a;
	int c=0;
	bool chk=true;
	
	while(x>0){
		c=x%10;
		x=x/10;
		if(c==1 || c==0){
			chk = chk && true;
		}else{
			chk = chk && false;
		}
	}
	return chk;
}

int B2D(long long a){
	long long x=a;
	int c=0;
	int val=0;
	int po=0;
	while(x>0){
		c=x%10;
		x=x/10;
		val+= c*(pow(2,po));
		po++;
	}
	return val;
}
long long D2B(long long a){
	long long x=a;
	int c=0;
	long long val=0;
	int po=0;
	while(x>0){
		c=x%2;
		x=x/2;
		val+= c * pow(10,po);
		po++;
	}
	return val;
}

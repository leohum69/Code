#include <iostream>
using namespace std;

bool perfect ( int );

int main(){

	for(int i=1;i<=1000;i++){
		bool chk=perfect(i);
		
		if(chk==1){
			cout<<i<<" is perfect"<<endl;
		}
	}		
	
return 0;
}

bool perfect (int a){
	int sum=0;
	
	for(int i=1;i<a;i++){
		if(a%i==0){
			sum=sum+i;
		}
	}
	if(sum==a){
		return 1;
	}else{
		return 0;
	}
}


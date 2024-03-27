#include <iostream>
using namespace std;

void ADD(int *a,int *b,int *c);

int main(){
	int a,b,c;
	cout<<"Enter 1st Number :";
	cin>>a;
	cout<<"Enter 2nd Number :";
	cin>>b;
	ADD(&a,&b,&c);
	cout<<"Sum : "<<c<<endl;



	return 0;
}
void ADD(int *a,int *b,int *c){

	*c=*a+*b;


}

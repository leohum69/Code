#include <iostream>
using namespace std;

int main(){

	int *var1,*var2,a,b;
	var1 = &a;
	var2 = &b;
	cout<<"Input the first number :";
	cin>>*var1;
	cout<<"Input the second number :";
	cin>>*var2;
	cout<<"The sum of the entered numbers is : "<<*var1+*var2<<endl;

return 0;
}

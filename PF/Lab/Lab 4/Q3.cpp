#include <iostream>
using namespace std;

int main(){

	float up,quaintity,sales,tax;


	cout<<"Enter unit price of chocolate: ";
	cin>>up;
	cout<<"Enter quantity of chocolates sold: ";
	cin>>quaintity;

	sales= up * quaintity;

	cout<<"Total Sales before tax: "<<sales<<endl;

	tax= (10/100.0) * sales;

	cout<<"Sales after tax deduction: "<< sales - tax <<endl;






return 0;
}


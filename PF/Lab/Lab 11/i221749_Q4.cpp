#include <iostream>
using namespace std;

double Volume(double);
double Volume(double,double,double);
double Volume(double,double);

int main(){
	double length,width,height;
	double cube,Cuboid,Cylinder;

	cout<<"For Cube:"<<endl;
	cout<<"Enter Length: ";
	cin>>length;
	cube = Volume(length);
	cout<<endl<<endl;
	cout<<"For Cuboid:"<<endl;
	cout<<"Enter Length: ";
	cin>>length;
	cout<<"Enter Width: ";
	cin>>width;
	cout<<"Enter Height: ";
	cin>>height;
	
	Cuboid=Volume(length,width,height);
	cout<<endl<<endl;
	cout<<"For Cylinder:"<<endl;
	cout<<"Enter Radius: ";
	cin>>length;
	cout<<"Enter Height: ";
	cin>>height;
	Cylinder=Volume(length,height);
	
	cout<<"OUTPUT:"<<endl;
	cout<<"Volume of Cube: "<<cube<<endl;
	cout<<"Volume of Cuboid: "<<Cuboid<<endl;
	cout<<"Volume of Cylinder: "<<Cylinder<<endl;
	


return 0;
}
double Volume(double x){
	return (x*x*x);
}
double Volume(double x,double y,double z){
	return (x*y*z);
}
double Volume(double x,double y){
	return (3.14159 * x * x *y);
}

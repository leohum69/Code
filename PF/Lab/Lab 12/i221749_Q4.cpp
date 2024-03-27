#include <iostream>
using namespace std;

void pew(){
	static int x=0;
	x++;
	cout<<"Function is called "<<x<<" times"<<endl;
}

int main(){

	pew();
	pew();
	pew();
	pew();
	pew();



return 0;
}

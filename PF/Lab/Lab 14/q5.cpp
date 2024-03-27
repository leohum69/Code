#include <iostream>
#include <fstream>
using namespace std;


int main(){
	string xd,xd1;
	ifstream fin;
	ifstream fin2;
	fin.open("f1.txt");
	fin2.open("f2.txt");
	for(int i=0;i<3;i++){
		getline(fin,xd);
		getline(fin2,xd1);
		if(xd!=xd1){
			cout<<xd<<endl;
			cout<<xd1<<endl;
		}
	}


return 0;
}

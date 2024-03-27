#include <iostream>
#include <fstream>
using namespace std;

int main(){
	string cc;
	string xd;
	ofstream fout;
	fout.open("Record.txt");
	for(int i=1;i<=4;i++){
		cout<<"Enter Roll Number: ";
		cin>>cc;
		fout<<"\t"<<cc;
		cout<<"Enter Name: ";
		cin.ignore();
		getline(cin,cc);
		fout<<" "<<cc<<" ";
		cout<<"Enter Course: ";
		cin>>cc;
		fout<<cc<<" ";
		cout<<"Enter Number: ";
		cin>>cc;
		fout<<cc<<endl; 
		}
	
	fout.close();
	
	ifstream fin;
	fin.open("Record.txt");
	while(!fin.eof())
	{
		getline(fin,xd);
		cout<<xd<<endl;
	}



return 0;
}

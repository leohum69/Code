#include <iostream>
#include <fstream>
using namespace std;

void writef();
void readf();

int main(){
	writef();
	readf();
	


	



return 0;
}
void writef(){
	string xd;
	ofstream fout;
	fout.open("info.txt");
	cout<<"What Topic you want : ";
	cin>>xd;
	cout<<"Enter Paragraph: ";
	for(int i=0;i<10;i++){
		cin.ignore();
		getline(cin,xd);
		fout<<xd<<endl;
	}
	fout.close();
}
void readf(){
	int i=0;
	int counter=0;
	int counter2=0;
	string xd;
	ifstream fin;
	fin.open("info.txt");
	while(!fin.eof()){
		getline(fin,xd);
		while(xd[i]!='\0'){
			if(xd[i]==' '){
				counter++;
			}
			i++;

		}
		
		if(counter>=9){
			counter2++;
		}
		counter=0;
		i=0;
	}
		cout<<counter2<<" number of lines had more than 10 words"<<endl;
	
}

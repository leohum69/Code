#include <iostream>
using namespace std;
int code(char a);
char decode(int a);
char* encrp(char *cc);
char* decrp(char *cc);
int main(){
	int i=0;
	char *ptr= new char[100];
	char *ptr2=0;
	cout<<"Enter The code you want to encrypt: (small letters please):";
	cin.get(ptr,100);
	ptr2 = encrp(ptr);
	while(ptr2[i]!='\0'){
		cout<<ptr2[i];
		i++;
	}
	cout<<endl;

	return 0;
}
int code(char a){
	int p=0;
	for(int i='a';i<='z';i++){
		if(a==i){
			return p;
		}
		p++;
	}
	return -1;
}
char decode(int a){
	char p='A';
	for(int i=0;i<=25;i++){
		if(a==i)
			return p;
		p++;
	}
}

char* encrp(char *cc){
	char *ptr2= new char[100];
	int val=0;
	int i=0;
	while(cc[i]!='\0'){
		if(cc[i]==' '){
			i++;
			continue;
		}
		val= ((5*code(cc[i]))+8)%26;
		ptr2[i]= decode(val);
		i++;
	}
	for(int j=0;j<i;j++){
		if(ptr2[j]=='\0')
			ptr2[j]=' ';
	}
	return ptr2;
}
char* decrp(char *cc){
	int i=0;
	int val=0;
	while(cc[i]!='\0'){
		
		i++;
	}
}

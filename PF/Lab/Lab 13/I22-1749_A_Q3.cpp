#include <iostream>
using namespace std;

int main(){

	char str[100]="";
	int counter=0;
	cout<<"Enter String:";
	
	cin.get(str,100);
	
	
	for(int i=0;i<100;i++){
		if((str[i] == 65 )|| (str[i] == 69 )|| (str[i] == 73 )||( str[i] == 79 || str[i] == 85 )|| (str[i] == 97 )|| (str[i] == 101) || (str[i] == 105 )||( str[i] == 111 )||( str[i] == 117)){
			counter++;
		}
	}
	cout<<"Number of Vowels are "<<counter<<endl;
return 0;
}

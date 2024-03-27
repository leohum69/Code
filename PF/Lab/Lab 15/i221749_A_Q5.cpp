#include <iostream>
#include <ctime>
using namespace std;

int main(){
	srand(time(0));
	int *ptr;
	
	ptr = new int[10];
	for(int i=0;i<10;i++){
		*(ptr + i) = rand()%100;
	}
	for(int i=0;i<10;i++){
		cout<<*(ptr + i)<<" ";
	}


	return 0;
}

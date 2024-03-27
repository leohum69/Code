#include <iostream>
using namespace std;

int main(){
	
	int arr[5]={0};
	int *ptr;
	ptr=arr;
	int low=100,high=0;
	int *intptr;
	
	for(int i=0;i<5;i++){
		cout<<"Array["<<i<<"]= ";
		cin>>*(ptr+i);
	}
	intptr = &low;
	for(int i=0;i<5;i++){
		if(*intptr>ptr[i])
			*intptr=ptr[i];
	}
	cout<<"Smallest: "<<*intptr<<endl;
	intptr = &high;
	for(int i=0;i<5;i++){
		if(*intptr<ptr[i])
			*intptr=ptr[i];
	}
	cout<<"Largest: "<<*intptr<<endl;
	
	 



	return 0;
}

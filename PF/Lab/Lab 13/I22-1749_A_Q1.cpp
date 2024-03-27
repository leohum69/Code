#include <iostream>
using namespace std;

	void fun(int a[], int z);

int main(){

	const int ARRAY_SIZE = 10;
	int arr[ARRAY_SIZE];
	
	for(int i=0;i<ARRAY_SIZE;i++){
		cout<<"Enter "<<i+1<<" Value : ";
		cin>>arr[i];
	}
	
	fun(arr,ARRAY_SIZE);




return 0;
}

void fun(int a[], int z){
	int temp=0;
	int p=0;
	int c=0;

	cout<<"Unique Elements of the said array:";
	for(int i=0;i<z;i++){
		temp=a[i];
		for(int j=0;j<z;j++){
			if(i!=j){
				if(a[i]==a[j]){
					break;	
				}
				c=a[i];
			}

		}
		cout<<c<<" ";

	}


	
}

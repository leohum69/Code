#include <iostream>
using namespace std;

void reverse(int arr[][3],int);

int main(){
	int arr[3][3]={0};
	cout<<"Enter 9 Values: ";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	
	reverse(arr,3);



return 0;
}
void reverse(int arr[][3],int rows){
	int revarr[3][3]={0};
	
	for(int i=0,o=2;i<rows;i++,o--){
		for(int j=0,p=2;j<3;j++,p--){
			revarr[i][j]=arr[o][p];
		}
	}
	cout<<"Reverse array is : ";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<revarr[i][j]<<" ";
		}
	}

}

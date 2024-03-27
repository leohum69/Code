#include <iostream>
using namespace std;

int main(){

	int arr[5][5]={{2,3,5,3,1},{4,5,1,2,1},{4,7,3,2,0},{2,1,1,5,1},{1,7,8,9,0}};
	
	int sum[5]={0};
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			sum[i]+=arr[i][j];
		}
	}
	cout<<"Sum array: ";
	for(int i=0;i<5;i++){
		cout<<sum[i]<<" ";
	}




return 0;
}

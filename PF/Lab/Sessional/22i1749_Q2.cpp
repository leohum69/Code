#include <iostream>
using namespace std;

int main(){

	int x;
	cout<<"Enter a number :";
	cin>>x;
	
	for(int i=1,p=x,o=0;i<=x;i++,p--,o++){
		for(int j=1;j<p;j++){
			cout<<"  ";
		}
		for(int k=1;k<=i;k++){
			cout<<k<<" ";
		}
		for(int l=o;l>=1;l--){
			cout<<l<<" ";
		}
		cout<<endl;
	}







return 0;
}

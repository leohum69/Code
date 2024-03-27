#include <iostream>
using namespace std;

int main(){
	int a[8];
	int c=0;
	for(int i=0;i<8;i++){
		cout<<"Enter "<<1+i<<" Value : ";
		cin>>a[i];
	}
	cout<<"Array pairs whose sum equal to 12: "<<endl;
	for(int i=0;i<8;i++){
		for(int j=i;j<8;j++){
				if(a[i]+a[j]==12){
					cout<<a[i]<<","<<a[j]<<endl;
					c++;
				}
			}
	}
	cout<<"Number of pairs whose sum equal to 12: "<<c<<endl;

return 0;
}

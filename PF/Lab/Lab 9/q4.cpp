#include <iostream>

using namespace std;

int main(){

	int stu,tes,sum=0;
	int i=1,j=1;
	int pew;
	cout<<"Enter number of Students: ";
	cin>>stu;
	cout<<"Enter number of Tests: ";
	cin>>tes;
	
	do{
	
		cout<<"Enter Marks of Student "<<i<<endl;
	
		do{
			cout<<"Marks of test "<<j<<" : ";
			cin>>pew;
			sum=sum+pew;
			j++;
		
		}while(j<=tes);
		
		cout<<"Avrage of Student "<<i<<" : "<<(static_cast<float>(sum))/(tes)<<endl;
		j=1;
		sum=0;
		i++;
	
	}while(i<=stu);








	return 0;
}

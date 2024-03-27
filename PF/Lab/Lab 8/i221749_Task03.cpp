#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 1, c = 0, n,counter=1;

    cout << "Enter a positive number: ";
    cin >> n;
	if(n>2){

    cout << "Fibonacci Series: " << a << ", " << b << ", ";

    c = a + b;

    while(counter <= (n-2)) {
        cout << c << ", ";
        a = b;
        b = c;
        c = a + b;
	counter++;
    }}else{
	cout<<"Invalid Input"<<endl;
}

    
    return 0;
    
}

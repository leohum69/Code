#include <iostream>
using namespace std;

void recursivePuzzle(int n, char a,char c,char b){
    if(n==0)
        return;
    recursivePuzzle(n-1,a,b,c);
    cout<<"Move disk "<<n<<" from peg "<< a <<" to peg "<<c<<endl;
    recursivePuzzle(n-1,b,c,a);

}

int main(){
    //q1
    recursivePuzzle(3,'A','C','B');
    return 0;
}
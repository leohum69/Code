#include <iostream>
#include <string>

using namespace std;
template <typename T,typename U>
class Numbers
{
    private:
        T A;
        U B;
    public:
        Numbers(T A1, U B1);
        T Asquare();
        T Division();
};

template <typename T,typename U> Numbers<T,U>::Numbers(T A1, U B1){
    A = A1;
    B = B1;
}
template <typename T,typename U> T Numbers<T,U>::Asquare(){
    T result  = A*A;
    return result;
}
template <typename T,typename U> T Numbers<T,U>::Division(){
    if(B!=0)
        return A/B ;
    else
        return 0;
}

int main(){

    Numbers<double,int> num(10.9,3);
    cout <<" A square : "<< num.Asquare()<<endl;
    cout <<" A/B : "<< num.Division()<<endl;

}

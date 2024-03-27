#include <iostream>
#include <ctime>
using namespace std;

int determinant(int ** matrix){
    int det = 0;
    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
    - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
    + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}
int** adj(int ** matrix){
    int ** adjoint = new int*[3];
    for(int i=0;i<3;i++)
        adjoint[i] = new int[3];

    adjoint[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
    adjoint[0][1] = -(matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    adjoint[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
    adjoint[1][0] = -(matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
    adjoint[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
    adjoint[1][2] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);
    adjoint[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
    adjoint[2][1] = -(matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]);
    adjoint[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    return adjoint;
}
int detinv(int deter){
    if(deter < 0){
        deter = deter * -1;
        for(int i=1 ; i< 27 ;i++){
            if((i*deter)%26 == 1)
                {
                    cout<<i<<endl;
                    return i * -1;
                }
        }
    }else{
        for(int i=1 ; i< 27 ;i++){
            if((i*deter)%26 == 1)
                {
                    cout<<i<<endl;
                    return i;
                }
        }
    }
}
void matinv(int ** mat){
    int dets = determinant(mat);
    int ** newmat = adj(mat);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<newmat[i][j]<<" ";
        }
        cout<<endl;
    }

    int det = detinv(dets);
    cout<<dets<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            newmat[i][j] = newmat[i][j] * det;
            if(newmat[i][j] < 0){
                newmat[i][j] = newmat[i][j] * -1;
                newmat[i][j] = newmat[i][j] % 26;
                newmat[i][j] = newmat[i][j] * -1;
            }else{
                newmat[i][j] = newmat[i][j] % 26;
            }
        }
    }


    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(newmat[i][j] < 0)
                newmat[i][j] = newmat[i][j] + 26;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            mat[i][j]=newmat[i][j];
        }
    }
    for(int i=0;i<3;i++){
        delete []newmat[i];
    }
    delete []newmat;

}
void mult(int ** key,int * arr, int * arr2){
    arr2[0] = (key[0][0] * arr[0]) + (key[0][1] * arr[1]) + (key[0][2] * arr[2]);
    arr2[1] = (key[1][0] * arr[0]) + (key[1][1] * arr[1]) + (key[1][2] * arr[2]);
    arr2[2] = (key[2][0] * arr[0]) + (key[2][1] * arr[1]) + (key[2][2] * arr[2]);
}
bool able(int** mat){
    if(determinant(mat) == 0)
        return false;
    else
        return true;
}
int** keygen(){
    int ** mat = new int*[3];
    for(int i=0;i<3;i++)
        mat[i] = new int[3];
    do{
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                mat[i][j] = rand()%26;
            }
        }
    }while(able(mat) == false);

    return mat;
}
void enc(char * arr,int ** mat){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    int idx = i/3;
    int p=0;

    int arr2[3] = {0};
    for(int i=0 ; i<3;i++){
        arr2[i] = arr[i]-65;
    }
    int arr3[3] = {0};
    mult(mat,arr2,arr3);
    for(int i=0 ; i<3;i++){
        arr[i] = (arr3[i]%26) + 65;
    }
    arr[3] = '\0';

}
void decer(char * arr, int ** mat){
int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    int idx = i/3;
    int p=0;

    int arr2[3] = {0};
    for(int i=0 ; i<3;i++){
        arr2[i] = arr[i]-65;
    }
    int arr3[3] = {0};
    mult(mat,arr2,arr3);
    for(int i=0 ; i<3;i++){
        arr[i] = (arr3[i]%26) + 65;
    }
    arr[3] = '\0';
}
int main(){
    srand(time(0));
    char inp[100];
    cin.getline(inp,100);
    int ** key = keygen();
    enc(inp,key);
    cout<<inp<<endl;
    cout<<endl;
    matinv(key);
    decer(inp,key);
    cout<<inp<<endl;


return 0;
}

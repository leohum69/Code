#include <iostream>
using namespace std;
void setstr(char * arr){
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    char * pew = new char[i];
    i=0;
    int j=0;
    while(arr[i]!='\0'){
        if((int)arr[i] > 96 && (int)arr[i] < 123){
            pew[j] = arr[i] - 32;
            j++;
        }else if((int)arr[i] > 64 && (int)arr[i] < 91){
            pew[j] = arr[i];
            j++;
        }
        i++;
    }
    pew[j] = '\0';
    i=0;
    while(arr[i]!='\0'){
        arr[i] = '\0';
        i++;
    }
    i=0;
    while(pew[i]!='\0'){
        arr[i] = pew[i];
        i++;
    }
}
void encrypt(char * inp,int key){
    int i=0;
    while(inp[i]!='\0'){
        i++;
    }
    cout<<i<<endl;
    int idx=0;
    if((i)%key == 0)
        idx = (i) / key;
    else
        idx = ((i)/key) + 1;

    cout<<idx<<endl;

    char ** pew = new char*[idx];
    for(int i=0;i<idx;i++){
        pew[i] = new char[key];
    }
    int l=0;
    int x=0;
    bool chk = false;
    for(int i=0;i<idx;i++){
        for(int j=0 ; j<key;j++){
            if(inp[l]=='\0'){
                chk = true;
                break;
            }
            if(chk)
                break;
            pew[i][j] = inp[l++];
            x=j;
        }
        if(chk)
            break;
    }
    x++;
    while(x<key){
        pew[idx-1][x] = 'X';
        x++;
    }
    l=0;

    for(int i = 0;i<key;i++){
        for(int j=0;j<idx;j++){
            inp[l++] = pew[j][i];
        }
    }
    inp[l] = '\0';
}
void decrypt(char * inp, int key){
    int i=0;
    while(inp[i]!='\0'){
        i++;
    }

    int idx = i/key;
    char ** pew = new char*[key];
    for(int i=0;i<key;i++){
        pew[i] = new char[idx];
    }
    int l=0;
    for(int i=0;i<key;i++){
        for(int j=0;j<idx;j++){
            pew[i][j] = inp[l++];
        }
    }

    l=0;
    for(int i=0;i<idx;i++){
        for(int j=0;j<key;j++){
            inp[l++] = pew[j][i];
        }
    }
    inp[l] = '\0';

}

int main(){
    char inp[100];
    cout<<"Enter The PlainText: ";
    cin.getline(inp,100);
    setstr(inp);
    encrypt(inp,5);
    cout<<"Encrypted msg: ";
    cout<<inp<<endl;
    decrypt(inp,5);
    cout<<"Decrypted msg: ";
    cout<<inp<<endl;

return 0;
}

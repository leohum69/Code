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
char* newkeygen(char * key, char* pt){
    int i=0,j=0,k=0,l=0;;
    while(pt[i]!='\0'){
        i++;
    }
    while(key[j]!='\0'){
        j++;
    }
    char * newarr = new char[i];
    while(k<i){
        if(l == j-1)
            l=0;
        newarr[k] = key[l];
        k++;
        l++;
    }
    newarr[k] = '\0';
    return newarr;
}

int main(){
    char input[100];
    char key[50];
    cout<<"Enter PlainText: ";
    cin.getline(input,100);
    cout<<"Enter Key: ";
    cin.getline(key,50);
    setstr(input);
    setstr(key);
    //cout<<input<<endl<<key<<endl;
    char * newkey = newkeygen(key,input);
    //cout<<newkey<<endl;
    cout<<"Encrypted Text: ";
    int i=0;
    while(input[i] != '\0'){
        input[i] = ((input[i] + newkey[i]) % 26) + 'A';
        i++;
    }
    cout<<input<<endl;
    cout<<"Decrypted Text: ";
    i=0;
    while(input[i] != '\0'){
        input[i] = (((input[i] - newkey[i]) + 26) % 26) + 'A';
        i++;
    }
    cout<<input<<endl;




return 0;
}

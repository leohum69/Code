#include <iostream>
using namespace std;
void decrypt(char* inp,int key){
    int i=0;
    while(inp[i]!='\0'){
            if((int)inp[i] > 64 && (int)inp[i] < 91){
                inp[i] = inp[i] - key;
                if((int)inp[i] < 65)
                    inp[i]=inp[i]+26;
            }
            else if((int)inp[i] > 96 && (int)inp[i] < 123){
                inp[i] = inp[i] - key;
                if((int)inp[i] < 97)
                    inp[i]=inp[i]+26;
            }
            i++;
    }
}


void cracker(char* inp){
    int i=0;
    while(inp[i]!='\0'){
        i++;
    }
    char* meow = new char[i+1];
    i=0;
    while(inp[i]!='\0'){
        meow[i] = inp[i];
        i++;
    }
    int j=0;
    meow[i] = '\0';
    for(int i = 1; i<27;i++){
        decrypt(meow,i);
        cout<<i<<"th : "<<meow<<endl;
        j=0;
        while(inp[j]!='\0'){
            meow[j] = inp[j];
            j++;
        }
    }

}

int main(){
    char inp[100];
    cout<<"Enter the Encrypted Text: ";
    cin.getline(inp,100);
    cracker(inp);
return 0;
}

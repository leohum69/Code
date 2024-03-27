#include <iostream>
using namespace std;

void encrypt(char* inp){
    int i=0;
    while(inp[i]!='\0'){
            if((int)inp[i] > 64 && (int)inp[i] < 91){
                inp[i] = inp[i] + 3;
                if((int)inp[i] > 90)
                    inp[i]=inp[i]-26;
            }
            else if((int)inp[i] > 96 && (int)inp[i] < 123){
                inp[i] = inp[i] + 3;
                if((int)inp[i] > 122)
                    inp[i]=inp[i]-26;
            }
            i++;
    }
}
void decrypt(char* inp){
    int i=0;
    while(inp[i]!='\0'){
            if((int)inp[i] > 64 && (int)inp[i] < 91){
                inp[i] = inp[i] - 3;
                if((int)inp[i] < 65)
                    inp[i]=inp[i]+26;
            }
            else if((int)inp[i] > 96 && (int)inp[i] < 123){
                inp[i] = inp[i] - 3;
                if((int)inp[i] < 97)
                    inp[i]=inp[i]+26;
            }
            i++;
    }
}



int main(){
    char meow[100];
    cout<<"Enter PlainText: ";
    cin.getline(meow,100);
    encrypt(meow);
    cout<<"After Encryption: ";
    cout<<meow<<endl;
    cout<<"after Decryption: ";
    decrypt(meow);
    cout<<meow<<endl;

return 0;
}

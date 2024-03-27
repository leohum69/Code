#include <iostream>
using namespace std;
char cipher[] = "PQWOIERUYTASKLDJHFGZCXVBMN";
char cipher2[] = "pqwoieruytaskldjhfgzcxvbmn";
int sear(char letter,char* arr){
    int i=0;
    while(arr[i]!='\0'){
        if(arr[i] == letter)
            return i;
        i++;
    }
    return -1;
}

void enc(char* input){
    int diff=0;
    int i=0;
    while(input[i]!='\0'){
        if((int)input[i] > 64 && (int)input[i] < 91){
            diff = input[i] - 65;
            input[i] = cipher[diff];
        }else if((int)input[i] > 96 && (int)input[i] < 123){
            diff = input[i] - 97;
            input[i] = cipher2[diff];
        }
        i++;
    }
}
void dec(char* input){
    int i=0;
    int idx = 0;
    while(input[i]!='\0'){
        if((int)input[i] > 64 && (int)input[i] < 91){
            idx = sear(input[i],cipher);
            input[i] = static_cast<char>(idx + 65);
        }else if((int)input[i] > 96 && (int)input[i] < 123){
            idx = sear(input[i],cipher2);
            input[i] = static_cast<char>(idx + 97);
        }
        i++;
    }
}
int main(){
    char input[100];
    cout<<"Input you PlainText: ";
    cin.getline(input,100);
    cout<<"After Encryption: ";
    enc(input);
    cout<<input<<endl;
    dec(input);
    cout<<"after Decryption: ";
    cout<<input<<endl;

return 0;
}

#include <iostream>

using namespace std;
int count_words(string arr[],int total_sen);
string *words_list(string sent[],int total_sen,int word_count);
int main(){
	int words=0;
	string corpus []= {"hello i am sara.","how is life going on?","things are very complicated here.","life is very short."};
	words=count_words(corpus,4);
	cout<<words<<endl;
	string *arr=words_list(corpus,4,words);
	cout<<"{";
	for(int i=0;i<words;i++){
		cout<<arr[i]<<",";
	}
	cout<<"}"<<endl;
	
	
	return 0;
}

int count_words(string arr[],int total_sen){
	int words=0;
	int j=0;
	for(int i=0;i<total_sen;i++){
		while(arr[i][j]!='\0'){
			if(arr[i][j]==' ')
				words++;
			if(arr[i][j]=='.')
				words++;
			if(arr[i][j]=='?')
				words++;
			j++;
		}
		j=0;
	}
	return words;
}
string *words_list(string sent[],int total_sen,int word_count){
	int i=0;
	int i2=0;
	int c=0;
	string arr[word_count];
	string *ptr=arr;
	for(int j=0;j<total_sen;j++){
		while(sent[j][c]!='\0'){
			if(sent[j][c]==' ')
				i2++;
			if(sent[j][c]=='.')
				i2++;
			if(sent[j][c]=='?')
				i2++;
			arr[i2][i]=sent[j][c];
			c++;
			i++;
		}
	}
	return ptr;
	
}

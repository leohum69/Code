/*
 * TextBook.cpp
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#include "TextBook.h"

TextBook::TextBook() {
	cout<<"Inside TextBook Constuctor"<<endl;
	this->title = "\0";
	this->author = "\0";
	this->book_id = 0;
}
TextBook::TextBook(string a,string b,int c):title(a),author(b),book_id(c){

}
void TextBook::Set(){
	cout<<"Enter Title: ";
	getline(cin,title);
	cout<<"Enter Author: ";
	getline(cin,author);
	cout<<"Enter Book id: ";
	cin>>book_id;
}
void TextBook::Print(){
	cout<<"Title : "<<this->title<<endl;
	cout<<"Author : "<<this->author<<endl;
	cout<<"Book id : "<<this->book_id<<endl;
}
TextBook::~TextBook() {
	// TODO Auto-generated destructor stub
}


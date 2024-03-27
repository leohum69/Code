/*
 * FaceBook.cpp
 *
 *  Created on: Mar 15, 2023
 *      Author: lab
 */

#include "FaceBook.h"

FaceBook::FaceBook() {
	contact = new char[50];
}
FaceBook::FaceBook(string a,string b, char c, char * d){
	name = a;
	email = b;
	gender = c;
	contact = new char[100];
	int i=0;
	while(d[i] != '\0'){
		i++;
	}
	for(int j=0;j<i;j++){
		contact[j] = d[j];
	}
	contact[i]='\0';

}

char* FaceBook::getContact() const {
	return contact;
}

void FaceBook::setContact(char *cont) {
	delete []contact;
	contact = new char[100];
	int i=0;
	while(cont[i] != '\0'){
		contact[i] = cont[i];
	}
	contact [i] = '\0';
}

const string& FaceBook::getEmail() const {
	return email;
}

void FaceBook::setEmail(const string &email) {
	this->email = email;
}

char FaceBook::getGender() const {
	return gender;
}

void FaceBook::setGender(char gender) {
	this->gender = gender;
}

const string& FaceBook::getName() const {
	return name;
}

void FaceBook::setName(const string &name) {
	this->name = name;
}


FaceBook::~FaceBook() {
	delete []contact;
}


/*
 * FaceBook.h
 *
 *  Created on: Mar 15, 2023
 *      Author: lab
 */

#ifndef FACEBOOK_H_
#define FACEBOOK_H_
#include <iostream>
#include <string>
using namespace std;

class FaceBook {
	string name;
	string email;
	char gender;
	char *contact;

public:
	FaceBook();
	FaceBook(string,string,char,char *);
	virtual ~FaceBook();
	char* getContact() const;
	void setContact(char *cont);
	const string& getEmail() const;
	void setEmail(const string &email);
	char getGender() const;
	void setGender(char gender);
	const string& getName() const;
	void setName(const string &name);
};

#endif /* FACEBOOK_H_ */

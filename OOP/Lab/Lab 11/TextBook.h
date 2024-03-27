/*
 * TextBook.h
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#ifndef TEXTBOOK_H_
#define TEXTBOOK_H_
#include <iostream>
#include <string>
using namespace std;

class TextBook {
	string title;
	string author;
	int book_id;
public:
	TextBook();
	TextBook(string,string,int);
	void Set();
	void Print();
	virtual ~TextBook();
};

#endif /* TEXTBOOK_H_ */

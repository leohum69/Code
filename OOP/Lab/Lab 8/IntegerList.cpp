/*
 * IntegerList.cpp
 *
 *  Created on: Mar 15, 2023
 *      Author: lab
 */

#include "IntegerList.h"

IntegerList::IntegerList(int a){
	numElements = a;
	list = new int[a];
	size = a;
	for(int i=0;i<a;i++){
		*(list+i) = 0;
	}

}
IntegerList::IntegerList(IntegerList &copy){
	this->numElements = copy.numElements;
	this->size = copy.size;
	this->list = new int[numElements];
	for(int i=0;i<this->numElements;i++){
			*(list+i) = copy.list[i];
		}
}
bool IntegerList::isValid(int a){
	if(a >= 0 && a <= (numElements-1))
		return true;
	else
		return false;
}
void IntegerList::setElement(int a, int b){
	if(isValid(a) == true){
		this->list[a] = b;
	}else
		exit(EXIT_FAILURE);
}
int IntegerList::getElement(int a){
	if(isValid(a) == true){
		return this->list[a];
	}else
		exit(EXIT_FAILURE);
}
IntegerList::~IntegerList() {
	delete []list;
}


/*
 * Course.h
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#ifndef COURSE_H_
#define COURSE_H_
#include "Instructor.h"
#include "TextBook.h"
class Course {
	Instructor Ins;
	TextBook Tex;
public:
	Course();
	void setter();
	void Print();
	virtual ~Course();
};

#endif /* COURSE_H_ */

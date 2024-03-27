/*
 * Student.cpp
 *
 *  Created on: Mar 1, 2023
 *      Author: lab
 */

#include "Student.h"

Student::Student() {
	cout<<"Default Constructer"<<endl;

}
Student::Student(string n,int a){
	this->name=n;
	this->age=a;
}
void Student::SetName(string n){
	name=n;
}
string Student::GetName(){
	return name;
}
void Student::SetRoll(string b){
	roll=b;
}
string Student::GetRoll(){
	return roll;
}
void Student::SetAge(int a){
	age=a;
}
int Student::GetAge(){
	return age;
}
void Student::SetCgpa(double x){
	cgpa=x;
}
double Student::GetCgpa(){
	return cgpa;
}
void Student::print(){
	cout<<"Name: "<<name<<endl;
	cout<<"Roll Number: "<<roll<<endl;
	cout<<"Age: "<<age<<endl;
	cout<<"Cgpa:"<<cgpa<<endl;

}
Student::~Student() {
	// TODO Auto-generated destructor stub
}

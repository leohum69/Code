/*
 * Block.cpp
 *
 *  Created on: Mar 8, 2023
 *      Author: lab
 */

#include "Block.h"


int Block::countofBlocks = 0;
Block::Block():material("card") {
	countofBlocks++;
}
Block::Block(int l,int w,int h,string clr,string mater):material(mater){
	this->Length=l;
	this->Width=w;
	this->Height=h;
	this->color=clr;
	countofBlocks++;
}

const string Block::getColor() const {
	return color;
}

void Block::setColor(const string &color) {
	this->color = color;
}

int Block::getHeight() const {
	return Height;
}

void Block::setHeight(int height) {
	this->Height = height;
}

int Block::getLength() const {
	return Length;
}

void Block::setLength(int length) {
	this->Length = length;
}

const string Block::getMaterial() const {
	return material;
}

int Block::getWidth() const {
	return Width;
}

void Block::setWidth(int width) {
	this->Width = width;
}
int Block::getVolume(){
	return Length*Width*Height;
}
int Block::getSurfaceArea(){
	return 2*((Length * Width)+(Length * Height)+(Width * Height));
}
void Block::print() const{
	cout<<"Length: " << Length <<endl;
	cout<<"Width: " << Width <<endl;
	cout<<"Height: " << Height <<endl;
	cout<<"Material: " << material <<endl;
	cout<<"Color: "<< color <<endl;
	cout<<"Volume: " << (Length*Width*Height) <<endl;
	cout<<"Surface Area: "<< 2*((Length * Width)+(Length * Height)+(Width * Height)) <<endl;

}
int static getcount(){
	return Block::countofBlocks;
}

Block::~Block() {
	// TODO Auto-generated destructor stub
}


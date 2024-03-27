/*
 * Block.h
 *
 *  Created on: Mar 8, 2023
 *      Author: lab
 */

#ifndef BLOCK_H_
#define BLOCK_H_
#include <string>
#include <iostream>
using namespace std;

class Block {
	int Length;
	int Width;
	int Height;
	string color;
	const string material;
public:
	static int countofBlocks;
	Block();
	Block(int l,int w,int h,string clr,string mater);
	const string getColor() const;
	void setColor(const string &color);
	int getHeight() const;
	void setHeight(int height);
	int getLength() const;
	void setLength(int length);
	const string getMaterial() const;
	int getWidth() const;
	void setWidth(int width);
	int getVolume();
	int getSurfaceArea();
	void print() const;
	static int getcount();
	virtual ~Block();

};
#endif /* BLOCK_H_ */

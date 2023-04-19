#pragma once
//
// Name:	Korfali, Khaled
// Project:	5
// Due: 	04-19-2023
// Course:	cs-2560-01-sp23
//
// Description:
//		This code defines the IntArray class, which is
//		a dynamic array that allows for resizing and varius
//		operations on its elements. Implementation is done
//		in IntArray.cpp.
//

#include<string>

class IntArray
{
private:
	int size;
	int numOfElements;
	int* dynamicIntArray;
public:
	IntArray(int size = 100);
	~IntArray();
	int getLength() const;
	int get(int index) const;
	bool add(int value);
	void set(int index, int value);
	int* toArray() const;
	std::string toString() const;
};
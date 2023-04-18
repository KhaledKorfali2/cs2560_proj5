#include"IntArray.h"
#include<sstream>
#include<string>
#include<iostream>

IntArray::IntArray(int size)
{
	this->size = size;
	numOfElements = 0;
	dynamicIntArray = new int[size];
}


IntArray::~IntArray()
{
	delete[] dynamicIntArray;
}


int IntArray::getLength() const
{
	return numOfElements;
}

int IntArray::get(int index) const
{
	if (index < 0 || index >= numOfElements)
	{
		std::cerr << "IntArray: index " << index << " out of bound" << std::endl;
		exit(1);
	}


	return *(dynamicIntArray + index);
}

bool IntArray::add(int value)
{
	numOfElements += 1;
	if (numOfElements == size)
	{
		size *= 2;
		int* newDynamicIntArray = new int[size];
		for (int i = 0; i < numOfElements; i++) 
		{
			*(newDynamicIntArray + i) = *(dynamicIntArray + i);
		}

		delete[] dynamicIntArray;
		dynamicIntArray = newDynamicIntArray;
	}
	*(dynamicIntArray + numOfElements - 1) = value;
	return true;
}


void IntArray::set(int index, int value)
{
	if (index < 0 || index >= numOfElements)
	{
		std::cerr << "IntArray: index " << index << " out of bound" << std::endl;
		exit(1);
	}

	*(dynamicIntArray + index) = value;
}

int* IntArray::toArray() const
{
	int* newArray = new int[numOfElements];
	for (int i = 0; i < numOfElements; i++) {
		*(newArray + i) = *(dynamicIntArray + i);
	}
	return newArray;
}

std::string IntArray::toString() const
{
	std::stringstream buffer;
	for (int i = 0; i < numOfElements; i++)
	{
		buffer << *(dynamicIntArray + i);
		if (i != numOfElements - 1)
		{
			buffer << ",";
		}
	}

	return buffer.str();
}
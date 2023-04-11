#include"IntArray.h"
#include<sstream>
#include<string>
#include<iostream>

IntArray::IntArray(int size = 100)
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
	return size;
}

int IntArray::get(int index) const
{
	return *(dynamicIntArray + index);
}

bool IntArray::add(int value)
{
	numOfElements += 1;
	if (numOfElements == size)
	{
		size *= 2;
		int* newDynamicIntArray = new int[size];
		for (int i = 0; i < numOfElements; i++) {
			*(newDynamicIntArray + i) = *(dynamicIntArray + i);
		}

		delete[] dynamicIntArray;
		dynamicIntArray = newDynamicIntArray;
	}
	*(dynamicIntArray + numOfElements) = value;
}
void IntArray::set(int index, int value)
{
	*(dynamicIntArray + index) = value;
}

int* IntArray::toArray()
{
	return dynamicIntArray;
}

std::string IntArray::toString()
{
	std::stringstream buffer;
	for (int i = 0; i < size; i++)
	{
		buffer << *(dynamicIntArray + i);
		if (i != size - 1)
		{
			buffer << ", ";
		}
	}

	return buffer.str();
}
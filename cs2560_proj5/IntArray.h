#pragma once

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
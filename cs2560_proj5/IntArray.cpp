#include"IntArray.h"
#include<sstream>
#include<string>
#include<iostream>

// Constructor for IntArray class
IntArray::IntArray(int size)
{
	// Size of the dynamic array is set
	this->size = size;
	// Number of elements currently in the array is initialized to zero
	numOfElements = 0;
	// Memory is allocated for the dynamic array
	dynamicIntArray = new int[size];
}

// Destructor for IntArray class
IntArray::~IntArray()
{
	// Dynamic array memory is freed
	delete[] dynamicIntArray;
}

// Returns the number of elements in the array
int IntArray::getLength() const
{
	return numOfElements;
}

// Returns the element at a given index in the array
int IntArray::get(int index) const
{
	// Checks if the index is within bounds of the array
	if (index < 0 || index >= numOfElements)
	{
		// Prints an error message and terminates the program if the index is out of bounds
		std::cerr << "IntArray: index " << index << " out of bound" << std::endl;
		exit(1);
	}

	// Returns the value at the given index in the dynamic array
	return *(dynamicIntArray + index);
}

// Adds a value to the end of the array
bool IntArray::add(int value)
{
	// Increases the number of elements in the array by one
	numOfElements += 1;

	// If the number of elements has reached the current size of the dynamic array
	if (numOfElements == size)
	{
		// Doubles the size of the dynamic array
		size *= 2;

		// Allocates memory for a new dynamic array with the new size
		int* newDynamicIntArray = new int[size];

		// Copies the values of the old dynamic array to the new dynamic array
		for (int i = 0; i < numOfElements; i++) 
		{
			*(newDynamicIntArray + i) = *(dynamicIntArray + i);
		}

		// Frees the memory of the old dynamic array
		delete[] dynamicIntArray;

		// The pointer of the old dynamic array now points to the new dynamic array
		dynamicIntArray = newDynamicIntArray;
	}
	// Sets the value at the end of the dynamic array to the new value
	*(dynamicIntArray + numOfElements - 1) = value;

	return true; // Always returns true for the sake of this program
}

// Sets the value at a given index in the array to a new value
void IntArray::set(int index, int value)
{
	// Checks if the index is within bounds of the array
	if (index < 0 || index >= numOfElements)
	{
		// Prints an error message and terminates the program if the index is out of bounds
		std::cerr << "IntArray: index " << index << " out of bound" << std::endl;
		exit(1);
	}
	// Sets the value at the given index in the dynamic array to the new value
	*(dynamicIntArray + index) = value;
}

// Converts the dynamic array to a regular array and returns a pointer to it
int* IntArray::toArray() const
{
	// Allocates memory for a new array with the same size as the dynamic array
	int* newArray = new int[numOfElements];
	// Copies the values of the dynamic array to the new array
	for (int i = 0; i < numOfElements; i++) {
		*(newArray + i) = *(dynamicIntArray + i);
	}
	// Returns a pointer to the new array
	return newArray;
}

// This function converts the array to a string representation
std::string IntArray::toString() const
{
	// A stringstream is used to create a buffer for the string
	std::stringstream buffer;

	// Iterate over the elements in the array
	for (int i = 0; i < numOfElements; i++)
	{
		// Append the current element to the buffer
		buffer << *(dynamicIntArray + i);

		// If this is not the last element in the array, append a comma
		if (i != numOfElements - 1)
		{
			buffer << ",";
		}
	}

	// Return the string representation of the buffer
	return buffer.str();
}
//
// Name:	Korfali, Khaled
// Project:	5
// Due: 	04-19-2023
// Course:	cs-2560-01-sp23
//
// Description:
//		This code reads a list of integers from a file named "input.dat"
//		and stores them in an IntArray object. It then calculates the sum
//		and average of the integers in the array and displays the results.
//		The program also includes testing/debugging functionality to generate
//		a random input file containing integers between -999 and 9999.
//
#include"IntArray.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<ctime>

using namespace std;

//Pre-processor directives (uncomment to gain access to debug/testing functions)
//#define DEBUG


#ifdef DEBUG
void generateRandomInputFile();
#endif // DEBUG

int main()
{
	#ifdef DEBUG
	// Testing/Debug Purpose: Generate a .dat file with random numbers 
	// between -999 and 9999
	generateRandomInputFile();
	#endif // DEBUG

	// Variables
	IntArray myIntArray(5);

	string fileName = "input.dat";

	ifstream inFile(fileName);

	int sum = 0;
	int number;

	double average;

	// Display header
	cout << "IntArray by K. Korfali" << endl << endl;

	// Output error message if file not successfully opened
	if (!inFile.is_open())
	{
		cerr << "Failed to open file " << fileName << endl;
		return 1;
	}

	// Read numbers line by line from file and put them in IntArray
	while (inFile >> number)
	{
		myIntArray.add(number);
	}

	// Close file
	inFile.close();

	// Convert IntArray to array of integers using toArray
	int* intArray = myIntArray.toArray();

	// Calculate the sum of elements in intArray
	for (int i = 0; i < myIntArray.getLength(); i++) 
	{
		sum += intArray[i];
	}

	// Calculates the average of elements in intArray
	if (myIntArray.getLength() > 0) 
	{
		average = static_cast<double>(sum) / myIntArray.getLength();
	}
	else // If no elements in array then average defualts to zero
	{
		average = 0;
	}

	// Display outputs
	cout << "Data count = " << myIntArray.getLength() << endl;
	cout << "Values = " << myIntArray.toString() << endl;
	cout << "Sum = " << sum << endl;
	cout << "Average = " << setprecision(1) << fixed << showpoint << average << endl;
	cout << endl;
	
	// Test member functions not used in a-d
	cout << "Element at end of array before calling myIntArray.set(" << myIntArray.getLength() - 1 << ", 100): " << myIntArray.get(myIntArray.getLength() - 1) << endl;
	myIntArray.set(myIntArray.getLength() - 1, 100); // Set 10th element to 100
	cout << "Element at end of array after calling myIntArray.set(" << myIntArray.getLength() - 1 << ", 100): " << myIntArray.get(myIntArray.getLength() - 1) << endl;


	// Memory management
	delete[] intArray;

	// Return zero to indicate succsesful execution of program
	return 0;
}


#ifdef DEBUG
// Function that generates a .dat file containing random numbers
// between -999 and 9999
void generateRandomInputFile()
{
	ofstream file;
	file.open("input.dat");
	srand(time(0));
	int cap = rand() % 500;
	for (int i = 0; i < cap; i++)
	{
		file << rand() % 10999 - 999 << endl;
	}

	file.close();
}
#endif // DEBUG

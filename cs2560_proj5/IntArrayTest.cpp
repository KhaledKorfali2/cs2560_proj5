//
// Name:	Korfali, Khaled
// Project:	5
// Due: 	04-10-2023
// Course:	cs-2560-01-sp23
//
// Description:
//		This code 
//
#include"IntArray.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<ctime>

using namespace std;

//Pre-processor directives (uncomment to gain access to debug/testing functions)
#define DEBUG


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
	IntArray myIntArray(50);

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
	for (int i = 0; i < myIntArray.getLength(); i++) {
		sum += intArray[i];
	}

	// Calculates the average of elements in intArray
	if (myIntArray.getLength() > 0) {
		average = static_cast<double>(sum) / myIntArray.getLength();
	}

	// Display outputs
	cout << "Data count = " << myIntArray.getLength() << endl;
	cout << "Values = " << myIntArray.toString() << endl;
	cout << "Sum = " << sum << endl;
	cout << "Average = " << setprecision(1) << fixed << showpoint << average << endl;

	

	// Test member functions not used in a-d
	cout << "Element at index 10 before myIntArray.set(10, 100): " << myIntArray.get(10) << endl;
	myIntArray.set(10, 100); // Set 10th element to 10
	cout << "Element at index 10 after myIntArray.set(10, 100): " << myIntArray.get(10) << endl;
	cout << "Testing error handling of set and get: " << endl;
	cout << "Set: ";
	myIntArray.set(myIntArray.getLength(), 100); // Set an out of bounds element to 10 (outputs error)
	cout << "Get: ";
	myIntArray.get(myIntArray.getLength()); // Get an out of bounds element (outputs error)
	
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
	for (int i = 0; i < 100; i++)
	{
		file << rand() % 10999 - 999 << endl;
	}

	file.close();
}
#endif // DEBUG

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

	for (int i = 0; i < myIntArray.getLength(); i++) {
		sum += intArray[i];
	}
	if (myIntArray.getLength() > 0) {
		average = static_cast<double>(sum) / myIntArray.getLength();
	}

	cout << "Data count = " << myIntArray.getLength() << endl;
	cout << "Values = " << myIntArray.toString() << endl;
	cout << "Sum = " << sum << endl;
	cout << "Average = " << setprecision(1) << fixed << showpoint << average << endl;

	

	// Test member functions not used in a-d
	cout << "Element at index 10 before myIntArray.set(10, 100): " << myIntArray.get(10) << endl;
	myIntArray.set(10, 100); // Set 10th element to 10
	cout << "Element at index 10 after myIntArray.set(10, 100): " << myIntArray.get(10) << endl;


	cout << "Element at index 100: " << myIntArray.get(100) << endl; // should output error message

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

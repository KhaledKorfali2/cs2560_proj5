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
#include<fstream>
#include<string>

double  calcAverage(const IntArray& arr, int sum);


using namespace std;
int main()
{
	IntArray myArray;
	string fileName = "input.dat";
	ifstream inFile(fileName);

	int sum = 0;
	int number;
	if (!inFile.is_open())
	{
		cerr << "Failed to open file " << fileName << endl;
		return 1;
	}

	while (inFile >> number)
	{
		sum += number;
		myArray.add(number);
	}

	cout << "Data count = " << myArray.toString() << endl;
	cout << "Values = " << myArray.toString() << endl;
	cout << "Sum = " << sum << endl;

	
	cout << "Average = " << calcAverage(myArray, sum) << endl;

	return 0;
}

double  calcAverage(const IntArray &arr, int sum)
{
	return static_cast<double>(sum) / arr.getLength();
}

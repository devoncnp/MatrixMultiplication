//Collaborated with Brayden Eiland
//referenced http://www.geeksforgeeks.org/dynamic-programming-set-8-matrix-chain-multiplication/
//for assistance, as it illustrated dynamic matix multiplication wel

#include<stdio.h>
#include<limits.h>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//allocating length of 100 for the array to use
const int MaxInputs = 100;

//open file program
bool openfile(ifstream &infile) {
	string file;
	cout << "What's the name of the file?\nIf your file isn't working, starter.txt is an option you can use" << endl;
	cin >> file;

	infile.open(file);
	if (!infile)
	{
		cout << " File did not open Properly!" << endl;
		return false;
	}
	return true;
}

//reading in the file into an array program
int* ReadFile(ifstream &infile, int list[]) {
	int line = 0;
	while (!infile.eof())
	{
		for (int i = 0; i < MaxInputs; i++)
		{
			infile >> list[i];
		}
	}
	return list;
}


void MatrixChainOrder(int matricies[], int size)
{
	int length, cost;
	//initializing a 2d array with size by size to dynamically multiply
	//the list of maticies
	int** dynamicArray = new int*[size];
	for (int i = 0; i < size; i++)
		dynamicArray[i] = new int[size];	

	//dynamic array is set to equal the minimal amount of multiplations needed to
	//multiply the matricies

	// cost is zero when multiplying one matrix.
	for (int i = 1; i<size; i++)
		dynamicArray[i][i] = 0;

	// length is the amount of matricies being multiplied starting at 2.
	for (length = 2; length<size; length++)
	{
		for (int i = 1; i<size - length + 1; i++)
		{
			int j = i + length - 1;
			dynamicArray[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				// figuring out the cost of multiplying the matricies
				cost = dynamicArray[i][k] + dynamicArray[k + 1][j] + matricies[i - 1] * matricies[k] * matricies[j];
				cout << cost << endl;
				if (cost < dynamicArray[i][j]) {
					dynamicArray[i][j] = cost;
				}
			}
		}
	}
	cout << "Minimum number of multiplications is " << dynamicArray[1][size - 1];
}

int main()
{
	int size = 0;
	int* matriciesArray = new int[MaxInputs];
	ifstream infile;
	
	//initializing array of matricies
	for (int i = 0; i < MaxInputs; i++)
		matriciesArray[i] = 0;
		
	//openfile stuff
	openfile(infile);
	matriciesArray = ReadFile(infile, matriciesArray);

	//getting the size of the array after ran through the file.
	for (int i = 0; i < MaxInputs; i++)
	{
		if (matriciesArray[i] != 0)
			size++;
	}

	
	MatrixChainOrder(matriciesArray, size);

	system("pause");
	return 0;
}
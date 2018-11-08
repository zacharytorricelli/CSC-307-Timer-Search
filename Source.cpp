//
//  Homework 6 - 307
//
//  Created by Zachary Torricelli on 2/28/18.
//  Copyright © 2018 Zachary Torricelli. All rights reserved.
//
//  •    Open a text file
//  •    Create an array of 100 random numbers of values 0-99
//  •    Output your array of numbers to your text file
//  •    Apply the Selection Sort to your array of numbers
//  •    Output your array of numbers to your text file again
//  •    Close your file
//
//  The sorting function algorithms came from the textbook.
//  Title: C++ Programming From Problem Analysis to Program Design
//  Author: D.S. Malik
//  February 1, 2018
//  All Rights Reserved
//


// Header Files used in this program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>


using namespace std;


// Constant integer for size declared to 100
const int SIZE = 100;

// Function prototype for selectionSort
void selectionSort(int[], const int, ofstream&, int arrayNumber);
void bubbleSort(int[], const int, ofstream&);
void insertionSort(int[], const int, ofstream&);
void fillArray(int[], int[], int[], int[]);
void copyArray(int[], int[], int[], int[]);
void print(int[], int[], int[], int[], ofstream&);


// ChronoTimer Function
unsigned long long fib(unsigned long long n)
{
	
	return (0 == n || 1 == n) ? 1 : fib(n - 1) + fib(n - 2);

}

int main() {


	// Declares file stream variables
	ofstream outDataArray;
	ofstream outDataTimer;

	// Opens the output files
	outDataArray.open("arrays.txt");
	outDataTimer.open("timer.txt");



		// Declares arrays of size 100
		int numberArray1[SIZE];
		int numberArray2[SIZE];
		int numberArray3[SIZE];
		int numberArray4[SIZE];

		// Sets the seed
		srand(static_cast<unsigned int>(time(0)));

		// Adds a header to the output file
		outDataTimer << "\t\t Selection Sort" << "\t\t Bubble Sort" << "\t\t Insertion Sort" << endl;

		// Calls and executes the function fillArray
		fillArray(numberArray1, numberArray2, numberArray3, numberArray4);

		

		// Calls and excecutes the function copyArray
		copyArray(numberArray1, numberArray2, numberArray3, numberArray4);
			
		// Calls and executes the function selectionSort
		selectionSort(numberArray1, 100, outDataTimer, 1);

		// Calls and executes the function bubbleSort
		bubbleSort(numberArray1, 100, outDataTimer);

		// Calls and executes the function insertionSort
		insertionSort(numberArray1, 100, outDataTimer);

		// Adds a line of space to the output file
		outDataTimer << endl;

		
		
		// Calls and executes the function selectionSort
		selectionSort(numberArray2, 100, outDataTimer, 2);

		// Calls and executes the function bubbleSort
		bubbleSort(numberArray2, 100, outDataTimer);

		// Calls and executes the function insertionSort
		insertionSort(numberArray2, 100, outDataTimer);
		
		// Adds a line of space to the output file
		outDataTimer << endl;

		
		
		// Calls and executes the function selectionSort
		selectionSort(numberArray3, 100, outDataTimer, 3);

		// Calls and executes the function bubbleSort
		bubbleSort(numberArray3, 100, outDataTimer);

		// Calls and executes the function insertionSort
		insertionSort(numberArray3, 100, outDataTimer);

		// Adds a line of space to the output file
		outDataTimer << endl;

		
		
		// Calls and executes the function selectionSort
		selectionSort(numberArray4, 100, outDataTimer, 4);

		// Calls and executes the function bubbleSort
		bubbleSort(numberArray4, 100, outDataTimer);

		// Calls and executes the function insertionSort
		insertionSort(numberArray4, 100, outDataTimer);

		// Adds a line of space to the output file
		outDataTimer << endl;

		
		
		// Calls and executes the print function
		print(numberArray1, numberArray2, numberArray3, numberArray4, outDataArray);

		// Writes the unit of measure to the output file
		outDataTimer << "The unit of measure is microseconds." << endl;


		// Closes the output file
		outDataArray.close();
		outDataTimer.close();

		system("pause");
		return 0;
	
}



// Function to fill the arrays
void fillArray(int numberArray1[], int numberArray2[], int numberArray3[], int numberArray4[])
{

	// For loop to fills the arrays with random numbers between 0 and 99
	for (int i = 0; i < SIZE; i++)
	{

		numberArray1[i] = rand() % (99 - 0) + 0;
		numberArray2[i] = rand() % (99 - 0) + 0;
		numberArray3[i] = rand() % (99 - 0) + 0;
		numberArray4[i] = rand() % (99 - 0) + 0;

	}

}



// Function to make a copy of the arrays
void copyArray(int numberArray1[], int numberArray2[], int numberArray3[], int numberArray4[])
{

	// Variable declaration for this function
	int copy1[SIZE];
	int copy2[SIZE];
	int copy3[SIZE];
	int copy4[SIZE];


	// For loop to copy the array
	for (int i = 0; i < SIZE; i++)
	{

		copy1[i] = numberArray1[i];
		copy2[i] = numberArray2[i];
		copy3[i] = numberArray3[i];
		copy4[i] = numberArray4[i];
		
	}

}



// Selection sort function to sort the numbers
void selectionSort(int numberArray[], const int SIZE, ofstream &outDataTimer, int arrayNumber)
{

	// Starts the timer
	auto start = std::chrono::high_resolution_clock::now();

	// Variable declaration for this function
	int index;
	int smallestIndex;
	int location;
	int temp;


	// Beginning of for loop
	for (index = 0; index < SIZE - 1; index++)
	{

		// Assumes first element is the smallest
		smallestIndex = index;

		for (location = index + 1; location < SIZE; location++)
			if (numberArray[location] < numberArray[smallestIndex])
				smallestIndex = location;

		temp = numberArray[smallestIndex];
		numberArray[smallestIndex] = numberArray[index];
		numberArray[index] = temp;

	} // End of for loop


	// Stops the timer
	auto finish = std::chrono::high_resolution_clock::now();

	// Calculates the total time elapsed and writes it to an output file
	auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
	outDataTimer << "Array " << arrayNumber << "\t\t\t" << microseconds.count() << "µs";
	


}



// Bubble sort function to sort the numbers
void bubbleSort(int numberArray[], const int SIZE, ofstream& outDataTimer)
{

	// Starts the timer
	auto start = std::chrono::high_resolution_clock::now();

	// Variable declaration for this function
	int temp;
	int iteration;
	int index;


	// Beginning of outer for loop
	for (iteration = 1; iteration < SIZE; iteration++)
	{

		// Beginning of inner for loop
		for (index = 0; index < SIZE - iteration; index++)
			if (numberArray[index] > numberArray[index + 1])
			{

				temp = numberArray[index];
				numberArray[index] = numberArray[index + 1];
				numberArray[index + 1] = temp;
			
			} // End of inner for loop

	} // End of outer for loop


	// Stops the timer
	auto finish = std::chrono::high_resolution_clock::now();

	// Calculates the total time elapsed and writes it to an output file
	auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
	outDataTimer << "\t\t\t" << microseconds.count() <<  "µs";


}



// Insertion sort function to sort the numbers
void insertionSort(int numberArray[], const int SIZE, ofstream& outDataTimer)
{

	// Starts the timer
	auto start = std::chrono::high_resolution_clock::now();

	// Variable declaration for this function
	int firstOutOfOrder;
	int location;
	int temp;

	
	// Beginning of outer for loop
	for (firstOutOfOrder = 1; firstOutOfOrder < SIZE; firstOutOfOrder++)
		if (numberArray[firstOutOfOrder] < numberArray[firstOutOfOrder - 1])
		{

			temp = numberArray[firstOutOfOrder];
			location = firstOutOfOrder;

			// Inner do-while loop
			do
			{

				numberArray[location] = numberArray[location - 1];
				location--;

			} while (location > 0 && numberArray[location - 1] > temp);

			numberArray[location] = temp;


		} // End of outer for loop

	
	 // Stops the timer
	auto finish = std::chrono::high_resolution_clock::now();

	// Calculates the total time elapsed and writes it to an output file
	auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
	outDataTimer << "\t\t\t" << microseconds.count() << "µs";

}



// Print function to print the array after insertion sort
void print(int numberArray1[], int numberArray2[], int numberArray3[], int numberArray4[], ofstream &outDataArray)
{

	// Function variable declaration
	int column = 10;


	// Label for array
	outDataArray << "Selection Sort: NumberArray1" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray1[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;


	// Label for array
	outDataArray << "Selection Sort: NumberArray2" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray2[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;


	// Label for array
	outDataArray << "Selection Sort: NumberArray3" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray3[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;


	// Label for array
	outDataArray << "Selection Sort: NumberArray4" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray4[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;


		// Label for array
		outDataArray << "Insertion Sort: NumberArray1" << endl;

		// For loop to output Array1 in a 10x10 table
		for (int i = 0; i < SIZE; i++)
		{

			outDataArray << setw(3) << numberArray1[i] << setw(3);

			if ((i + 1) % column == 0)
			{

				outDataArray << endl;

			}

		}

	// Adds two lines of space
	outDataArray << endl << endl;

	

	// Label for array
	outDataArray << "Insertion Sort: NumberArray2" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray2[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;

	

	// Label for array
	outDataArray << "Insertion Sort: NumberArray3" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray3[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;



	// Label for array
	outDataArray << "Insertion Sort: NumberArray4" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray4[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;



	// Label for array
	outDataArray << "Bubble Sort: NumberArray1" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray1[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;


	// Label for array
	outDataArray << "Bubble Sort: NumberArray2" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray2[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;


	// Label for array
	outDataArray << "Bubble Sort: NumberArray3" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray3[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;


	// Label for array
	outDataArray << "Bubble Sort: NumberArray4" << endl;

	// For loop to output Array1 in a 10x10 table
	for (int i = 0; i < SIZE; i++)
	{

		outDataArray << setw(3) << numberArray4[i] << setw(3);

		if ((i + 1) % column == 0)
		{

			outDataArray << endl;

		}

	}

	// Adds two lines of space
	outDataArray << endl << endl;


}
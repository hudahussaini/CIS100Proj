#include <iostream>
#include <array>
using namespace std;

//Given that arrayIntValues[MAX_ROWS][MAX_COLUMNS] is a 2 dimensional array of positive integers,
//write a C++ function howManyEven to find the total number of even elements in the array.It should have 
//input parameter array arrayIntValues.The function should return an integer.Also create a C++ function called
//printArray, with the input parameter array arrayIntValues, to print out the elements in the array
//(be sure to have row and column labels and proper formatting(i.e.column values line up).
// Main must be in one source file and all other functions in a second source file.

const int MAX_ROWS = 3; 
const int MAX_COLUMNS = 2;


int howmanyeven(int(&arrayintval)[MAX_ROWS][MAX_COLUMNS])
{
	// total number of even elements in array
	int counteven = 0;

	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLUMNS; j++)

		{
			if (arrayintval[i][j] % 2 == 0)

				counteven++;

		}
	}
	//cout << "The number even " << counteven << endl;
	return counteven;

}

void printarray(int(&arrayintval)[MAX_ROWS][MAX_COLUMNS])
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLUMNS; j++)
		{
			cout << arrayintval[i][j] << " ";
			
		}
		cout << endl;
	}

}

void updatevals(int(&arrayintval)[MAX_ROWS][MAX_COLUMNS])
{
	
		cout << "Enter Values \n";
		
			for (int i = 0; i < MAX_ROWS; i++)
			{
				for (int j = 0; j < MAX_COLUMNS; j++)
				{
					cin >> arrayintval[i][j];
					//print array 
				}
			}

}

int main()
{
	int arrayIntValues[MAX_ROWS][MAX_COLUMNS] = { {3 , 2},
											       {4, 5}, 
												   {2, 2} }; //row, columns

	cout << "This how many even " <<  howmanyeven(arrayIntValues) << endl;
	cout << "This is curr array \n";
	printarray(arrayIntValues);

	char decide = 'Y';
	cout << "update vals at least once " ;
	while (decide == 'Y') {
		updatevals(arrayIntValues);

		cout << "new array\n";
		printarray(arrayIntValues);
		cout << "Do you want to add values (Y for yes N for no):  \n";
		cin >> decide;

	}


}

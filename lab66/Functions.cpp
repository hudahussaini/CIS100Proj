#include <iostream>

using namespace std;


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
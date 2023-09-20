// File name: Question2Lab1pointers.cpp 
// Author: Huda Hussaini
// 1/25/22 - Question 2 -  array of 100 integers in the range of - 63 to + 101. Using 4 different array notations. 


#include <iostream>
using namespace std;


int main()
{
	// 100 array w/ -63 to 101
	const int fat = 100;
	int array[fat];
	int* fatPtr = array;

	//idek why
	srand(time(0));

		for (int i = 0; i < fat; i++) {
			//rand % (max - min + 1) + min - IDEK
			array[i] = (rand() % 164-63);

		}
		cout <<  endl;
		cout << endl;

		
		//array notation array[x];

		cout << "Here is array notation " << endl;
		for (int i = 0; i < fat; i++) {
			cout << array[i] << " ";


		}

		cout << endl;
		cout << endl;


		//array offset notation* (myArray + x); Using array offset notation,
		//print all values in the array, from last index to first, on one line, each separated by a space

		cout << "Here is another ~CoOl~ way using offset notation" << endl;
		// could you do 100 instead?
		for (int i = fat; i >= 0; i--) {
			cout << *(array + i) << " ";


		}

		cout << endl;
		cout << endl;
	


		//pointer notation* arrayPtr; 	
		//Using pointer notation, print all negative values on one line, each separated by a space

		cout << "Alr folks its pointer notation time" << endl;
		fatPtr = &array[0];

		for (int i = 0; i < fat; ++i) {
			fatPtr++;
         
			if ((*fatPtr) < 0) {
				cout << *fatPtr << " ";
			
			}



		}

		cout << endl;
		cout << endl;
		
	
	//pointer offset notation* (arrayPtr + x); 
 ///Using pointer offset notation, print all positive values on one line, each separated by a space
		cout << "(pointer) Offset! rain drop, drop top" << endl;
		fatPtr = &array[0];

		for (int i = 0; i < fat; ++i) {

			if (*(fatPtr + i) > 0) {
				cout << (*(fatPtr + i)) << " ";
			}



		}

		cout << endl;
		return 0;
}


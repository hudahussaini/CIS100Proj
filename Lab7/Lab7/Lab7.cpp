// Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// A recursive function to perform a linear search through an array
// Author: Huda Hussaini

#include <iostream>
using namespace std;


int recursiveLinearSearch(int array[], int key, int size, bool& methodStatus) {

	if (array[size] != key) {

		methodStatus = false;

		return 0;

	}

	if (array[size] == key) {

		methodStatus = true;

		return 1;

	}

	return 1 + recursiveLinearSearch(array, key, size - 1, methodStatus);

}

int main()

{

	int const size = 5000;

	int array[size];

	for (int i = 0; i < size; i++) {

		array[i] = i;

	}

	bool methodStatus = false;

	int key;

	

	int contin = 0;

	while (contin == 0) {

		cout << "Enter a Integer..." << endl;
		cin >> key;

		int count = recursiveLinearSearch(array, key, size - 1, methodStatus);


		if (methodStatus) {

			cout << "Key " << key << " found" << endl;

			cout << "Number of recursive call : " << count;

		}
		else {

			cout << "Key " << key << " not found" << endl;

			cout << "Number of recursive call : " << count;
		}
		
		cout << endl << endl;

		cout << "do you want to continue?";
		cin >> contin;
	}

	return 0;

}
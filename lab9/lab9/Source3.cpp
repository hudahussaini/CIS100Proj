//Lab 9 -  array data Structure
//CPP file, author - Huda Husaini
//Update a record, Delete a record, List a record, list All tools, and Quit when finished.
#include <iostream>
using namespace std;

void insertionSort(record unsortArr[], int size) {
	int count = 0;
	record key = { 0, "", 0, 0.0 };
	for (int i = 0; i < size; i++) {
		key = unsortArr[i]; 
		int j = i - 1;  
		while (j >= 0 && unsortArr[j].recordNum > key.recordNum) {
			unsortArr[j + 1] = unsortArr[j];  
			j--;
		}
		unsortArr[j + 1].recordNum = key.recordNum; 
	}
	logFunc("insertionSort function called", count);
}

int main() {
	record recArr[101];
	for (int i = 0; i < 101; i++) {         
		recArr[i] = { 0, "", 0, 0.0 };
	}
	int choice; =
	while (1) {
		cout << "1: Add a Record" << endl;
		cout << "2: Update a Record" << endl;
		cout << "3: Delete a Record" << endl;
		cout << "4: Print a Record" << endl;
		cout << "5: Print All Records" << endl;
		cout << "6: Quit Program" << endl;
		cout << "Choose one of the numbers above: ";
		cin >> choice;
		if (choice == 6)
			break;
		switch (choice) { 
		case 1:
			//writeArray(recArr);
			break;
		case 2:
			cout << "Enter the record number you want to update: " << endl;
			int key1;
			cin >> key1;
			//updateArray(recArr, key1, 101);
			break;
		case 3:
			cout << "Enter the record number you want to delete: " << endl;
			int key3;
			cin >> key3;
			//delArr(recArr, key3, 101);
			break;
		case 4:
			cout << "Enter the record number you want to print out: " << endl;
			int key2;
			cin >> key2;
			//linSearch(recArr, key2, 101);
			break;
		case 5:
			cout << "Records for Unsorted Array" << endl;
			printAll(recArr, 101);
			cout << "Records for Sorted Array" << endl;
			insertionSort(recArr, 101);  //sort array vals
			printAll(recArr, 101);
			break;
		}
	}
	return 0;


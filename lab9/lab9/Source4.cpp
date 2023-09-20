//Lab 9 - Random access file  data Structure
//CPP file, author - Huda Husaini
//Update a record, Delete a record, List a record, list All tools, and Quit when finished.
// Lab8Ram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int toolname_LN = 20;
int count;

struct record {
	int recordnum;
	string toolname;
	int Quantity;
	double cost;
};

void adddata(fstream& recordFile);
void updateData(fstream& recordFile);
void printRecord(fstream& recordFile);
void deleteData(fstream& recordFile);
void printTools(fstream& recordFile);
void menu(fstream& recordFile);

int main()
{
	fstream recordFile;
	recordFile.open("recordlog.txt", ios::in | ios::out | ios::trunc);
	if (recordFile.good() == false)
		std::cout << strerror(errno);

	while (1)
	{
		menu(recordFile);
		std::cout << "\n\Press one to try again...0 to quit\n";

	}
	recordFile.close();
}

void menu(fstream& recordFile)
{
	int count;
	int switchval;
	std::cout << "\n\Press one to update a record, 2 to delete a record, 3 to list a record, 4 to list all tools, 5 to add, or 0 to quit\n";
	std::cin >> switchval;
		switch(switchval) {
		case 0:
			break;
		case 1:
			updateData(recordFile);
		case 2:
			deleteData(recordFile);
		case 3:
			printRecord(recordFile);
		case 4:
			printTools(recordFile);
		case 5:
			adddata(recordFile);
		}
}

void adddata(fstream& recordFile) {
	record myrecord = { 0, "", 0.0, 0.0 };
	string toolName;


	for (int i = 0; i <= 100; i++) {
		recordFile.write(reinterpret_cast<const char*>(&myrecord), sizeof(record));
	}
	//std::cout.flush();
	std::cout << "enter a record num\n"; 
	std::cin >> myrecord.recordnum;
		if (myrecord.recordnum == 0) std::cout <<"no records";
		recordFile.seekp((myrecord.recordnum)*sizeof(record), ios::beg);
		std::cout << "Enter tool name: ";
		std::cin >> toolName;
		for (int i = 0; i < toolName.length(); i++) {
			myrecord.toolname[i] = toolName[i];
		}

		std::cout << "Enter Quantity: ";
		std::cin >> myrecord.Quantity;

		std::cout << "Enter cost: ";
		std::cin >> myrecord.cost;

		recordFile.write(reinterpret_cast<const char*>(&myrecord), sizeof(record));

	}

void updateData(fstream& recordFile) {
	record myrecord = { 0, "", 0.0, 0.0 };
	string toolName;

	std::cout << "Enter the account number or enter 0 to quit: ";
	cin >>myrecord.recordnum;
	if (myrecord.recordnum == 0) return;

	recordFile.seekp((myrecord.recordnum) * sizeof(record), ios::beg);

	std::cout << "Enter new tool name for this record: ";
	cin >> toolName;
	for (int i = 0; i < toolname_LN && i < toolName.length(); i++) {
		myrecord.toolname[i] = toolName.at(i);
	}

	std::cout << "Enter new Quantity: ";
	cin >> myrecord.Quantity;

	std::cout << "Enter new cost: ";
	cin >> myrecord.cost;


	recordFile.write(reinterpret_cast<const char*>(&myrecord), sizeof(record));

	}

void printRecord(fstream& recordFile) {
	record myrecord = { 0, "", 0.0, 0.0 };

	cout << "Enter the account number to read existing data or quit 0: ";
	cout.flush();
	cin >> myrecord.recordnum;
	recordFile.seekg(0 + (myrecord.recordnum) * sizeof(record), ios::beg); //beg of file + size of first so blank dat


	recordFile.read(reinterpret_cast<char*>(&myrecord), sizeof(record));

	cout << myrecord.recordnum << endl << myrecord.toolname <<
		endl << myrecord.Quantity << endl << myrecord.cost << endl;


}

void printTools(fstream& recordFile) {
	recordFile.seekg(0 + sizeof(record), ios::beg); //beg of file + size of first so blank data skipped
	record myrecord = { 0, "", 0.0, 0.0 };

	while (!recordFile.eof()) {


		recordFile.read(reinterpret_cast<char*>(&myrecord), sizeof(record));
		if (recordFile.good() == false) {
			//cout << strerror(errno);
			break;
		}
		if (myrecord.toolname == " ") continue;

		cout << myrecord.toolname << endl;
		recordFile.write(reinterpret_cast<const char*>(&myrecord), sizeof(record));
	}
}

void deleteData(fstream & recordFile)
{
	record myrecord = { 0, "", 0.0, 0.0 };

	cout << "Enter the account number to delete data or quit 0: \n";
	cin >> myrecord.recordnum;
	recordFile.seekg(0 + (myrecord.recordnum) * sizeof(record), ios::beg); //beg of file + size of first so blank dat


	recordFile.read(reinterpret_cast< char*>(&myrecord), sizeof(record));

	cout << myrecord.recordnum << endl << myrecord.toolname <<
		endl << myrecord.Quantity << endl << myrecord.cost << endl;

    cout << "\n\Are you sure you want to delete, press 0 to delete ?: \n ";
	int yes;
	std::cin >> yes; 
	if (yes != 0) std::cout<< "bye";
	else {
		recordFile.seekp((myrecord.recordnum) * sizeof(record), ios::beg);

		myrecord.toolname = " ";
		myrecord.Quantity = 0;
		myrecord.cost= 0;

		recordFile.write(reinterpret_cast<const char*>(&myrecord), sizeof(record));
	}

}

/*
void logger(string mg, int count)
{
	ofstream log("recordlog.txt", std::ios_base::app);
	if (!recordFile.is_open()) cout << "Error opening log file\n" << endl;
	log << mg << " " << to_string(count) << " times" << endl;
	log.close();
}
*/
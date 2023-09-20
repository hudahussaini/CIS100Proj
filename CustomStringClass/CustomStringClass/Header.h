#pragma once
#include <string>
#include <iostream>
using namespace std;

class CustomStringClass {
private:
	int statusvariable;
	//string myString;
	// Initialise the char array
	char* myString;

public:

	CustomStringClass() { myString = NULL; }
	CustomStringClass(const string &s);
	void set(const string &s);
	string get() { return myString; }
	void print() { cout << myString << endl; }

	int size();
	void addStart(const string &a, const string &b);
	void addEnd(const string& a);
	void partString(int startPos, int length); 
	void replPartString(int startPos, int len);
	void replWholeString(string mystring);
	int compareString(const char* s1, const char* s2);
	bool numericString();
	bool alphabeticString();

	~CustomStringClass() { delete myString; }
	

};

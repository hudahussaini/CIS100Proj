#include "Header.h"
#include <cstring>
#include <fstream>


CustomStringClass::CustomStringClass(const string &s) {
	set(s);
}

void CustomStringClass::set(const string &s) {
	//Copying s into myString -- mystring is a new char pointer
	delete myString;
	myString = NULL;

	myString = new char[s.length() + 1];
	for (int i = 0; i < s.length(); i++) {
		myString[i] = s.at(i);
	}
	myString[s.length()] = '\0';
}

int CustomStringClass::size() {
	//returns how many characters are in the string(empty string is size zero)
	cout << strlen(myString);
	return strlen(myString);
}

void CustomStringClass::addStart(const string &b, const string &a){
	int buffer = 100;

	char* mstring = new char[a.length() + 1];
	for (int i = 0; i < a.length(); i++) {
		mstring[i] = a.at(i);
	}
	mstring[a.length()] = '\0'; //takes up all the space from string a 

	char* bstring = new char[b.length() + 1];
	for (int i = 0; i < b.length(); i++) {
		bstring[i] = b.at(i);
	}
	bstring[b.length()] = '\0'; //two letters but index starts at 0 
	//Above was just creating char pointers array with our string letters

	char* tempstr = new char[buffer]; //  buffer size 100 for both chars for our new sentance (mystring)
	
	for (int i = 0; i < a.length(); i++) {
		 tempstr[i]= mstring[i];
	}
	tempstr[a.length()] = ' ';

	
	for (int i = 0; i < b.length(); i++) {
			tempstr[(a.length()+1) + i] = bstring[i];
	}

	tempstr[(a.length() + b.length())+1] = '\0';

	//for (int i = 0; i < ; i++) {
	//	myString[i] = tempstr[i];
	//}
	//tempstr[(a.length() + b.length()) + 1] = '\0';

	//delete tempstr;
	//tempstr = NULL;

	fstream myfile;
	myfile.open("customStringClass.txt");

	if (myfile.is_open())
	{
		myfile << tempstr << endl;

		myfile.close();
	}
	else cout << "Unable to open file";

	cout << "Printing new sentance... " << tempstr << endl;

} 

void CustomStringClass::addEnd(const string& a) {
	// adds the string in the input parameter to the end of the current string
	//try to do vector way
	int buffer = 100;

	char* newstring = new char[a.length() + 1];
	for (int i = 0; i < a.length(); i++) {
		newstring[i] = a.at(i);
	}
	newstring[a.length()] = '\0'; //takes up all the space from string a 

	//Above was just creating char pointers array with our string letters

	char* tempstr = new char[buffer]; //  buffer size 100 for both chars for our new sentance (mystring)

	int SIZE = strlen(myString);
	int sizestr = strlen(newstring);

	for (int i = 0; i < SIZE; i++) {
		tempstr[i] = myString[i];
	}
	tempstr[SIZE] = ' ';

	for (int i = 0; i < a.length(); i++) {
		tempstr[(SIZE + 1) + i] = newstring[i];
	}

	tempstr[SIZE + sizestr] = '\0';

	//for (int i = 0; i < (a.length() + b.length() + 1); i++) {
	//	myString[i] = tempstr[i];
	//}
	//tempstr[(a.length() + b.length()) + 1] = '\0';

	//delete tempstr;
	//tempstr = NULL;
	fstream myfile;
	myfile.open("customStringClass.txt");

	if (myfile.is_open())
	{
		myfile << tempstr << endl;

		myfile.close();
	}
	else cout << "Unable to open file";
	cout << "Printing a longer sentance... " << tempstr << endl;
}

void CustomStringClass::partString(int startPos, int length) {
	//returns as myString that portion from startPos for length given. Handle startPos < 0 & > size; 
	//startPos + length > size; startPos == size returns null string

	cout << "Hello there, your current string is  *" << myString << "*" << endl;

	if (startPos < 0) {
		cout << "Please enter a real length afer 0" << endl;
	}
	if (startPos > strlen(myString)) {
		cout << "Um too long" << endl;
	}
	if (startPos + length > strlen(myString)) {
		cout << "Be reasoanble pls" << endl;
	}
	else {
		for (int i = startPos; i <= length; i++) {
			fstream myfile;
			myfile.open("customStringClass.txt");

			if (myfile.is_open())
			{
				myfile <<  myString[i] << endl;

				myfile.close();
			}
			else cout << "Unable to open file";

			cout << myString[i];
		}
		cout << endl;
	}
}

void CustomStringClass::replPartString(int startPos, int len)
{
	char* temp = new char[size()];

	if (startPos < 0)
	{
		cout << "less";
	}

	if (startPos >= size())
	{
		cout << "not valid";
	}
	// valid starting position
	else
	{
		for (int x = 0; x < size(); x++) {
			temp[x] = myString[startPos++];
		}
		temp[size()] = '\0';
		cout << temp << endl;
		fstream myfile;
		myfile.open("customStringClass.txt");

		if (myfile.is_open())
		{
			myfile << temp << endl;

			myfile.close();
		}
		else cout << "Unable to open file";

	}
}

void CustomStringClass::replWholeString(string st) {
	// replaces current string data value with parameter string
	char* newstring = new char[st.length() + 1];
	for (int i = 0; i < st.length(); i++) {
		newstring[i] = st.at(i);
	}
	newstring[st.length()] = '\0';

	for (int i = 0; i < st.length(); i++) {
		myString[i] = newstring[i];
	}
	myString[st.length()] = '\0';
	cout << myString << endl;
	fstream myfile;
	myfile.open("customStringClass.txt");

	if (myfile.is_open())
	{
		myfile << myString << endl;

		myfile.close();
	}
	else cout << "Unable to open file";

}

int CustomStringClass::compareString(const char* s1, const char* s2) {
// compare current value of string with parameter string.Returns 0 if strings match, 
// otherwise return character position(NOT index) where mismatch occurs.If parameter is 
//first alphabetically then return is a positive number, otherwise a negative number.

	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
		s1++;
		s2++;
	}
		if (*s1 == *s2) {
			cout << "Yay, they match!" << endl;
			return 0;
		}
		if (*s1 > *s2) {
			cout << *s1 << "does not match & first word is bigger ASCII wise" << *s2 << endl;
			return 2;
		}

		if (*s2 > *s1) {
			cout << *s1 << "does not match & is the second word is bigger ASCII wise" << *s2 << endl;
			return -3;
		}
		else {
			return -4;
		}
	
}

bool CustomStringClass::numericString() {
//– returns Boolean telling if data value is an integer or real(digits, signs, decimal point.etc.), or not
	for (int x = 0; x < size(); x++) {
		if (!isdigit(myString[x])) {
			cout << "Is alpha" << endl;
			return false;
			
		}
		cout << "Is number!" << endl;
		return true;
		
	}
}

bool CustomStringClass::alphabeticString() {
	//– returns Boolean telling if data value is all alphabetic characters
	for (int i = 0; i < size(); i++) {
		if (!isalpha(myString[i])) {
			cout << "numbers1!" << endl;
			return false;
		}
		cout << "Is alpha" << endl;
		return true;
	}
}

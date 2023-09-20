// File name: Question3Lab1pointers.cpp 
// Author: Huda Hussaini
// 1/25/22 - Question 3 -  display to the console the name of the
//executable that is running and each argument value.

Using namespace std;
#include <iostream>

/*Int main(int argc, const char* argv[]) {
	cout << endl;
	
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << end;

	}
	cout << endl;

	return 0;

}*/
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	cout << "You have entered " << argc
		<< " arguments:" << "\n";

	for (int i = 0; i < argc; ++i)
		cout << argv[i] << "\n";

	return 0;
}


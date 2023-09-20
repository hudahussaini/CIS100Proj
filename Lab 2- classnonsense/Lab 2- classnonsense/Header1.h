
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Person {
private:
	string major;
	int credhrs;

public:
	Person(string(mj) = "general studies", int(crhr) = -1):  major(mj), credhrs(crhr) {
		cout<< "\n\tConstructor called for"<< mj << " and hours of\n" << crhr << endl;
	}

	string getMajor() const;
	int getCredhrs() const;
	void setBoth(const string mj, const int crhr);
	void PrintMe();


	~Person() {
		cout << "\n\tDestructor called for" << major << " major.\n " << endl;
	};
	

};



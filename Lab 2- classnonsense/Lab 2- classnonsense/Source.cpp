#include "Header1.h"
#include <iostream> 

string Person::getMajor() const{ 
	return major;
}

int Person::getCredhrs() const{
	return credhrs;
}

 
void Person::setBoth(const string mj, const int crhr) {
 major = mj;
 credhrs=crhr;

}

void Person::PrintMe() {
	cout << "I’m a" << major <<" major and have completed"<< credhrs << "credit hours." << endl;
}

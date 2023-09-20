#include "Header.h"
#include <fstream>

int main() {
	CustomStringClass obj;
	CustomStringClass(myString);
	obj.set("Hello");
	obj.size();
	obj.print();
	obj.addStart("Jello", "Hello");
	obj.addEnd("Halal?");
	obj.partString(2, 3);
	obj.replPartString(2, 4);
	obj.replWholeString("okay");
	obj.compareString("hi", "hi");
	obj.numericString();
	obj.alphabeticString();
	

}

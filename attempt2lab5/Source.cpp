#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double distance, x1, x2, y1, y2;
	cout << "enter first point x1, y1" << endl;
	cin >> x1 >> "," >> y1 >> endl; 
	cout << "enter second point x2, y2" << endl;
	cin >> x2 >> "," >> y2 >> endl;
	distance = pow(pow((x1 - x2), 2) + pow((y1 - y2), 2), 0.5);
	cout << "distance between:" << distance; 

}
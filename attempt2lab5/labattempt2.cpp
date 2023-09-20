#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double distance, x1, x2, y1, y2;
	cout << "enter first point x1, y1" << endl;
	cin >> x1;
	cin >> y1;
	cout << "enter second point x2, y2" << endl;
	cin >> x2;
	cin >> y2;
	distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	cout << "distance between:" << distance; 
}
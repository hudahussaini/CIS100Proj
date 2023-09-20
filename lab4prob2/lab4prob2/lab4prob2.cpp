#include <iostream>
#include <cassert>
using namespace std;


double squareRoot(double x)
{
	assert(x >= 0);
	if (x == 0) return 0;
	// assert that x is not negative
	double curr = x / 2;
	double next = ((curr + (x / curr)) / 2);

	while (next - curr > 0.0001) {
		curr = next;
		next = ((curr + (x / curr)) / 2);
		// xn+1 = (xn + x/xn)/2.
	}
	return next;
}

int main()
{
	cout << squareRoot(3) << endl;
	cout << squareRoot(0) << endl;
	cout << squareRoot(-3) << endl;


}



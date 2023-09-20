
#include <iostream>
using namespace std;
// Huda Hussaini
// Sep 29, 2021
//Switch statements


int main() {

	int watts;
	int life;

	cout << "input ";
	cin >> watts;


	switch (watts) {
	case 25:
		life = 2500;
		break;
	case 40:
	case 60:
		life = 1000;
		break;
	case 75:
	case 100:
		life = 750;
		break;
	default:
		life = 0;
		break;

	}
	cout << life << endl;
}

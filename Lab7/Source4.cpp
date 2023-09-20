// Lab7.cpp Part 2: creating a recursive function to perform a factorial calculation. 
// Author: Huda Hussaini
#include <iostream>

using namespace std;

int factorial(int value, bool& methodStatus) {
    if (value < 0) {
        methodStatus = false;
        return -1;
    }
    else if (value == 0) {
        return 1;
    }
    else {
        return value * factorial(value - 1, methodStatus);
    }
}

int main() {
    bool status = true;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n, status) << endl;
    cout << "factorial status is " << status << endl;
    return 0;

}
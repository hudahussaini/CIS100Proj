// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Greet {
public:
    Greet();
};


Greet::Greet() {
    cout << "Hello";
}

int main() {
    Greet t1;
    return 0;
}
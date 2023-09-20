#include <iostream>
using namespace std;
// Huda Hussaini
// Sep 29, 2021
//GPA calculator 

int main()
{
    float GPA;

    cout << "insert GPA: ";
        cin >> GPA;
    if (GPA < 0.99) {
        cout << "Failed Semester - Registration Suspended." << endl;
    }
    else if (GPA < 1.99) {
        cout << "On Probation for Next Semester." << endl;
    }
    else if (GPA < 2.99) {
        cout << "Pass." << endl;
    }
    else if (GPA < 3.49) {
        cout << "Dean's List for Semester." << endl;

    }
    else if (GPA < 4.0) {
        cout << "Highest Honors for Semester." << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;


class Vector
{
public:

    Vector();
    Vector(int s) {
        size = s;
        entries = new int[s];
        for (int i = 0; i < size; i++) {
            entries[i] = 0;
        }
    }

    Vector(const Vector& other) {
        // copy constructor
        // makes a deep copy
        size = other.size; // why not s
        entries = new int[size]; // it dont matter the size?
        for (int i = 0; i < size; i++) {
            entries[i] = other.entries[i];
        }
    }

    ~Vector() {
        delete entries;
    }// default destructor

    void print() {
        cout << "The #'s are : [ ";
        for (int i = 0; i < size; i++) {
            cout << entries[i];
            if (i < size - 1) {
                cout << " ";
            }
        }
        cout << "]\n";
    }

    void set(int val, int pos) {

        if (0 <= pos && pos < size) {
            entries[pos] = val;  // ?????????????????

            //    stores val at pos in entries
            // otherwise error message 
        }
        else {
            cout << "This is wrong just like you," <<
                "next time please put in something greater or equal to your IQ(0) \n";
        }
    }


private:
    int size;          			 // sets the # of elements used  
    int* entries;			// point to array of integers with size entries
                           //   e.g. entries = new int[size]
};



/*Given storeMonthlySales[NUM_STORES][NUM_MONTHS][NUM_DEPTS] is a three - dimensional array of floating 
point values.Write a C++ function, printMonthlySales, to The constants NUM_STORES,
NUM_MONTHS, and NUM_DEPTS must be accessed globally by defining the following global variables */:
#include <iostream>
using namespace std;
const int numDepts = 2;
const int numStores = 2;
const int numMonths = 12;

void printDetais(float storeMonthlySales[numStores][numMonths][numDepts])
{
    int i, j, k, n;//variable declarations
    //infinite loop to print details as much as user needs
    while (1)
    {
        cout << endl << "Please enter a month to print(1-12 or 0 to exit) : ";
        cin >> n;//read the month names
        //condition for terminating the operation
        if (n == 0)
            break;
        cout << endl << "Sales for month of " << n;
        cout << endl << "\t\tDept#1\tDept#2\tStore Total";
        cout << endl << "Store #1\t";
        //print the details sales for store 1
        cout << storeMonthlySales[0][n - 1][0] << "\t" << storeMonthlySales[0][n - 1][1] << "\t" << storeMonthlySales[0][n - 1][0] + storeMonthlySales[0][n - 1][1];
        cout << endl << "Store #2\t";
        //print the details sales for store 2
        cout << storeMonthlySales[1][n - 1][0] << "\t" << storeMonthlySales[1][n - 1][1] << "\t" << storeMonthlySales[0][n - 1][0] + storeMonthlySales[0][n - 1][1];
        cout << endl << "Dept Total : " << storeMonthlySales[0][n - 1][0] + storeMonthlySales[1][n - 1][0] << "\t" << storeMonthlySales[0][n - 1][1] + storeMonthlySales[1][n - 1][1] << "\t" << (storeMonthlySales[0][n - 1][0] + storeMonthlySales[0][n - 1][1]) + (storeMonthlySales[1][n - 1][0] + storeMonthlySales[1][n - 1][1]);
    }
}
//driver program
int main()
{
    float storeMonthlySales[numStores][numMonths][numDepts] = { {{1.1,3.1},{1.2,3.2},{1.3,3.3},{1.4,3.4},{1.5,3.5},{1.6,3.6},{1.7,3.7},{1.8,3.8},{1.9,3.9},{2.0,4.0},{2.1,4.1},{2.2,4.2}},{{2.1,2.1},{2.2,2.2},{2.3,2.3},{2.4,2.4},{2.5,2.5},{2.6,2.6},{2.7,2.7},{2.8,2.8},{2.9,2.9},{3.0,3.0},{3.1,3.1},{3.2,3.2}} };
    //call to printDetais()
    printDetais(storeMonthlySales);
}

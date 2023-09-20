#include <iostream>
using namespace std;
int main()
{
	int numberEmp; 
	int countEmp; 
	float hours; 
	float rate; 
	float pay; 
	float totalPay; 

	cout << "Enter number of employees: " << endl;
		cin >> numberEmp;
	
	totalPay = 0.0;
	countEmp = 0;
	while(countEmp < numberEmp)
	{ //
	cout << "Hours: ";
	cin >> hours;
	cout << "Rate : $";
	cin >> rate;
	pay = hours * rate;
	cout << "Pay is $" << pay << endl;
	totalPay = totalPay + pay; 
	countEmp = countEmp + 1;
	} //
	cout << "Total payroll is $" << totalPay << endl;
	cout << "All employees processed." << endl;
	return 0;
}
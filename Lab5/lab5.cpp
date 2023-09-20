#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double x;
double x1;
double y;
double y1;

double distance(double x, double x1, double y, double y1) {
    double formula;
    double corPow;
    double cor2Pow;
    double cor1;
    double cor2;

    cor1 = x - y;
    cor2 = x1 - y1;
    
    corPow = pow(cor1, 2);
    cor2Pow = pow(cor2, 2);

 
    formula = sqrt(cor1 + cor2);

    return formula;
}
int main()
{
    cin >> x >> endl;
    cin >> x1 >> endl;
    cin >> y >> endl;
    cin >> y1 >> endl;

    cout << distance << endl; 

    return 0;
}
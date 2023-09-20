#include <iostream>
using namespace std;

float computeSum(int numitems) {
    float sum = 0.0;
    float value;
    int i;

    for (i = 0; i < numitems; i++) {
        cout << "enter value: ";
        cin >> value;
        sum += value;
    }
    return sum;
}

float computeAve(int numItems, float& sum) {
    float average;
    average = sum / numItems;
    return average; 
}

void printSumAve(int numitems, float sum, float average) {
    cout << "The sum is: " << sum << endl;
    cout << "avg is: " << average << endl;
}
int main()
{
    int numItems;
    float averageItems;
    float sumItems;

    cout << "enter the number of items ";
    cin >> numItems;

    sumItems = computeSum(numItems);
    averageItems = computeAve(numItems, sumItems);
    printSumAve(numItems, sumItems, averageItems);

    return 0;

}


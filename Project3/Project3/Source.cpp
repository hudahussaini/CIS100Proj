#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> num2 = nums;
        int target1 = target;
        int flag = 0; // flag is a way to break out of nested loop

        for (size_t i = 0; i < num2.size(); i++) { // you can use (size_t i= 0) instead of (int i = 0)

            for (size_t j = 1; j < num2.size(); j++) {
                if (target1 == num2[i] + num2[j]) {
                    cout << "[" << i << "," << j << "]";
                    flag = 1;
                    break;


                }
            }
            if (flag == 1) {
                break;
            }

        }

        return num2;

    }

};

int main() {
    cout << "Do you want to enter num: ";
    string ans;
    cin >> ans;
    vector<int>num1;

    while (ans == "yes" || ans == "Yes") {
        cout << "Enter the number: " << endl;
        int num;
        cin >> num;

        num1.push_back(num);
        cout << "Do you want to enter num: ";
        cin >> ans;
    }

    cout << "Decide the target: ";
    int targets;
    cin >> targets;
    cout << "The output is: " << endl;

    Solution first;
    first.twoSum(num1, targets);

    return 0;
}
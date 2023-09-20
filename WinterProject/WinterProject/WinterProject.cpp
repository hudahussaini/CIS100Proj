#include<iostream>
#include <string>
using namespace std;

class university {

private:
	int courseIdentification = 1710;
	int departmentCourseId[2] = {101, 1};
	int numberCredit = 360;
	int roomNumber[2] = { 25,2 };
	int maxEnroll = 25;
	int nS = 0;
	string daysNtime[2] = { "Tues", "9:00AM" };
	string campus = "ELAB";
	string courseInstructor;
	string nStudent[100];
	string courseStatus;

public:
	void setCourseIdentification(int n) {
		courseInstructor = n;
	}
	void setDepartmentCourse(int n, int m) {
		departmentCourseId[0] = n;
		departmentCourseId[1] = m;
	}
	void setNumberCredit(int n) {
		numberCredit = n;
	}

	void setRoomNumber(int n, int m) {
		roomNumber[0] = n;
		roomNumber[1] = m;

	}

	void setMaxEnroll(int n) {
		maxEnroll = n;
	}
	void setCourseInstructor(string s) {
		courseInstructor = s;
	}
	void setNstudent(int n) {
		nS = n;
		for (int i = 0; i < n; i++) {
			string s;
			cout << "enter student ID" << endl;
			cin >> s;
			nStudent[i] = s;
		}
	}
	void setCourseStatus(string s) {
		courseStatus = s;
	}

	void setDayTime(string s, string s1) {
		daysNtime[0] = s;
		daysNtime[1] = s1;
	}
	void display() {
		cout << "Course Identification Number " << courseIdentification << endl;
		cout << "department course ID is " << departmentCourseId[0] << " and section number is " << departmentCourseId[1] << endl;
		cout << "number of credits for the course " << numberCredit << endl;
		cout << "days and times the course " << daysNtime[0] << " and " << daysNtime[1] << endl;
		cout << "Room in which the course meets is " << roomNumber[0] << " and " << roomNumber[1] << endl;
		cout << "Max enroll " << maxEnroll << endl;
		cout << "Campus on which the course is held is " << campus << endl;
		cout << "# of student currently enrolled and student ID of students " << nS << endl;
		for (int i = 0; i < nS; i++)
			cout << "ID: " << nStudent[i] << " " ;
		cout << endl;
		cout << "Course status is " << courseStatus;
	}
};

int main() {
	university u;
	string s;
	int change;
	int anger;
	int creditval;
	int numstu;
	cout << "enter course instructor" << endl;
	cin >> s;
	u.setCourseInstructor(s);
	cout << "Enter # of student to enroll" << endl;
	int n;
	cin >> n;
	u.setNstudent(n);
    cout << "enter course status " << endl;
	cin >> s;
	u.setCourseStatus(s);
	u.display();

	cout << endl << "-" << endl;
	cout << "Thank you!" << endl << "If you want to continue enter 0" << endl;
	cin >> change;

	if (change == 0) {
		cout << "choose a element to change" << endl << "1. Credits" << endl << "2. # of students" << endl;
		cin >> anger;
	}
	    if (anger ==1) {
		 	cout << "enter the new number of credits" << endl;
			cin >> creditval;
			u.setNumberCredit(creditval);
			u.display();
		}

		if (anger == 2) {
			cout << "enter the new number of students & ID" << endl;
			cin >> numstu;
			u.setNstudent(numstu);
			u.display();
		}

	else {
		
		return 0;
	}


}
#include <iostream> 
#include 
using namespace std;

struct record{
	int recordnumber;
	char tool[20];
	int quantity;
	double cost;
	record* Next;
};

void writeData(fstream& creditFile);
void print(fstream& creditFile);
void readData(fstream& creditFile);
void updateData(fstream& creditFile);

int main()
{
	fstream recordFile;
	recordFile.open("record.dat", ios::in | ios::out | ios::trunc);
	if (recordFile.good() == false) {
		cout << strerror(errno);
	}

	writeData(creditFile);
	readData(creditFile);
	updateData(creditFile);
	print(creditFile);

	creditFile.close();
}
const int tool_length = 20;

void menu (fstream& recordFile) {
	int input;
	cout << "Do you want to add, update, Delete or list all the tools" << , endl;
	cin >> input;
	switch (input) {
	case 1:
		writeData();
		break;
	case 2:
		readData();
		break;

	}


	if ()

}

void writeData(fstream& recordFile) {
	recordData MyRecords = { 0.0, "", 0.0, 1.0 };
	int recordnum;
	string toolname;
	int Quantity;
	double cost;



	for (int i = 0; i <= 100; i++) {
		recordFile.write(reinterpret_cast<const char*>(&MyRecord), sizeof(recordData));
	}

	while (1) {
		cout << "Enter the record number or enter 0 to quit: ";
		cout.flush();
		cin >> MyRecords.recordnumber;
		if (MyRecords.accountNumber == 0) break;
		creditFile.seekp(MyRecords.accountNumber) * sizeof(recordData), ios::beg);

		cout << "Enter Tool name: ";
		cin >> toolname;
		for (int i = 0; i < tool_length && i < toolname.length(); i++) {
			Myrecords.toolname[i] = toolname[i];

		cout << "Enter the record number or enter 0 to quit: ";
		cin >> MyRecords.Quantity;
		if (MyRecords.accountNumber == 0) break;
		creditFile.seekp(MyRecords.accountNumber) * sizeof(recordData), ios::beg);
		}

		creditFile.write(reinterpret_cast<const char*>(&MyClient), sizeof(clientData));
	}


}

void readData(fstream& creditFile) {
	clientData MyClient = { 0, "", "", 0.0 };

	cout << "Enter the account number to read existing data or quit 0: ";
	cout.flush();
	cin >> MyClient.accountNumber;
	creditFile.seekg(0 + (MyClient.accountNumber) * sizeof(clientData), ios::beg); //beg of file + size of first so blank dat


	creditFile.read(reinterpret_cast<char*>(&MyClient), sizeof(clientData));

	cout << MyClient.accountNumber << endl << MyClient.lastName <<
		endl << MyClient.firstName << endl << MyClient.balance << endl;


}

void updateData(fstream& creditFile) {
	clientData MyClient = { 0, "", "", 0.0 };
	string firstname;
	string lastname;

	cout << "Enter your account number or enter 0 to quit: ";
	cin >> MyClient.accountNumber;
	if (MyClient.accountNumber == 0) return;

	creditFile.seekp((MyClient.accountNumber) * sizeof(clientData), ios::beg);
	//creditFile.read(reinterpret_cast<char*>(&MyClient), sizeof(clientData));  reading from cin

	cout << "Enter last name: ";
	cin >> lastname;
	for (int i = 0; i < LN_length && i < lastname.length(); i++) {
		MyClient.lastName[i] = lastname[i];
	}

	cout << "Enter first name: ";
	cin >> firstname;
	for (int i = 0; i < FN_length && i < firstname.length(); i++) {
		MyClient.firstName[i] = firstname[i];

		cout << "Enter balance: ";
		cin >> MyClient.balance;

		creditFile.write(reinterpret_cast<const char*>(&MyClient), sizeof(clientData));

	}
}

void print(fstream& creditFile) {
	creditFile.seekg(0 + sizeof(clientData), ios::beg); //beg of file + size of first so blank data skipped
	clientData MyClient = { 0, "", "", 0.0 };

	while (!creditFile.eof()) {


		creditFile.read(reinterpret_cast<char*>(&MyClient), sizeof(clientData));
		if (creditFile.good() == false) {
			//cout << strerror(errno);
			break;
		}
		if (MyClient.accountNumber == 0) continue;

		cout << MyClient.accountNumber << endl << MyClient.lastName <<
			endl << MyClient.firstName << endl << MyClient.balance << endl;

	}


}


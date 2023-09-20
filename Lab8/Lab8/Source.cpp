#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void readStudData(ifstream& rss, int scores[], int id[], int& count, bool& tooMany);
float mean(int scores[], int count);
void printTable(int score[], int ID[], int count);
void printGrade(int oneScore, float average);
const int MAX_SIZE = 10;
int main()
{
	int scores[MAX_SIZE];
	int ID[MAX_SIZE];
	int count;
	bool tooMany;
	ifstream inFile;
	inFile.open("scores.txt");
	readStudData(inFile, scores, ID, count, tooMany);
	inFile.close();
	if (tooMany) cout << "\nWarning! Some data is missing\n";
	// Print the data
	printTable(scores, ID, count);
	cout << endl;
	system("Pause");
	return 0;
}

void readStudData(ifstream& rss, int scores[], int id[], int& count, bool& tooMany)
{
	tooMany = false;
	count = 0;

	while (!rss.eof())
	{
		if (count == MAX_SIZE) break;
		rss >> id[count] >> scores[count];
		count++;
	}
	
	if (!rss.eof() && count == MAX_SIZE) tooMany = true;
}
float mean(int scores[], int count)
{
	// Store the sum of the scores here
	int sum = 0;
	// Loop through and accumulate the scores from the array
	for (int i = 0; i < count; i++)
	{
		sum += scores[i];
	}
	// Return the average
	return (float)sum / count;
}
void printTable(int score[], int ID[], int count)
{
	// Need the average
	float average = mean(score, count);
	// Display the average to the user
	cout << "Average: " << average << endl;
	// Display the header for the table
	cout << "ID\t" << "Score\t" << "Grade" << endl;

       
	for (int i = 0; i < count; i++)
	{
		cout << ID[i] << '\t' << score[i] << '\t';
		printGrade(score[i], average);
	}
}

void printGrade(int oneScore, float average)
{
	// See the text for grade criterion
	// Recommend that you use if-else if-else
	if (oneScore < average + 10 && oneScore > average - 10) cout << "Satisfactory\n"; 
	else if (oneScore > average + 10) cout << "Outstanding\n"; 
	else cout << "Unsatisfactory\n"; 
}
#include "Classes.h"

int main() {
	int SIZE = 8;
	// from file
	vector <Jobs> exact;
	Queue<Jobs> obj;
	vector<CPU>CPUs(SIZE);
	int aType = 0, bType = 0, cType = 0;
	bool processing;
	int total_jobs = 0;
	ofstream logfile;
	logfile.open("logfile.txt");
	//Opening the static data file
	ifstream read("Datafyleusedforsim.txt");
	int maxqueuesize = 0;
	int totaltimeproc = 0;
	int totalqueue = 0;
	int totaltimeinqueue = 0;
	int jobsprocessed = 0;
	int overall = 1;
	int job_queue = 0;
	int typeA = 1;
	int typeB = 1;
	int typeC = 1;
	while (!read.eof())
	{
		Jobs temp;
		//reading in every data sample from the file
		read >> temp.type >> temp.arrival >> temp.processing;
		temp.overall = overall++;
		switch (temp.type)
		{
		case 'A': temp.typeOverall = typeA++;
			break;
		case 'B': temp.typeOverall = typeB++;
			break;
		case 'C': temp.typeOverall = typeC++;
			break;
		}
		//read in a temporary object that gets stored in a vector using pushback
		exact.push_back(temp);

	}
	read.close(); //closing file


	int runtime = 10000;
	for (int time = 1; time <= runtime; ++time) {
		for (int i = 0; i < SIZE; i++)
		{
			CPUs.at(i).execution();
			if (CPUs.at(i).isProcessing && CPUs.at(i).isJobComplete())
			{

				// cout of complete job
				//check if time does not equal the job that is about to leave its arrive time;
				logfile << "Time " << time << ": Complete Processing Job:" << CPUs.at(i).current_job.overall << ", Job " <<
					CPUs.at(i).current_job.type << ":" << CPUs.at(i).current_job.typeOverall << " in CPU " << i + 1 << ";" << endl;;
				// check again for being processing

			}
		}
		//assigning jobs to CPU from queue
		while (!obj.isEmpty())
		{
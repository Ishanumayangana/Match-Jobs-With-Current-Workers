#pragma once
#include "Jobs.h"
#include "LinkedList.h"
#include <string>
#include <algorithm>
using namespace std;

void Admin(linkedList applicant);
void Applicant(linkedList applicant, linkedListJobs jobs);

//Develop Work Assignment Algorithm to Match Jobs With Current Workors


int mainMenu()
{
	cout << " " << endl;
	cout << "                               ...::: Welcome to the Jobs & Applicants Finder :::..." << endl;
	cout << " " << endl;
	cout << "1. View Applicants as the Admin " << endl;
	cout << "2. Find a Job and Register as an Applicant " << endl;
	cout << " " << endl;

	int selection;
	cin >> selection;

	return selection;
}

void secondMenu(int selection, linkedList applicant, linkedListJobs jobs)//main menu output pass here
{
	while (selection < 5)
	{
		switch (selection)
		{
		case 1:
			Admin(applicant);
			selection = 5;
			break;
		case 2:
			Applicant(applicant, jobs);
			selection = 5;
			break;
		default:
			selection = mainMenu();
			secondMenu(selection, applicant, jobs);
			break;
		}
	}
}

void Admin(linkedList applicant)
{
	cout << "List of Applicants" << endl;
	applicant.print();

}

void Applicant(linkedList applicant, linkedListJobs jobs)
{
	cout << "*******************  Welcome to our company  ******************" << endl;
	cout << " " << endl;
	cout << "Please enter your details below" << endl;

	string Name;
	cin.ignore();

	cout << "Name : ";
	getline(cin, Name);
	cout << endl;

	int Age;
	cout << "Age : ";
	cin >> Age;
	cout << endl;

	string Hometown;
	cin.ignore();

	cout << "Hometown : ";
	getline(cin, Hometown);
	//cin.ignore();
	cout << endl;

	applicant.insertLast(Name, Age, Hometown);
	cout << "Now, enter your qualifications" << endl;
	cout << "At the end, please type 'exit'" << endl;

	string qualification;

	while (qualification != "exit")
	{
		cout << "Enter the qualifications one by one" << endl;
		getline(cin, qualification);
		transform(qualification.begin(), qualification.end(), qualification.begin(), ::tolower);
		applicant.returnNode(Name)->qualifications.push_back(qualification);
		//cin.ignore();
	}

	//cout << "Here is the most suitable job according to our system" << endl;

	int sizeApplicant = sizeof(applicant.returnNode(Name)->qualifications) / sizeof(applicant.returnNode(Name)->qualifications[0]);

	Jnode* current = jobs.head;
	int bigscore = 0;
	string bigjob = "output";
	int score = 0;
	while (current != NULL)
	{
		score = 0;
		//int sizejobs = sizeof(current->QualificationsRequired) / sizeof(current->QualificationsRequired[0]);

		for (string qualification : applicant.returnNode(Name)->qualifications) {
			for (string jobqualification : current->QualificationsRequired) {
				if (qualification == jobqualification) {
					score++;
				}
			}

		}

		if (bigscore <= score)
		{
			bigscore = score;
			bigjob = current->jobName;
		}
		current = current->next;
	}
	
	if (bigscore > 0)

		cout << "The most suitable job is " << bigjob << endl;

	else
		cout << "Invalid Keyword(s) / There Is No Suitabable Job For Your Qualifications" << endl;
	
		
	

	int selection = mainMenu();

	secondMenu(selection, applicant, jobs);
}

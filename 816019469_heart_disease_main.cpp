#include "816019469_heart_disease.h"
#include<iostream>
#include <iomanip>
#include<fstream>
#include<vector>
#include<cassert>
#include<stdexcept>

using std::cin; using std::cout; using std::vector; using std::string; using std::endl;
using std::ofstream; using std::string; using std::domain_error; using std::cerr; using std::setw;

int main()
{
	//initialize neccessary containers
	vector<Records> patient_records;
	vector<Records> heart_patients;

	//executes functions that looks for and opens a specific file
	try
	{
		readfile(patient_records);
		readfile2(heart_patients);
	}
	//error handling
	catch (domain_error e)		
	{
		cerr << "Error: " << e.what() << endl;
		system("pause");
		return 0;
	}

	int choice = 0;
	int pick = 0;
	int Lowest_Age = 0;

	while (choice != Exit)
	{
		system("cls");

		choice = printMenu();
		switch (choice)
		{
		case Gender:  //executes gender function
			system("cls");
			try
			{
				compGender(patient_records);
			}
			catch (domain_error e)
			{
				cerr << e.what() << endl;
				system("pause");
			}
			break;

		case Age:  //executes age functions
			system("cls");
				Lowest_Age = compAge(patient_records);
				compdisAge(heart_patients,Lowest_Age);
			break;
		case Exang:  //exercised exercised induced angina function
			try
			{
				compExang(patient_records);
			}
			catch (domain_error e1)
			{
				cerr << e1.what() << endl;
				system("pause");
			}
			break;
		case Pain:   //executes chest pain function
			try
			{
				compPain(patient_records);
			}
			catch (domain_error e)
			{
				cerr << e.what() << endl;
				system("pause");
			}
			break;
		case Complicated:   //executes secondary menu to choose fbs, bps or chol
			system("cls");
			pick = printMenu3();
			switch (pick)
			{
			case Fbs:			//executes diabetes function
				system("cls");
				try
				{
					compFbs(patient_records);
				}
				catch (domain_error e)
				{
					cerr << e.what() << endl;
					system("pause");
				}
				break;

			case Bps:		//executes hypertension function
				compBps(patient_records);
				break;

			case chol:		//executes cholesterol function
				compChol(patient_records);
				break;
			case compExit:		//exits to main menu
				break;
			default:
				system("cls");
				cerr << "Error: Invalid entry! Please try again.." << "\n" << endl;
				system("pause");
				system("cls");
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				pick = printMenu3();
				break;
			}

			break;
		case CA:			//executes fluoroscopy function
			try
			{
				compCA(patient_records);
			}
			catch (domain_error e)
			{
				cerr << e.what() << endl;
				system("pause");
			}
			break;
		case Exit:			//ends program
			cout << "Thank You For Using This Program \n" << endl;
			system("pause");
			return 0;
		default:
			system("cls");
			cerr << "Error: Invalid entry" << endl;
			system("pause");
			
		}
	}
	system("cls");
	choice = printMenu();

	return 0;
}

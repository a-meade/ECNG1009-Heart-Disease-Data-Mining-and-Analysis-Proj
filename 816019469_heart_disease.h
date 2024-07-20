#pragma once

#include<vector>
#include<string>


using std::vector; using std::string; 

struct Records
{
	int Age;
	int Sex;
	int Chest_Pain;
	int Threstbps;
	int chol;
	int fbs;
	int ECG;
	int thalach;
	int exang;
	double oldpeak;
	int slope;
	int fluorscopy;
	int thalas;
	int target;
};

//the integers for the switch case are assigned appropriate names
const int Gender = 1;
const int Age = 2;
const int ageExit = 3;
const int Exang = 3;
const int Pain = 4;
const int compExit = 4;
const int Complicated = 5;
const int Fbs = 1;
const int Bps = 2;
const int chol = 3;
const int AllAge = 1;
const int disAge = 2;
const int CA = 6;
const int Exit = 7;

bool isInteger(string s);		//Function that checks a string to determine if input is an integer

int convert(string s);			//Function that converts an input string to an integer using stringstream

double convertdouble(string s);			//Function that converts an input string to a double using stringstream

Records split(string line);			//Function that parses each line of the csv file

void readfile(vector<Records>& v);			//Function that searches for and opens a specific file. The information is stored in vector of Structs

void readfile2(vector<Records>& v);			//Function that searches and opens a specific file. Only lines where target == 0 are stored in a vector of Structs

int printMenu();			//Function that prints the main menu and accepts the input

int printMenu3();			//Function that prints secondary menu for case 5 == Complicated and accepts the input

void compGender(const vector<Records>& v);			//Function that determines quantity of each gender with and without heart disease

void compdisAge(const vector<Records>& v, int L);			//Function that shows histogram of the ages of heart disease patients.

int compAge(const vector<Records>& v);					//Function that shows histogram of the ages of all patients.

void compExang(const vector<Records>& v);			//Function that shows the quantity of patients with and without exercised iduced angina

void compPain(const vector<Records>& v);			//Function that shows the most prevalent chest pain types

void compFbs(const vector<Records>& v);				//Function that shows probability tree for diabeties

void compBps(const vector<Records>& v);				//Function that shows probability tree for high blood pressure

void compChol(const vector<Records>& v);			//Function that shows probability tree for high cholesterol

void compCA(const vector<Records>& v);				//Function that shows the amount of vessels coloured by fluoroscopy

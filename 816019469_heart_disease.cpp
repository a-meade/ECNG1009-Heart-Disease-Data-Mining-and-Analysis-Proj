#include<iostream>
#include<cmath>
#include<math.h>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
#include<cassert>
#include<stdexcept>
#include<map>
#include<cctype>
#include<iomanip>
#include "816019469_heart_disease.h"

using std::cout; using std::cin; using std::list; using std::vector; using std::string; using std::ifstream;
using std::ofstream; using std::string; using std::stringstream; using std::domain_error; using std::invalid_argument;
using std::sort; using std::endl; using std::cerr; using std::getline; using std::setw;


bool isInteger(string s)		 
{
	for (string::size_type i = 0; i != s.size(); i++)
	{
		if (isdigit(s[i])== false)
		
			return false;
		
	}
	return true;
}

int convert(string s)		
{
	stringstream ss;
	ss << s;
	int num;
	ss >> num;
	return num;
}

double convertdouble(string s)			
{
	stringstream ss;
	ss << s;
	double number;
	ss >> number;
	return number;
}

Records split(string line)			
{
	Records p;
	vector<string> temp_records_items;
	string temp;
	stringstream ss;
	ss << line;
	while (getline(ss, temp, ','))
	{
		temp_records_items.push_back(temp);
	}
	for (vector<string>::size_type i = 0; i != 9; ++i)
	{
		if (isInteger(temp_records_items[i]))
		{
			continue;
		}
		else
		{
			cerr << "Non interger type found" << endl;
			system("pause");
		}
	}
	for (vector<string>::size_type i = 10; i != temp_records_items.size(); ++i)
	{
		if (isInteger(temp_records_items[i]))
		{
			continue;
		}
		else
		{
			cerr << "Non interger type found" << endl;
			system("pause");
		}
	}

	p.Age = convert(temp_records_items[0]);
	p.Sex = convert(temp_records_items[1]);
	p.Chest_Pain = convert(temp_records_items[2]);
	p.Threstbps = convert(temp_records_items[3]);
	p.chol = convert(temp_records_items[4]);
	p.fbs = convert(temp_records_items[5]);
	p.ECG = convert(temp_records_items[6]);
	p.thalach = convert(temp_records_items[7]);
	p.exang = convert(temp_records_items[8]);
	p.slope = convert(temp_records_items[10]);
	p.fluorscopy = convert(temp_records_items[11]);
	p.thalas = convert(temp_records_items[12]);
	p.target = convert(temp_records_items[13]);

	return p;
}

void readfile(vector<Records>& v)			 
{																			
	ifstream infile;
	infile.open("heart.csv");
	if (!infile)
	{
		//error handling
		throw domain_error("File Not Found");
	}
	else
	{
		cout << "Let's Begin: \n";

		string line;
		vector <string> usefuldata;

		//extracts each line of the file into a vector
		while (getline(infile, line))
		{
			usefuldata.push_back(line);
		}

		Records temp;
		for (vector<string>::size_type i = 1; i != usefuldata.size(); i++)
		{

			temp = split(usefuldata[i]);
			v.push_back(temp);

		}
	}
}

/*same functions as the last the readfile function 
but only lines where target = 0 are added to a vector*/
void readfile2(vector<Records>& v)			
{																				
	ifstream infile;
	infile.open("heart.csv");
	if (!infile)
	{
		throw domain_error("File Not Found");
	}
	else
	{
		cout << "Let's Begin: \n";

		string line;
		vector <string> usefuldata;

		while (getline(infile, line))
		{
			usefuldata.push_back(line);
		}

		Records temp;
		for (vector<string>::size_type i = 1; i != usefuldata.size(); i++)
		{

			temp = split(usefuldata[i]);
			if (temp.target == 0)
			{
				v.push_back(temp);
			}

		}
	}
}

	int printMenu()				
	{
		//get input
		int choice = 0;
		cout << "Menu: \n"
			<< "(1) Compare Heart Disease by Gender \n"
			<< "(2) Compare Heart Disease by Age Group \n"
			<< "(3) Exercise Induced Angina \n"
			<< "(4) Most Common Chest Pain Types \n"
			<< "(5) Volume with Diabetes, High Blood Pressure and Cholesterol \n"
			<< "(6) Number of Vessels Highlighted by Fluoroscopy \n"
			<< "(7) Exit \n";
		cout << "Choose an item (1-7) \n";
		cin >> setw(1) >> choice;

		//Error Check
		while (!cin.good())
		{
			//Report Problem
			system("cls");
			cerr << "Faulty Input! Please try again..." << endl << endl;
			system("pause");
			system("cls");

			//clear stream
			cin.clear();
			cin.ignore(INT_MAX, '\n');
	
			//get input again
			cout << "Menu: \n"
				<< "(1) Compare Heart Disease by Gender \n"
				<< "(2) Compare Heart Disease by Age Group \n"
				<< "(3) Exercise Induced Angina \n"
				<< "(4) Most Common Chest Pain Types \n"
				<< "(5) Volume with Diabetes, High Blood Pressure and Cholesterol \n"
				<< "(6) Number of Vessels Highlighted by Fluoroscopy \n"
				<< "(7) General Summary \n"
				<< "(8) Exit \n";
			cout << "Choose an item (1-8) \n";
			cin >> setw(1) >> choice;

			//clear stream
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		return choice;
	}

int printMenu3()
{
	//gets input 
	int pick = 0;
	cout << "Pick an Option \n"
		<< "(1) Diabeties \n"
		<< "(2) High Blood Pressure \n"
		<< "(3) Cholesterol \n"
		<< "(4) Exit \n";
	cin >> setw(1) >> pick;
	return pick;
}

void compGender(const vector<Records>& v)
{
	system("cls");
	ofstream outfile("Gender_Results.txt");
	int numMales = 0;		double malePerc = 0;
	int numFemales = 0;	double femalePerc = 0;
	int max = 0;				double diseasePerc = 0;
	int disease = 0;		int nodisease = 0;
	double nodiseasePerc = 0;
	int disMales = 0;		int nodisMale = 0;
	int disFemales = 0; int nodisFem = 0;
	cout << "\n" << "Gender Summary" << "\n";
	cout << "\n" << "Number of Patients: " << v.size() << "\n";
	outfile << "\n" << "Gender Summary" << "\n";
	outfile << "\n" << "Number of Patients: " << v.size() << "\n";

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].Sex == 0 || v[i].Sex == 1)
		{
			continue;
		}
		else
		{
			cout << "line: " << i + 1 << "\n";
			throw domain_error("Incorrect Value for Gender Found");
		}
	}
	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].target == 0)
		{
			++disease;

		}
		if (v[i].target == 1)
		{
			++nodisease;
		}
		if (v[i].Sex == 1)
		{
			++numMales;
		}
		if (v[i].Sex == 0)
		{
			++numFemales;
		}
		if (v[i].Sex == 1 && v[i].target == 0)
		{
			++disMales;
		}
		if (v[i].Sex == 0 && v[i].target == 0)
		{
			++disFemales;
		}
		if (v[i].Sex == 1 && v[i].target == 1)
		{
			++nodisMale;
		}
		if (v[i].Sex == 0 && v[i].target == 1)
		{
			++nodisFem;
		}

	}

	malePerc = round((((double)disMales) / numMales) * 100);
	femalePerc = round((((double)disFemales) / numFemales) * 100);
	diseasePerc = round((((double)disease) / v.size()) * 100);
	nodiseasePerc = round((((double)nodisease) / v.size()) * 100);
	cout << "\n";
	outfile << "\n";
	cout << "Number of Males: " << setw(6) << numMales << endl;
	outfile << "Number of Males: " << setw(6) << numMales << endl;
	cout << "Number of Females: " << setw(4) << numFemales << endl;
	outfile << "Number of Females: " << setw(4) << numFemales << endl;
	cout << string(30, '-') << endl;
	outfile << string(30, '-') << endl;
	cout << "\n" << "Number without Heart Disease: " << nodisease << " (" << nodiseasePerc << "%)" << "\n" << endl;
	outfile << "Number without Heart Disease: " << nodisease << " (" << nodiseasePerc << "%)" << "\n" << endl;
	cout << "Males without Heart Disease: " << setw(4) << nodisMale << endl;
	outfile << "Males without Heart Disease: " << nodisMale << endl;
	cout << "Females without Heart Disease: " << nodisFem << endl;
	outfile << "Females without Heart Disease: " << nodisFem << endl;
	cout << string(30, '-') << endl;
	outfile << string(30, '-') << endl;
	cout << "\n" << "Number with Heart Disease: " << disease << " (" << diseasePerc << "%)" << "\n" << endl;
	outfile << "Number with Heart Disease: " << disease << " (" << diseasePerc << "%)" << "\n" << endl;
	cout << "Males with Heart Disease: " << setw(4) << disMales << " (" << malePerc << "%)" << endl;
	outfile << "Males with Heart Disease: " << disMales << " (" << malePerc << "%)" << endl;
	cout << "Females with Heart Disease: " << disFemales << " (" << femalePerc << "%)" << endl;
	outfile << "Females with Heart Disease: " << disFemales << " (" << femalePerc << "%)" << endl;
	cout << string(30, '-') << endl;
	outfile << string(30, '-') << endl;


	system("pause");
}

void compdisAge(const vector<Records>& v, int L)
{
	ofstream outfile("DisAge_Results.txt");
	int disMales = 0;
	int disFemales = 0;
	double distotalAgeM = 0;
	double distotalAgeF = 0;
	double distotalAge = 0;
	int disLowest_Age = 100;
	int disHighest_Age = 0;


	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].Age < disLowest_Age)
		{
			disLowest_Age = v[i].Age;
		}
		if (v[i].Age > disHighest_Age)
		{
			disHighest_Age = v[i].Age;
		}
		distotalAge += v[i].Age;
	}
	double disAverageAge = round(((double)distotalAge) / v.size());

	cout << "\n" << "Age Data for Patients with Heart Disease" << "\n";
	outfile << "\n" << "Age Data for Patients with Heart Disease" << "\n";
	cout << "Lowest Age: " << disLowest_Age << "\n";
	outfile << "Lowest Age: " << disLowest_Age << "\n";
	cout << "Higest Age: " << disHighest_Age << "\n";
	outfile << "Higest Age: " << disHighest_Age << "\n";
	cout << "Average Age: " << disAverageAge << "\n";
	outfile << "Average Age: " << disAverageAge << "\n";

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].Sex == 1)
		{
			++disMales;
			distotalAgeM += v[i].Age;
		}
		else
		{
			++disFemales;
			distotalAgeF += v[i].Age;
		}
	}
	double avgMaleAge = round(((double)distotalAgeM) / disMales);
	double avgFemaleAge = round(((double)distotalAgeF) / disFemales);

	cout << "Average Male Age: " << avgMaleAge << endl;
	outfile << "Average Male Age: " << avgMaleAge << endl;
	cout << "Average Female Age: " << avgFemaleAge << "\n" << "\n";
	outfile << "Average Female Age: " << avgFemaleAge << "\n" << "\n";

	//creates the ranges for the bins of the histogram
	for (int i = 0; i < 5; i++)
	{
		cout << i << ": " << (L + (i * 10)) << "-" << (L + (i + 1) * 10) << ", ";
		outfile << i << ": " << (L + (i * 10)) << "-" << (L + (i + 1) * 10) << ", ";
	}
	int n[5] = { 0,0,0,0,0 };
	//determines the quantity in each bin
	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].Age >= L && v[i].Age <= (L+10))
			n[0]++;
		if (v[i].Age > (L+10) && v[i].Age <= (L+20))
			n[1]++;
		if (v[i].Age > (L+20) && v[i].Age <= (L+30))
			n[2]++;
		if (v[i].Age > (L+30) && v[i].Age <= (L+40))
			n[3]++;
		if (v[i].Age > (L+40) && v[i].Age <= (L+50))
			n[4]++;
	}
	//outputs histogram
	cout << "\n" << endl;
	outfile << "\n" << endl;
	cout << "0 " << n[0] << "   " << string((n[0] / 4), '*') << '\n';
	outfile << "0 " << n[0] << "  " << string((n[0] / 4), '*') << '\n';
	cout << "1 " << n[1] << "  " << string((n[1] / 4), '*') << '\n';
	outfile << "1 " << n[1] << "  " << string((n[1] / 4), '*') << '\n';
	cout << "2 " << n[2] << "  " << string((n[2] / 4), '*') << '\n';
	outfile << "2 " << n[2] << "  " << string((n[2] / 4), '*') << '\n';
	cout << "3 " << n[3] << "  " << string((n[3] / 4), '*') << '\n';
	outfile << "3 " << n[3] << "  " << string((n[3] / 4), '*') << '\n';
	cout << "4 " << n[4] << "   " << string((n[4] / 4), '*') << '\n';
	outfile << "4 " << n[4] << "   " << string((n[4] / 4), '*') << '\n';

	cout << "\n" << "Each Star Represents 4 Persons." << "\n";
	outfile << "\n" << "Each Star Represents 4 Persons." << "\n";
	cout << string(41, '-') << endl;
	outfile << string(41, '-') << endl;

	system("pause");
}

int compAge(const vector<Records>& v)
{
	ofstream outfile("Age_Results.txt");
	system("cls");
	int numMales = 0;
	int numFemales = 0;
	double totalAgeM = 0.0;
	double totalAgeF = 0.0;
	double totalAge = 0.0;
	int Lowest_Age = 100;
	int Highest_Age = 0;

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].Age < Lowest_Age)
		{
			Lowest_Age = v[i].Age;
		}
		if (v[i].Age > Highest_Age)
		{
			Highest_Age = v[i].Age;
		}
		totalAge += v[i].Age;
	}
	double AverageAge = round(((double)totalAge) / v.size());

	cout << "Age Data for all Patients" << "\n";
	outfile << "Age Data for all Patients" << "\n";
	cout << "Lowest Age: " << Lowest_Age << "\n";
	outfile << "Lowest Age: " << Lowest_Age << "\n";
	cout << "Higest Age: " << Highest_Age << "\n";
	outfile << "Higest Age: " << Highest_Age << "\n";
	cout << "Average Age: " << AverageAge << "\n";
	outfile << "Average Age: " << AverageAge << "\n";

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].Sex == 1)
		{
			++numMales;
			totalAgeM += v[i].Age;
		}
		else
		{
			++numFemales;
			totalAgeF += v[i].Age;
		}
	}
	double avgMaleAge = round(((double)totalAgeM) / numMales);
	double avgFemaleAge = round(((double)totalAgeF) / numFemales);

	cout << "Average Male Age: " << avgMaleAge << endl;
	outfile << "Average Male Age: " << avgMaleAge << endl;
	cout << "Average Female Age: " << avgFemaleAge << "\n" << "\n";
	outfile << "Average Female Age: " << avgFemaleAge << "\n" << "\n";

	for (int i = 0; i < 5; i++)
	{
		cout << i << ": " << (Lowest_Age + (i * 10)) << "-" << (Lowest_Age + (i + 1) * 10) << ", ";
		outfile << i << ": " << (Lowest_Age + (i * 10)) << "-" << (Lowest_Age + (i + 1) * 10) << ", ";
	}
	int n[5] = { 0,0,0,0,0 };

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].Age >= Lowest_Age && v[i].Age <= (Lowest_Age + 10))
			n[0]++;
		if (v[i].Age > (Lowest_Age + 10) && v[i].Age <= (Lowest_Age + 20))
			n[1]++;
		if (v[i].Age > (Lowest_Age + 20) && v[i].Age <= (Lowest_Age + 30))
			n[2]++;
		if (v[i].Age > (Lowest_Age + 30) && v[i].Age <= (Lowest_Age + 40))
			n[3]++;
		if (v[i].Age > (Lowest_Age + 40) && v[i].Age <= (Lowest_Age + 50))
			n[4]++;
	}
	cout << "\n" << endl;
	outfile << "\n" << endl;
	cout << "0 " << n[0] << "  " << string((n[0] / 5), '*') << '\n';
	outfile << "0 " << n[0] << "  " << string((n[0] / 5), '*') << '\n';
	cout << "1 " << n[1] << "  " << string((n[1] / 5), '*') << '\n';
	outfile << "1 " << n[1] << "  " << string((n[1] / 5), '*') << '\n';
	cout << "2 " << n[2] << " " << string((n[2] / 5), '*') << '\n';
	outfile << "2 " << n[2] << " " << string((n[2] / 5), '*') << '\n';
	cout << "3 " << n[3] << "  " << string((n[3] / 5), '*') << '\n';
	outfile << "3 " << n[3] << "  " << string((n[3] / 5), '*') << '\n';
	cout << "4 " << n[4] << "  " << string((n[4] / 5), '*') << '\n';
	outfile << "4 " << n[4] << "  " << string((n[4] / 5), '*') << '\n';

	cout << "\n" << "Each Star Represents 5 Persons." << "\n";
	outfile << "\n" << "Each Star Represents 5 Persons." << "\n";
	cout << string(41, '-') << endl;
	outfile << string(41, '-') << endl;
	return Lowest_Age;

}

void compExang(const vector<Records>& v)
{
	system("cls");
	ofstream outfile("Exang_Results.txt");
	int numYes = 0;		int Yes = 0;
	int numNo = 0;		int No = 0;
	int WithDis = 0;	int WoDis = 0;
	int NoexDis = 0;	int NoexDisPerc = 0;
	int exDis = 0;		int exDisPerc = 0;
	cout << "\n" << "Exercised Induced Angina Summary" << "\n";
	outfile << "\n" << "Exercised Induced Angina Summary" << "\n";
	cout << "\n" << "All Patients: " << v.size() << "\n";
	outfile << "\n" << "All Patients: " << v.size() << "\n";

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].exang == 0 || v[i].exang == 1)
		{
			continue;
		}
		else
		{
			cout << "line: " << i + 1 << "\n";
			throw domain_error("Incorrect Binary for Exercised Induced Angina Found");
		}
	}

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].target == 0)
		{
			++WithDis;
		}
		if (v[i].target == 1)
		{
			++WoDis;
		}
		if (v[i].exang == 0)
		{
			++No;
		}
		if (v[i].exang == 1)
		{
			++Yes;
		}
		if (v[i].exang == 0 && v[i].target == 1)
		{
			++numNo;
		}
		if (v[i].exang == 1 && v[i].target == 1)
		{
			++numYes;
		}
		if (v[i].exang == 0 && v[i].target == 0)
		{
			++NoexDis;
		}
		if (v[i].exang == 1 && v[i].target == 0)
		{
			++exDis;
		}
	}
	NoexDisPerc = round((((double)NoexDis) / No) * 100);
	exDisPerc = round((((double)exDis) / Yes) * 100);
	cout << "\n" << "Exercise Induced Angina Experienced:" << endl;
	outfile << "\n" << "Exercise Induced Angina Experienced:" << endl;
	cout << "No: " << No << endl;
	outfile << "No: " << No << endl;
	cout << "Yes: " << setw(1) << Yes << endl;
	outfile << "Yes: " << setw(1) << Yes << endl;
	cout << string(36, '-') << endl;
	outfile << string(36, '-') << endl;
	cout << "\n" << "Non Heart Disease Patients: " << WoDis << endl;
	outfile << "\n" << "Non Heart Disease Patients: " << WoDis << endl;
	cout << "\n" << "Exercise Induced Angina Experienced:" << endl;
	outfile << "\n" << "Exercise Induced Angina Experienced:" << endl;
	cout << "No: " << numNo << endl;
	outfile << "No: " << numNo << endl;
	cout << "Yes: " << setw(1) << numYes << endl;
	outfile << "Yes: " << setw(1) << numYes << endl;
	cout << string(36, '-') << endl;
	outfile << string(36, '-') << endl;
	cout << "\n" << "Heart Disease Patients: " << WithDis << "\n";
	outfile << "\n" << "Heart Disease Patients: " << WithDis << "\n";
	cout << "\n" << "Exercise Induced Angina Experienced:" << endl;
	outfile << "\n" << "Exercise Induced Angina Experienced:" << endl;
	cout << "No: " << NoexDis << " (" << NoexDisPerc << "%)" << endl;
	outfile << "No: " << NoexDis << " (" << NoexDisPerc << "%)" << endl;
	cout << "Yes: " << exDis << " (" << exDisPerc << "%)" << endl;
	outfile << "Yes: " << exDis << " (" << exDisPerc << "%)" << endl;
	cout << string(36, '-') << endl;
	outfile << string(36, '-') << endl;

	system("pause");
}

void compPain(const vector<Records>& v)
{
	system("cls");
	ofstream outfile("ChestPain_Results.txt");
	int TypF = 0; int AtypF = 0; int NonAngF = 0; int AsympF = 0;
	int TypM = 0; int AtypM = 0; int NonAngM = 0; int AsympM = 0;
	int hdTypF = 0; int hdAtypF = 0; int hdNonAngF = 0; int hdAsympF = 0;
	int hdTypM = 0; int hdAtypM = 0; int hdNonAngM = 0; int hdAsympM = 0;
	int Typical = 0;
	int Atypical = 0;
	int Non_Anginal = 0;
	int Asymptomatic = 0;
	int HD = 0;  int NoHD = 0;
	int hdAsymp = 0;
	int hdAtyp = 0;
	int hdTyp = 0;
	int hdNonAng = 0;
	cout << "\n" << "Chest Pain Summary" << "\n";
	cout << "\n" << "Total Patients: " << v.size() << "\n";
	outfile << "\n" << "Chest Pain Summary" << "\n";
	outfile << "\n" << "Total Patients: " << v.size() << "\n";

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].Chest_Pain == 0 || v[i].Chest_Pain == 1 || v[i].Chest_Pain == 2 || v[i].Chest_Pain == 3)
		{
			continue;
		}
		else
		{
			cout << "line: " << i + 1 << "\n";
			throw domain_error("Incorrect Value for Chest Pain Found");
		}
	}

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].target == 1)
		{
			++NoHD;
		}
		if (v[i].Chest_Pain == 0 && v[i].target == 1)
		{
			++Asymptomatic;
		}
		if (v[i].Chest_Pain == 0 && v[i].Sex == 1 && v[i].target == 1)
		{
			++AsympM;
		}
		if (v[i].Chest_Pain == 0 && v[i].Sex == 0 && v[i].target == 1)
		{
			++AsympF;
		}
		if (v[i].Chest_Pain == 1 && v[i].target == 1)
		{
			++Atypical;
		}
		if (v[i].Chest_Pain == 1 && v[i].Sex == 1 && v[i].target == 1)
		{
			++AtypM;
		}
		if (v[i].Chest_Pain == 1 && v[i].Sex == 0 && v[i].target == 1)
		{
			++AtypF;
		}
		if (v[i].Chest_Pain == 2 && v[i].target == 1)
		{
			++Non_Anginal;
		}
		if (v[i].Chest_Pain == 2 && v[i].Sex == 1 && v[i].target == 1)
		{
			++NonAngM;
		}
		if (v[i].Chest_Pain == 2 && v[i].Sex == 0 && v[i].target == 1)
		{
			++NonAngF;
		}
		if (v[i].Chest_Pain == 3 && v[i].target == 1)
		{
			++Typical;
		}
		if (v[i].Chest_Pain == 3 && v[i].Sex == 1 && v[i].target == 1)
		{
			++TypM;
		}
		if (v[i].Chest_Pain == 3 && v[i].Sex == 0 && v[i].target == 1)
		{
			++TypF;
		}
	}
	cout << "\n" << "Number of Non Heart Disease Patients: " << NoHD << "\n";
	outfile << "\n" << "Number of Non Heart Disease Patients: " << NoHD << "\n";

	cout << "\n" << "Chest Pain Type" << setw(23) << "Number of Patients" << setw(9) << "Male" << setw(11) << "Female" << "\n";
	outfile << "\n" << "Chest Pain Type" << setw(23) << "Number of Patients" << setw(9) << "Male" << setw(11) << "Female" << "\n";

	cout << setw(7) << "Typical" << setw(22) << Typical << setw(17) << TypM << setw(9) << TypF << "\n";
	outfile << setw(7) << "Typical" << setw(22) << Typical << setw(17) << TypM << setw(9) << TypF << "\n";
	cout << setw(8) << "Atypical" << setw(21) << Atypical << setw(17) << AtypM << setw(9) << AtypF << "\n";
	outfile << setw(8) << "Atypical" << setw(21) << Atypical << setw(17) << AtypM << setw(9) << AtypF << "\n";
	cout << setw(4) << "Non Anginal" << setw(18) << Non_Anginal << setw(17) << NonAngM << setw(9) << NonAngF << "\n";
	outfile << setw(4) << "Non Anginal" << setw(18) << Non_Anginal << setw(17) << NonAngM << setw(9) << NonAngF << "\n";
	cout << setw(4) << "Asymptomatic" << setw(17) << Asymptomatic << setw(17) << AsympM << setw(9) << AsympF << "\n";
	outfile << setw(4) << "Asymptomatic" << setw(17) << Asymptomatic << setw(17) << AsympM << setw(9) << AsympF << "\n";
	cout << string(58, '-') << "\n";
	outfile << string(58, '-') << "\n";

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].target == 0)
		{
			++HD;
		}
		if (v[i].Chest_Pain == 0 && v[i].target == 0)
		{
			++hdAsymp;
		}
		if (v[i].Chest_Pain == 0 && v[i].target == 0 && v[i].Sex == 1)
		{
			++hdAsympM;
		}
		if (v[i].Chest_Pain == 0 && v[i].target == 0 && v[i].Sex == 0)
		{
			++hdAsympF;
		}
		if (v[i].Chest_Pain == 1 && v[i].target == 0)
		{
			++hdAtyp;
		}
		if (v[i].Chest_Pain == 1 && v[i].target == 0 && v[i].Sex == 1)
		{
			++hdAtypM;
		}
		if (v[i].Chest_Pain == 1 && v[i].target == 0 && v[i].Sex == 0)
		{
			++hdAtypF;
		}
		if (v[i].Chest_Pain == 2 && v[i].target == 0)
		{
			++hdNonAng;
		}
		if (v[i].Chest_Pain == 2 && v[i].target == 0 && v[i].Sex == 1)
		{
			++hdNonAngM;
		}
		if (v[i].Chest_Pain == 2 && v[i].target == 0 && v[i].Sex == 0)
		{
			++hdNonAngF;
		}
		if (v[i].Chest_Pain == 3 && v[i].target == 0)
		{
			++hdTyp;
		}
		if (v[i].Chest_Pain == 3 && v[i].target == 0 && v[i].Sex == 1)
		{
			++hdTypM;
		}
		if (v[i].Chest_Pain == 3 && v[i].target == 0 && v[i].Sex == 0)
		{
			++hdTypF;
		}
	}
	cout << "\n" << "Number of Heart Disease Patients: " << HD << "\n";
	outfile << "\n" << "Number of Heart Disease Patients: " << HD << "\n";

	cout << "\n" << "Chest Pain Type" << setw(23) << "Number of Patients" << setw(9) << "Male" << setw(11) << "Female" << "\n";
	outfile << "\n" << "Chest Pain Type" << setw(23) << "Number of Patients" << setw(9) << "Male" << setw(11) << "Female" << "\n";

	cout << setw(7) << "Typical" << setw(22) << hdTyp << setw(17) << hdTypM << setw(9) << hdTypF << "\n";
	outfile << setw(7) << "Typical" << setw(22) << hdTyp << setw(17) << hdTypM << setw(9) << hdTypF << "\n";
	cout << setw(8) << "Atypical" << setw(21) << hdAtyp << setw(17) << hdAtypM << setw(9) << hdAtypF << "\n";
	outfile << setw(8) << "Atypical" << setw(21) << hdAtyp << setw(17) << hdAtypM << setw(9) << hdAtypF << "\n";
	cout << setw(4) << "Non Anginal" << setw(18) << hdNonAng << setw(17) << hdNonAngM << setw(9) << hdNonAngF << "\n";
	outfile << setw(4) << "Non Anginal" << setw(18) << hdNonAng << setw(17) << hdNonAngM << setw(9) << hdNonAngF << "\n";
	cout << setw(4) << "Asymptomatic" << setw(17) << hdAsymp << setw(17) << hdAsympM << setw(9) << hdAsympF << "\n";
	outfile << setw(4) << "Asymptomatic" << setw(17) << hdAsymp << setw(17) << hdAsympM << setw(9) << hdAsympF << "\n";
	cout << string(58, '-') << "\n";
	outfile << string(58, '-') << "\n";

	system("pause");
}

void compFbs(const vector<Records>& v)
{
	system("cls");
	ofstream outfile("Diabetes_Results.txt");
	int Yes = 0;		int YesPerc = 0;
	int No = 0;			int NoPerc = 0;
	int Yfbs1 = 0;	int Yfbs1Perc = 0;
	int Yfbs0 = 0;	int Yfbs0Perc = 0;
	int Nfbs1 = 0;	int Nfbs1Perc = 0;
	int Nfbs0 = 0;	int Nfbs0Perc = 0;
	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].fbs == 0 || v[i].fbs == 1)
		{
			continue;
		}
		else
		{
			cout << "line: " << i + 1 << "\n";
			throw domain_error("Incorrect Binary for Fasting Blood Sugar Found");
		}
	}
	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].target == 0)
		{
			++Yes;
		}
		if (v[i].target == 1)
		{
			++No;
		}
		if (v[i].target == 0 && v[i].fbs == 1)
		{
			++Yfbs1;
		}
		if (v[i].target == 0 && v[i].fbs == 0)
		{
			++Yfbs0;
		}
		if (v[i].target == 1 && v[i].fbs == 1)
		{
			++Nfbs1;
		}
		if (v[i].target == 1 && v[i].fbs == 0)
		{
			++Nfbs0;
		}
	}
	YesPerc = round((((double)Yes) / v.size()) * 100);
	NoPerc = round((((double)No) / v.size()) * 100);
	Yfbs1Perc = round((((double)Yfbs1) / Yes) * 100);
	Yfbs0Perc = round((((double)Yfbs0) / Yes) * 100);
	Nfbs1Perc = round((((double)Nfbs1) / No) * 100);
	Nfbs0Perc = round((((double)Nfbs0) / No) * 100);
	//outputs probability tree
	cout << setw(30) << "Heart Disease" << endl;
	outfile << setw(30) << "Heart Disease" << endl;
	cout << setw(16) << "/" << setw(16) << "\\" << endl;
	outfile << setw(16) << "/" << setw(16) << "\\" << endl;
	cout << setw(15) << "/" << setw(18) << "\\" << endl;
	outfile << setw(15) << "/" << setw(18) << "\\" << endl;
	cout << setw(14) << "/" << setw(20) << "\\" << endl;
	outfile << setw(14) << "/" << setw(20) << "\\" << endl;
	cout << setw(14) << "Yes" << setw(22) << "No" << endl;
	outfile << setw(14) << "Yes" << setw(22) << "No" << endl;
	cout << setw(14) << Yes << setw(23) << No << endl;
	outfile << setw(14) << Yes << setw(23) << No << endl;
	cout << setw(13) << YesPerc << "%" << setw(22) << NoPerc << "%" << endl;
	outfile << setw(13) << YesPerc << "%" << setw(22) << NoPerc << "%" << endl;
	cout << setw(11) << "/" << setw(4) << "\\" << setw(19) << "/" << setw(4) << "\\" << endl;
	outfile << setw(11) << "/" << setw(4) << "\\" << setw(19) << "/" << setw(4) << "\\" << endl;
	cout << setw(10) << "/" << setw(6) << "\\" << setw(17) << "/" << setw(6) << "\\" << endl;
	outfile << setw(10) << "/" << setw(6) << "\\" << setw(17) << "/" << setw(6) << "\\" << endl;
	cout << setw(9) << "/" << setw(8) << "\\" << setw(15) << "/" << setw(8) << "\\" << endl;
	outfile << setw(9) << "/" << setw(8) << "\\" << setw(15) << "/" << setw(8) << "\\" << endl;
	cout << setw(8) << "/" << setw(10) << "\\" << setw(13) << "/" << setw(10) << "\\" << endl;
	outfile << setw(8) << "/" << setw(10) << "\\" << setw(13) << "/" << setw(10) << "\\" << endl;
	cout << setw(8) << "fbs>120" << setw(15) << "fbs<120" << setw(12) << "fbs>120" << setw(12) << "fbs<120" << endl;
	outfile << setw(8) << "fbs>120" << setw(15) << "fbs<120" << setw(12) << "fbs>120" << setw(12) << "fbs<120" << endl;
	cout << setw(6) << Yfbs1 << setw(15) << Yfbs0 << setw(12) << Nfbs1 << setw(12) << Nfbs0 << endl;
	outfile << setw(6) << Yfbs1 << setw(15) << Yfbs0 << setw(12) << Nfbs1 << setw(12) << Nfbs0 << endl;
	cout << setw(6) << Yfbs1Perc << "%" << setw(13) << Yfbs0Perc << "%" << setw(12) << Nfbs1Perc << "%" << setw(10) << Nfbs0Perc << "%" << endl;
	outfile << setw(6) << Yfbs1Perc << "%" << setw(13) << Yfbs0Perc << "%" << setw(12) << Nfbs1Perc << "%" << setw(10) << Nfbs0Perc << "%" << endl;
	cout << string(50, '-') << endl;
	outfile << string(50, '-') << endl;

	system("pause");
}

void compBps(const vector<Records>& v)
{
	system("cls");
	ofstream outfile("BloodPressure_Results.txt");
	int Yes = 0;		int YesPerc = 0;
	int No = 0;			int NoPerc = 0;
	int Ybps1 = 0;	int Ybps1Perc = 0;
	int Ybps0 = 0;	int Ybps0Perc = 0;
	int Nbps1 = 0;	int Nbps1Perc = 0;
	int Nbps0 = 0;	int Nbps0Perc = 0;
	int totalbps1 = 0;
	int totalbps0 = 0;
	double Avgbps1 = 0;
	double Avgbps0 = 0;
	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].target == 0)
		{
			++Yes;
			totalbps1 += v[i].Threstbps;

		}
		if (v[i].target == 1)
		{
			++No;
			totalbps0 += v[i].Threstbps;
		}
		if ((v[i].target == 0) && (v[i].Threstbps >= 120))
		{
			++Ybps1;
		}
		if (v[i].target == 0 && v[i].Threstbps < 120)
		{
			++Ybps0;
		}
		if ((v[i].target == 1) && (v[i].Threstbps >= 120))
		{
			++Nbps1;
		}
		if (v[i].target == 1 && v[i].Threstbps < 120)
		{
			++Nbps0;
		}
	}
	Avgbps1 = totalbps1 / Yes;
	Avgbps0 = totalbps0 / No;
	YesPerc = round((((double)Yes) / v.size()) * 100);
	NoPerc = round((((double)No) / v.size()) * 100);
	Ybps1Perc = round((((double)Ybps1) / Yes) * 100);
	Ybps0Perc = round((((double)Ybps0) / Yes) * 100);
	Nbps1Perc = round((((double)Nbps1) / No) * 100);
	Nbps0Perc = round((((double)Nbps0) / No) * 100);
	cout << setw(30) << "Heart Disease" << endl;
	outfile << setw(30) << "Heart Disease" << endl;
	cout << setw(16) << "/" << setw(16) << "\\" << endl;
	outfile << setw(16) << "/" << setw(16) << "\\" << endl;
	cout << setw(15) << "/" << setw(18) << "\\" << endl;
	outfile << setw(15) << "/" << setw(18) << "\\" << endl;
	cout << setw(14) << "/" << setw(20) << "\\" << endl;
	outfile << setw(14) << "/" << setw(20) << "\\" << endl;
	cout << setw(14) << "Yes" << setw(22) << "No" << endl;
	outfile << setw(14) << "Yes" << setw(22) << "No" << endl;
	cout << setw(14) << Yes << setw(23) << No << endl;
	outfile << setw(14) << Yes << setw(23) << No << endl;
	cout << setw(13) << YesPerc << "%" << setw(22) << NoPerc << "%" << endl;
	outfile << setw(13) << YesPerc << "%" << setw(22) << NoPerc << "%" << endl;
	cout << setw(11) << "/" << setw(4) << "\\" << setw(19) << "/" << setw(4) << "\\" << endl;
	outfile << setw(11) << "/" << setw(4) << "\\" << setw(19) << "/" << setw(4) << "\\" << endl;
	cout << setw(10) << "/" << setw(6) << "\\" << setw(17) << "/" << setw(6) << "\\" << endl;
	outfile << setw(10) << "/" << setw(6) << "\\" << setw(17) << "/" << setw(6) << "\\" << endl;
	cout << setw(9) << "/" << setw(8) << "\\" << setw(15) << "/" << setw(8) << "\\" << endl;
	outfile << setw(9) << "/" << setw(8) << "\\" << setw(15) << "/" << setw(8) << "\\" << endl;
	cout << setw(8) << "/" << setw(10) << "\\" << setw(13) << "/" << setw(10) << "\\" << endl;
	outfile << setw(8) << "/" << setw(10) << "\\" << setw(13) << "/" << setw(10) << "\\" << endl;
	cout << setw(8) << "bps>120" << setw(15) << "bps<120" << setw(12) << "bps>120" << setw(12) << "bps<120" << endl;
	outfile << setw(8) << "bps>120" << setw(15) << "bps<120" << setw(12) << "bps>120" << setw(12) << "bps<120" << endl;
	cout << setw(6) << Ybps1 << setw(15) << Ybps0 << setw(12) << Nbps1 << setw(12) << Nbps0 << endl;
	outfile << setw(6) << Ybps1 << setw(15) << Ybps0 << setw(12) << Nbps1 << setw(12) << Nbps0 << endl;
	cout << setw(6) << Ybps1Perc << "%" << setw(13) << Ybps0Perc << "%" << setw(12) << Nbps1Perc << "%" << setw(10) << Nbps0Perc << "%" << endl;
	outfile << setw(6) << Ybps1Perc << "%" << setw(13) << Ybps0Perc << "%" << setw(12) << Nbps1Perc << "%" << setw(10) << Nbps0Perc << "%" << endl;
	cout << "\n";
	outfile << "\n";
	cout << "Average Blood Pressure For Heart Disease Patients: " << Avgbps1 << "\n" << endl;
	outfile << "Average Blood Pressure For Heart Disease Patients: " << Avgbps1 << "\n" << endl;
	cout << "Average Blood Pressure For Non Heart Disease Patients: " << Avgbps0 << endl;
	outfile << "Average Blood Pressure For Non Heart Disease Patients: " << Avgbps0 << endl;
	cout << string(59, '-') << endl;
	outfile << string(59, '-') << endl;

	system("pause");
}

void compChol(const vector<Records>& v)
{
	system("cls");
	ofstream outfile("Chol_Results.txt");
	int Yes = 0;		int YesPerc = 0;
	int No = 0;			int NoPerc = 0;
	int Ychol1 = 0;	int Ychol1Perc = 0;
	int Ychol0 = 0;	int Ychol0Perc = 0;
	int Nchol1 = 0;	int Nchol1Perc = 0;
	int Nchol0 = 0;	int Nchol0Perc = 0;
	int totalchol1 = 0;
	int totalchol0 = 0;
	double Avgchol1 = 0;
	double Avgchol0 = 0;
	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].target == 0)
		{
			++Yes;
			totalchol1 += v[i].chol;

		}
		if (v[i].target == 1)
		{
			++No;
			totalchol0 += v[i].chol;
		}
		if ((v[i].target == 0) && (v[i].chol >= 240))
		{
			++Ychol1;
		}
		if (v[i].target == 0 && v[i].chol < 240)
		{
			++Ychol0;
		}
		if ((v[i].target == 1) && (v[i].chol >= 240))
		{
			++Nchol1;
		}
		if (v[i].target == 1 && v[i].chol < 240)
		{
			++Nchol0;
		}
	}
	Avgchol1 = totalchol1 / Yes;
	Avgchol0 = totalchol0 / No;
	YesPerc = round((((double)Yes) / v.size()) * 100);
	NoPerc = round((((double)No) / v.size()) * 100);
	Ychol1Perc = round((((double)Ychol1) / Yes) * 100);
	Ychol0Perc = round((((double)Ychol0) / Yes) * 100);
	Nchol1Perc = round((((double)Nchol1) / No) * 100);
	Nchol0Perc = round((((double)Nchol0) / No) * 100);
	cout << setw(30) << "Heart Disease" << endl;
	outfile << setw(30) << "Heart Disease" << endl;
	cout << setw(16) << "/" << setw(16) << "\\" << endl;
	outfile << setw(16) << "/" << setw(16) << "\\" << endl;
	cout << setw(15) << "/" << setw(18) << "\\" << endl;
	outfile << setw(15) << "/" << setw(18) << "\\" << endl;
	cout << setw(14) << "/" << setw(20) << "\\" << endl;
	outfile << setw(14) << "/" << setw(20) << "\\" << endl;
	cout << setw(14) << "Yes" << setw(22) << "No" << endl;
	outfile << setw(14) << "Yes" << setw(22) << "No" << endl;
	cout << setw(14) << Yes << setw(23) << No << endl;
	outfile << setw(14) << Yes << setw(23) << No << endl;
	cout << setw(13) << YesPerc << "%" << setw(22) << NoPerc << "%" << endl;
	outfile << setw(13) << YesPerc << "%" << setw(22) << NoPerc << "%" << endl;
	cout << setw(11) << "/" << setw(4) << "\\" << setw(19) << "/" << setw(4) << "\\" << endl;
	outfile << setw(11) << "/" << setw(4) << "\\" << setw(19) << "/" << setw(4) << "\\" << endl;
	cout << setw(10) << "/" << setw(6) << "\\" << setw(17) << "/" << setw(6) << "\\" << endl;
	outfile << setw(10) << "/" << setw(6) << "\\" << setw(17) << "/" << setw(6) << "\\" << endl;
	cout << setw(9) << "/" << setw(8) << "\\" << setw(15) << "/" << setw(8) << "\\" << endl;
	outfile << setw(9) << "/" << setw(8) << "\\" << setw(15) << "/" << setw(8) << "\\" << endl;
	cout << setw(8) << "/" << setw(10) << "\\" << setw(13) << "/" << setw(10) << "\\" << endl;
	outfile << setw(8) << "/" << setw(10) << "\\" << setw(13) << "/" << setw(10) << "\\" << endl;
	cout << setw(8) << "chol>240" << setw(15) << "chol<240" << setw(12) << "chol>240" << setw(12) << "chol<240" << endl;
	outfile << setw(8) << "chol>240" << setw(15) << "chol<240" << setw(12) << "chol>240" << setw(12) << "chol<240" << endl;
	cout << setw(6) << Ychol1 << setw(15) << Ychol0 << setw(12) << Nchol1 << setw(12) << Nchol0 << endl;
	outfile << setw(6) << Ychol1 << setw(15) << Ychol0 << setw(12) << Nchol1 << setw(12) << Nchol0 << endl;
	cout << setw(6) << Ychol1Perc << "%" << setw(13) << Ychol0Perc << "%" << setw(12) << Nchol1Perc << "%" << setw(10) << Nchol0Perc << "%" << endl;
	outfile << setw(6) << Ychol1Perc << "%" << setw(13) << Ychol0Perc << "%" << setw(12) << Nchol1Perc << "%" << setw(10) << Nchol0Perc << "%" << endl;
	cout << "\n";
	outfile << "\n";
	cout << "Average Cholesterol For Heart Disease Patients: " << Avgchol1 << "\n" << endl;
	outfile << "Average Cholesterol For Heart Disease Patients: " << Avgchol1 << "\n" << endl;
	cout << "Average Cholesterol For Non Heart Disease Patients: " << Avgchol0 << endl;
	outfile << "Average Cholesterol For Non Heart Disease Patients: " << Avgchol0 << endl;
	cout << string(56, '-') << endl;
	outfile << string(56, '-') << endl;

	system("pause");
}

void compCA(const vector<Records>& v)
{
	system("cls");
	ofstream outfile("CA_Results.txt");
	int vessel0 = 0;	int HDvessel0 = 0;
	int vessel1 = 0;	int HDvessel1 = 0;
	int vessel2 = 0;	int HDvessel2 = 0;
	int vessel3 = 0;	int HDvessel3 = 0;
	int HeartDisease = 0;
	int zeroPercent = 0;	int twoPercent = 0;
	int onePercent = 0;		int threePercent = 0;

	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].fluorscopy == 0 || v[i].fluorscopy == 1 || v[i].fluorscopy == 2 || v[i].fluorscopy == 3 || v[i].fluorscopy == 4)
		{
			continue;
		}
		else
		{
			cout << "line: " << i + 1 << "\n";
			throw domain_error("Incorrect Value for CA found");
		}
	}
	for (vector<Records>::size_type i = 0; i != v.size(); ++i)
	{
		if (v[i].target == 0)
		{
			++HeartDisease;
		}
		if (v[i].fluorscopy == 0)
		{
			++vessel0;
		}
		if (v[i].fluorscopy == 1)
		{
			++vessel1;
		}
		if (v[i].fluorscopy == 2)
		{
			++vessel2;
		}
		if (v[i].fluorscopy == 3)
		{
			++vessel3;
		}
		if (v[i].fluorscopy == 0 && v[i].target == 0)
		{
			++HDvessel0;
		}
		if (v[i].fluorscopy == 1 && v[i].target == 0)
		{
			++HDvessel1;
		}
		if (v[i].fluorscopy == 2 && v[i].target == 0)
		{
			++HDvessel2;
		}
		if (v[i].fluorscopy == 3 && v[i].target == 0)
		{
			++HDvessel3;
		}
	}
	zeroPercent = round((((double)HDvessel0) / vessel0) * 100);
	onePercent = round((((double)HDvessel1) / vessel1) * 100);
	twoPercent = round((((double)HDvessel2) / vessel2) * 100);
	threePercent = round((((double)HDvessel3) / vessel3) * 100);

	cout << "Coloured Fluoroscopy Summary: " << endl << endl;
	outfile << "Coloured Fluoroscopy Summary: " << endl << endl;
	cout << "All Patients: " << v.size() << endl << endl;
	outfile << "All Patients: " << v.size() << endl << endl;
	cout << "Number of Blood Vessels Highlighted: " << endl << endl;
	outfile << "Number of Blood Vessels Highlighted: " << endl << endl;
	cout << "0:" << setw(3) << vessel0 << endl;
	outfile << "0:" << setw(3) << vessel0 << endl;
	cout << "1:" << setw(3) << vessel1 << endl;
	outfile << "1:" << setw(3) << vessel1 << endl;
	cout << "2:" << setw(3) << vessel2 << endl;
	outfile << "2:" << setw(3) << vessel2 << endl;
	cout << "3:" << setw(3) << vessel3 << endl << endl;
	outfile << "3:" << setw(3) << vessel3 << endl << endl;
	cout << string(35, '-') << endl;
	outfile << string(35, '-') << endl;
	cout << "Heart Disease Patients: " << HeartDisease << endl << endl;
	outfile << "Heart Disease Patients: " << HeartDisease << endl << endl;
	cout << "Number of Blood Vessels Highlighted: " << endl << endl;
	outfile << "Number of Blood Vessels Highlighted: " << endl << endl;
	cout << "0:" << setw(3) << HDvessel0 << " (" << zeroPercent << "%)" << endl;
	outfile << "0:" << setw(3) << HDvessel0 << " (" << zeroPercent << "%)" << endl;
	cout << "1:" << setw(3) << HDvessel1 << " (" << onePercent << "%)" << endl;
	outfile << "1:" << setw(3) << HDvessel1 << " (" << onePercent << "%)" << endl;
	cout << "2:" << setw(3) << HDvessel2 << " (" << twoPercent << "%)" << endl;
	outfile << "2:" << setw(3) << HDvessel2 << " (" << twoPercent << "%)" << endl;
	cout << "3:" << setw(3) << HDvessel3 << " (" << threePercent << "%)" << endl;
	outfile << "3:" << setw(3) << HDvessel3 << " (" << threePercent << "%)" << endl;
	cout << string(35, '-') << endl;
	outfile << string(35, '-') << endl;
	system("pause");
}

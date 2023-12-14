/// Lab Project 6 - Gross Salary Calculation modualized with functions
/// By Ri'chard McCray
/// CSCI-1-0101
/// Submitted 5/15/23
/// Windows 10
/// Visual Studio 2019
/// Successfully Ran 10:36 AM 5/15/23

//Includes
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

//Prototypes//
void greeting();
double getUserData(double & payRate, string & firstName, string & lastName, bool & healthPlan);
double getGrossSalary(double hoursWorked, double payRate);
double getTaxWitheld(double GrossSalary);
double getNetSalary(double grossSalary, double taxWitheld, bool HealthPlan, string & HealthPlanStatusMessage);
void printResults(const string & firstName, const string & lastName, double hoursWorked, double payRate, double grossSalary, double taxWitheld, double netSalary, const string & HealthPlanStatus);
void goodbye();

int main()
{
	cout << fixed;
	cout << setprecision(2);

	////GetUserData Data////
	string FirstName; //One word Employee first name
	string LastName; //One word Employee last name
	double PayRate; //Hourly Pay Rate of an Employee
	double HoursWorked;
	bool HealthPlan; //Employee's selection or declination of health plan

	string HealthPlanStatusMessage;

	double GrossSalary;
	double TaxWitheld;
	double NetSalary;

	////Main Init////
	greeting();
	HoursWorked = getUserData(PayRate, FirstName, LastName, HealthPlan);
	//cout << "[DEBUG] PayRate: " << PayRate << " FirstName: " << FirstName << " LastName: " << LastName << " Hours Worked: " << HoursWorked << " HealthPlan: " << HealthPlan << endl;

	GrossSalary = getGrossSalary(HoursWorked, PayRate);
	//cout << "[DEBUG] Gross Salary: " << GrossSalary << endl;

	TaxWitheld = getTaxWitheld(GrossSalary);
	//cout << "[DEBUG] TaxWitheld: " << GrossSalary << endl;

	NetSalary = getNetSalary(GrossSalary, TaxWitheld, HealthPlan, HealthPlanStatusMessage);
	//cout << "[DEBUG] NetSalary" << NetSalary << endl;

	printResults(FirstName, LastName, HoursWorked, PayRate, GrossSalary, TaxWitheld, NetSalary, HealthPlanStatusMessage);

	goodbye();

	return 0;
}

void greeting()
{
	cout << "Welcome to salary computation program." << endl;
	cout << "In this program we will ask for the information that would allow us to process your pay check." << endl;
	cout << "We will collect information about hours worked, hourly pay rate and medical options." << endl;
	cout << "Processing will be completed in just few minutes [sic.]" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;

}

double getUserData(double & payRate, string & firstName, string & lastName, bool & healthPlan)
{
	double hours;
	hours = 0; //init as failsafe

	//Name Collection
	cout << "Please enter your First name [One word only]: ";
	cin >> firstName;
	cin.ignore();
	cout << "Please enter your Last name  [One word only]: ";
	cin >> lastName;
	cin.ignore();

	//Hours Worked Collection
	cout << "Please enter hours worked (positive number only): ";
	do
	{
		while (!(cin >> hours)) //get while checking if valid
		{
			cout << "Invalid hours worked entered. Hours must be a number: " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cin.ignore();
		
		if (hours < 0) //make sure number is positive
		{
			cout << "Invalid hours worked entered. Hours must be a value 0 or greater: " << endl;
		}
		else //is positive
		{
			break;
		}
	} while (hours < 0);
	
	//Hourly Rate Collection
	cout << "Please enter hourly pay rate [For example enter 15.23 if your hourly pay rate is $15 and 23 cents]" << endl; 
	while (!(cin >> payRate)) //Just a valid check, doesn't say to check positivity.
	{
		cout << "Invalid employee Pay Rate entered. Pay rate must be a number 0 or above: " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cin.ignore();

	//Determine Health Plan
	cout << "Enter 1 to purchase health plan or 0 (zero) to decline: ";
	do
	{
		while (!(cin >> healthPlan))
		{
			cout << "Please enter a number choice: " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cin.ignore();

		if ((healthPlan != 1) && (healthPlan != 0))
		{
			cout << "Please enter 1 or 2: " << endl;
		}
		else
		{
			break;
		}

	} while ((healthPlan != 1) && (healthPlan != 0));

	return hours;
}

double getGrossSalary(double hoursWorked, double payRate)
{
	double GrossSal;
	GrossSal = 0; //Init for failsafe

	if (hoursWorked <= 40) //If Hours are 40 or below (no raise)
	{
		GrossSal = (hoursWorked * payRate);
	}
	else //If Hours are above 40
	{
		double HoursExtra; //Seperate hours above 40
		HoursExtra = (hoursWorked - 40);
		double RaiseRate; //Make var for extra 50% rate 
		RaiseRate = (1.5 * payRate);

		GrossSal = (40 * payRate);
		GrossSal += (HoursExtra * RaiseRate);
	}

	return GrossSal;
}

double getTaxWitheld(double GrossSalary)
{
	const double ss_tax = 0.071;
	double TaxedAmount;

	TaxedAmount = (GrossSalary * ss_tax);

	return TaxedAmount;
}

double getNetSalary(double grossSalary, double taxWitheld, bool HealthPlan, string & HealthPlanStatusMessage)
{
	double NetSal;
	NetSal = 0;

	NetSal = (grossSalary - taxWitheld); //Deduct tax

	if (HealthPlan == 1) //If Health plan Selected
	{
		if (NetSal < 200) //Salary is too low
		{
			HealthPlanStatusMessage = "Employee opted for health insurance but was declined because of insufficiant salary.";
		}
		else //Salary is enough, they get it
		{
			NetSal = (grossSalary - 200);
			HealthPlanStatusMessage = "Employee opted for health insurance and was successfully registered.";
		}
	}
	else //If health plan was not selected
	{
		NetSal = grossSalary;
		HealthPlanStatusMessage = "Employee did not opt to register in health plan.";
	}

	return NetSal;
}


void printResults(const string & firstName, const string & lastName, double hoursWorked, double payRate, double grossSalary, double taxWitheld, double netSalary, const string & HealthPlanStatusMessage)
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Here are the Employee Payroll details." << endl;

	string fullname = firstName + " " + lastName; //Concat name

	cout << "Name: " << fullname << endl;
	cout << "Hours Worked: " << hoursWorked << " Hours" << endl;
	cout << "Hourly Pay Rate: $" << payRate << endl;
	cout << "Gross Salary: $" << grossSalary << endl;
	cout << "Tax Witheld: $" << taxWitheld << endl;
	cout << HealthPlanStatusMessage << endl;
	cout << "Employee Net Salary: $" << netSalary << endl;

	cout << "----------------------------------------------------------------------------------" << endl;
}

void goodbye() //Obligatory goodbye function
{
	cout << "Thank you for using our program." << endl;
	cout << "Please have a pleasant day." << endl;
}
/// Lab Project 7 - Hourly Workers' Weekly Salary Calculator Using Parallel Arrays
/// By Ri'chard McCray
/// CSCI-1-0101
/// Submitted 0/0/0
/// Windows 10
/// Visual Studio 2019
/// Successfully Ran 00:00 AM 0/0/0

//Includes
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_EMPLOYEES = 15;
const int MAX_EMP_DATA = 4;

//Prototypes
void greeting();
int fillEmployeeArrays(string empNames[], int empHoursWorked[], double empHourlyRate[]); //Will return amount of employees currently relevant
void computeWeeklySalary(int empHoursWorked[], double empHourlyRate[], double empWeeklySalary[], int empCount);
void printTable(const string EmpNames[], int EmpHoursWorked[], double EmpHourlyRate[], double EmpWeeklySalary[], int EmployeeAmount, double AverageSal);
double computeAverageSalary(const double EmpWeeklySalary[], int EmpCount);

int main()
{
	string EmpNames[MAX_EMPLOYEES]; //Employee Names
	int EmpHoursWorked[MAX_EMPLOYEES]; //Employee Hours
	double EmpHourlyRate[MAX_EMPLOYEES]; //Employee Hourly Pay Rate
	double EmpWeeklySalary[MAX_EMPLOYEES]; //Emp Weekly Salary

	int EmpCount; //Called EmpCount in functions
	double AverageSalary; //Passed in Print Func as 

	//// True Init ////

	greeting();

	EmpCount = fillEmployeeArrays(EmpNames, EmpHoursWorked, EmpHourlyRate);

	computeWeeklySalary(EmpHoursWorked, EmpHourlyRate, EmpWeeklySalary, EmpCount);

	AverageSalary = computeAverageSalary(EmpWeeklySalary, EmpCount);

	printTable(EmpNames, EmpHoursWorked, EmpHourlyRate, EmpWeeklySalary, EmpCount, AverageSalary);
}

void greeting()
{
	cout << "This Program 'calculates the weekly salary of hourly workers.'" << endl;
	cout << "It can handle a maximum of 15 Employees. " << endl;
}

int fillEmployeeArrays(string empNames[], int empHoursWorked[], double empHourlyRate[])
{
	int Employees = 0; //Amount of Employees collected

	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		//Gather Name
		cout << "Please enter the Name of Employee (" << (i + 1) << "): ";
		cin >> empNames[i];
		cin.ignore();

		//Gather Emp Hours Worked
		cout << "Please enter Employee Hours Worked: ";
		do
		{
			while (!(cin >> empHoursWorked[i])) //Check input type
			{
				cout << "Invalid Hours entered. Please enter a number: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cin.ignore();
			if (empHoursWorked[i] < 0) //Validate input
			{
				cout << "Invalid Hours Entered. Please enter a positive number: ";
			}
			else
			{
				break;
			}
		} while (empHoursWorked[i] < 0);

		//Gather Employee Hourly Rates
		cout << "Please enter Employee Pay per Hour: $";
		do
		{
			while (!(cin >> empHourlyRate[i])) //Check input type
			{
				cout << "Invalid Pay Rate Entered. Please enter a number: $";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cin.ignore();
			if (empHoursWorked[i] < 0) //Validate input
			{
				cout << "Invalid Pay Rate Entered. Please enter a positive number: $";
			}
			else
			{
				break;
			}
		} while (empHourlyRate[i] < 0);

		Employees += 1;

		char cont; // Sentinel input to determine if another employee is desired
		cout << "Would you like to enter another employee? [Y] or [N]: ";
		cin >> cont;
		if (tolower(cont) == 'n')
		{
			cout << endl;
			break;
		}
		else
		{
			cout << endl;
		}
	}

	return Employees;
}

void computeWeeklySalary(int empHoursWorked[], double empHourlyRate[], double empWeeklySalary[], int empCount) //Currently calculates without tax in mind
{
	for (int i = 0; i < empCount; i++)
	{
		double GrossSal;

		if (empHoursWorked[i] <= 40) //If Hours are 40 or below (no raise)
		{
			GrossSal = (empHoursWorked[i] * empHourlyRate[i]);
		}
		else //If Hours are above 40
		{
			int HoursExtra; //Seperate hours above 40
			HoursExtra = (empHoursWorked[i] - 40);
			double RaiseRate; //Make var for extra 50% rate 
			RaiseRate = (1.5 * empHourlyRate[i]);

			GrossSal = (40 * empHourlyRate[i]);
			GrossSal += (HoursExtra * RaiseRate);
		}

		empWeeklySalary[i] = GrossSal;
	}
}

double computeAverageSalary(const double EmpWeeklySalary[], int EmpCount)
{
	double TotalSal = 0;
	double Averaged; //The total salary count divided by the amount of Employees
	for (int i = 0; i < EmpCount; i++)
	{
		TotalSal += EmpWeeklySalary[i];
	}
	Averaged = (TotalSal / EmpCount);

	return Averaged;
}

void printTable(const string EmpNames[], int EmpHoursWorked[], double EmpHourlyRate[], double EmpWeeklySalary[], int EmployeeAmount, double AverageSal)
{
	cout << fixed;
	cout << setprecision(2);

	cout << "DEBUG This is the Current fucking project";
	cout << "Name" << setw(20 + 12 - 4) << "Hours Worked" << setw(20 + 15 - 12) << "Hourly Rate ($)" << setw(20 + 17 - 15) << "Weekly Salary ($)" << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;

	//Iteration [DEBUG Will Not Yet Have Salary Comps involved]
	for (int i = 0; i < EmployeeAmount; i++)
	{
		int Namelnth = EmpNames[i].length();
		int Hourslnth = to_string(EmpHoursWorked[i]).length();
		int Ratelnth = to_string(EmpHourlyRate[i]).length();
		int Salarylnth = to_string(EmpHourlyRate[i]).length();

		cout << EmpNames[i] << setw(20 + Hourslnth - Namelnth) << EmpHoursWorked[i] << setw(40 + Ratelnth - Hourslnth) << EmpHourlyRate[i] << setw(20 + Salarylnth - Ratelnth) << EmpWeeklySalary[i] << endl;
		cout << "--------------------------------------------------------------------------------------------------------------" << endl;

	}

	cout << "Average Weekly Salary: $" << AverageSal << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}
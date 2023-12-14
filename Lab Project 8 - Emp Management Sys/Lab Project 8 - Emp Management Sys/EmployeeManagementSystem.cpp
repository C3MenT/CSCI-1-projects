/// Lab Project 8 - Employee Management System Using Struct and Struct Array
/// By Ri'chard McCray
/// CSCI-1-0101
/// Submitted 6/7/23
/// Windows 10
/// Visual Studio 2019
/// Successfully Ran 7:57 PM 6/6/23

//Includes
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Constants
const int MAX_EMP = 10; //Max Constant for amount of handled employees

//Structs
struct Employee {
	string name; //Employee Name
	int hoursWorked; //Emp Hours Worked
	double hourlyRate; //Emp Pay per Hour
	double weeklySalary; //Emp Weekly Salary
};

//Func Prototypes
int fillEmployeeArray(Employee Employees[]);
void computeWeeklySalary(Employee Employees[], int employeesEntered); // void as returns to structures
double computeAverageSalary(const Employee Employees[], int employeesEntered);
void printTable(const Employee Employees[], int employeesEntered);

//True init
int main()
{
	cout << fixed << setprecision(2);

	int EmployeesEntered; //The amount of Employees data was entered for
	double AverageSalary; //The average Salary of all Employees
	Employee EmployeeList[MAX_EMP]; //List of Employee Struct objs

	EmployeesEntered = fillEmployeeArray(EmployeeList);
	computeWeeklySalary(EmployeeList, EmployeesEntered);
	printTable(EmployeeList, EmployeesEntered);
	computeAverageSalary(EmployeeList, EmployeesEntered);
}

int fillEmployeeArray(Employee Employees[])
{
	int sentinel = 0; //Continue Sentinel or Consent char to continue
	int index = 0; //Index for quality of life
	do
	{
		cout << "Employee #" << (index + 1) << endl;
		//Name
		cout << "Name: ";
		cin >> Employees[index].name; //Enter into the name slot of the the Emp struct at index of list
		cin.ignore();

		//Hours Worked
		int hoursTemp = 0; //Temp var for hours worked
		do
		{
			cout << "Hours Worked: ";
			while (!(cin >> hoursTemp)) //Validate number data
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Hours Worked is invalid please enter a number: " << endl;
			}
			if (hoursTemp < 0) //Check positive
			{
				cout << "Hours Worked is invalid please enter a positive number :" << endl;
			}
			else //Everything checks out
			{
				Employees[index].hoursWorked = hoursTemp;
				break;
			}
		} while (hoursTemp < 0);
		cin.ignore();

		//Hourly Rate
		double rateTemp = 0; //Temp var for hours worked
		do
		{
			cout << "Hourly Rate: ";
			while (!(cin >> rateTemp)) //Validate number data
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Hourly Rate is invalid please enter a number: " << endl;
			}
			if (rateTemp < 0) //Check positive
			{
				cout << "Hourly Rate is invalid please enter a positive number :" << endl;
			}
			else //Everything checks out
			{
				Employees[index].hourlyRate = rateTemp;
				break;
			}
		} while (rateTemp < 0);
		cin.ignore();

		index++;

		cout << "More Data? Enter 0 to Continue or 1 to stop: ";
		cin >> sentinel;
		cout << endl;

	} while (sentinel != 1);

	return index; //This index counts up so it can record the amount of employees entered
}

void computeWeeklySalary(Employee Employees[], int employeesEntered)
{
	double tempSalary;
	int ExtraHours = 0;
    double ExtraRate = 0.0;

	for (int i = 0; i < employeesEntered; i++)
	{
		if (Employees[i].hoursWorked > 40)
		{
			ExtraHours = (Employees[i].hoursWorked - 40);
            ExtraRate = (1.5 * Employees[i].hourlyRate);

			tempSalary = (Employees[i].hourlyRate * 40);
			tempSalary += (ExtraHours * ExtraRate);

		}
		else
		{
			tempSalary = (Employees[i].hoursWorked * Employees[i].hourlyRate);
		}
        Employees[i].weeklySalary = tempSalary;
	}
}

double computeAverageSalary(const Employee Employees[], int employeesEntered)
{
	double AverageSalLocal;
	double TotalSalLocal = 0;

	for (int i = 0; i < employeesEntered; i++)
	{
		TotalSalLocal += Employees[i].weeklySalary;
	}

	AverageSalLocal = (TotalSalLocal / employeesEntered);

	cout << "Average Weekly Salary: $" << AverageSalLocal;

	return AverageSalLocal; //because at least two func have to return
}

void printTable(const Employee Employees[], int employeesEntered)
{
	string nameTemp;
	int hoursTemp;
	double rateTemp;
	double salaryTemp;

	int NameLth;
	int HourLth;
	int RateLth;
	int SalaryLth;

	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Name" << setw(30 - 4 + 13) << "Hours Worked" << setw(30 - 13 + 16) << "Hourly Rate ($)" << setw(30 - 12 + 18) << "Weekly Salary ($)" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < employeesEntered; i++)
	{
		//Assign
		nameTemp = Employees[i].name;
		hoursTemp = Employees[i].hoursWorked;
		rateTemp = Employees[i].hourlyRate;
		salaryTemp = Employees[i].weeklySalary;

		//Measure
		NameLth = nameTemp.length();
		HourLth = to_string(hoursTemp).length();
		RateLth = to_string(rateTemp).length();
		SalaryLth = to_string(salaryTemp).length();

		//Print
		cout << nameTemp << setw(30 - NameLth + HourLth);
		cout << hoursTemp << setw(30 - HourLth + RateLth);
		cout << rateTemp << setw(30 - RateLth + SalaryLth);
		cout << salaryTemp << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

	}
}
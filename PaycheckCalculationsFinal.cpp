#include <iostream>
#include <cmath>
#include <typeinfo>
#include <sstream>
using namespace std;

/// Lab Activity 4: Company Paycheck Calculations (no functions)
/// by Ri'chard McCray CSCI-1-0101

int main()
{
	for (int t = 0; t < 25; t++)
	{
		cout << "Iteration: " << t << endl;//deubg

		string first; //first name
		string last; //last name
		char em_code; //Employee Code (important)
		int ID; //Employee ID
		int level; //Job Classification (important) 
		int years; //Years Serving the Company (important)
		int education; //Level of Education (important)

		double base_pay;

		//Real Init
		//start with irrelevant info
		cout << "Please enter Employee first name: " << endl;
		cin >> first;
		cin.ignore();

		cout << "Please enter Employee last name: " << endl;
		cin >> last;
		cin.ignore();
		
		//Employee Code
		cout << "Please enter Employee code: " << endl; 
		do 
		{
			cin >> em_code;
			cin.ignore();
			cout << "[DEBUG] em code: " << em_code << endl;
			if (em_code != 'S' && em_code != 'O' && em_code != 'M')
			{
				cout << "Employee code entered is invalid." << endl;
				cout << "Please enter valid employee code (S, O, or M): " << endl;
			}
		} while (em_code != 'S' && em_code != 'O' && em_code != 'M');

		//Employee ID Number 
		cout << "Please enter Employee ID: " << endl; 
		while(true) //Need arbitrary base loop to support advanced cin checks
			{
		 	cin >> ID;
			cin.ignore();
			cout << "[DEBUG] ID No.: " << ID << endl;

			if (!cin) //if the buffer fails (due to not int inputted)
			{
		 		cout << "Employee ID is invalid." << endl;
				cout << "ID must be a number: " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else //input succeeded so must be number. Good.
			{
				break;
			}
		}

		//Job Classification
		cout << "Please enter the Employee Job Classification: " << endl; 
		do
		{	
			cin >> level;
			cin.ignore();
			cout << "[DEBUG] level: " << level << endl;
			if (level < 1 || level > 3)
			{
				cout << "Job classification level is invalid." << endl;
				cout << "Please enter valid employee job classification (1-3): " << endl;
			}
		} while (level < 1 || level > 3);
		
		//Years of service
		cout << "Please enter the years the employee has worked for: " << endl; 
		do
		{
			cin >> years;
			cin.ignore();
			cout << "[DEBUG] Years: " << years <<endl;
			if (years < 0 || years > 10)
			{
				cout << "Years of service entered is an invalid number." << endl;
				cout << "Please enter valid Employee years of service (0-10): " << endl;
			}
		} while (years < 0 || years > 10);

		//Education Level
		cout << "Please enter the Employee's level of education: " << endl; 
		do
		{
			cin >> education;
			cin.ignore();
			cout << "[DEBUG] Education: " << education <<endl;
			if (education < 1 || education > 4)
			{
				cout << "Education level is an invalid number." << endl;
				cout << "Please enter valid level of education (1-4): " << endl;
			}
		} while (education < 1 || education > 4);

		//Now to do math
		
		
	}
}
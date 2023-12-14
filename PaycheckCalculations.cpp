#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

/// Lab Activity 4: Company Paycheck Calculations (with functions)
/// by Ri'chard McCray CSCI-1-0101

//Declare Global Variables
string first; //first name
string last; //last name
char em_code; //Employee Code (important)
string em_code_full; //Full Employee code to be set after char code
int ID; //Employee ID
int level; //Job Classification (important) 
int years; //Years Serving the Company (important)
int education; //Level of Education (important)

double base_pay;

void Employee_Code()
{
	//Employee Code
	cout << "Please enter Employee code: " << endl;
	cout << "S = Factory Worker, O = Office Worker, and M = Management" << endl;
	do
	{
		cin >> em_code;
		cin.ignore();
		switch (em_code)
		{
		case 'S':
			base_pay = 800.95;
			em_code_full = "Factory Worker";
			break;
		case 'O':
			base_pay = 1000.86;
			em_code_full = "Office Worker";
			break;
		case 'M':
			base_pay = 1499.89;
			em_code_full = "Management";
			break;
		default:
			cout << "Employee code entered is invalid." << endl;
			cout << "Please enter valid employee code (S, O, or M): " << endl;
		}
	} while (em_code != 'S' && em_code != 'O' && em_code != 'M');
	cout << "[DEBUG] base_pay: $" << base_pay << endl;
}

void Employee_ID()
{
	//Employee ID Number 
	cout << "Please enter Employee ID: " << endl;
	while (true) //Need arbitrary base loop to support advanced cin checks
	{
		cin >> ID;
		cin.ignore();
		//cout << "[DEBUG] ID No.: " << ID << endl;

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
}

double Job_Classification()
{
	//Job Classification
	double bonus_pay; //bonus pay local var each "additional factor func will use"
	bonus_pay = 0.0;

	cout << "Please enter the Employee Job Classification (1-3): " << endl;
	do
	{
		cin >> level;
		cin.ignore();
		//cout << "[DEBUG] level: " << level << endl;
		switch (level)
		{
		case 1: // 5% of base pay
			bonus_pay = (base_pay * (double(5) / 100));
			break;
		case 2: // 10% of base pay
			bonus_pay = (base_pay * (double(10) / 100));
			break;
		case 3: // 20% of base pay
			bonus_pay = (base_pay * (double(20) / 100));
			break;
		default:
			cout << "Job classification level is invalid." << endl;
			cout << "Please enter valid employee job classification (1-3): " << endl;
		}
	} while (level < 1 || level > 3);
	return bonus_pay;
}

double Years_of_Service()
{
	//Years of service
	double bonus_pay;
	bonus_pay = 0;

	cout << "Please enter the years the employee has worked for (1-50): " << endl;
	do
	{
		cin >> years;
		cin.ignore();
		//cout << "[DEBUG] Years: " << years <<endl;

		if (years > 0 && years <= 10)
		{
			bonus_pay = (base_pay * (double(5) / 100));
		}
		else if (years > 10 && years <= 50)
		{
			bonus_pay = (base_pay * (double(5) / 100));
			bonus_pay += (base_pay * (double(years - 10) / 100));
		}
		else
		{
			cout << "Years of service entered is an invalid number." << endl;
			cout << "Please enter valid Employee years of service (0-10): " << endl;
		}

	} while (years < 0 || years > 50);
	return bonus_pay;
}

double Education_Level()
{
	//Education Level
	double bonus_pay;
	bonus_pay = 0;

	cout << "Please enter the Employee's level of education (1-4): " << endl;
	cout << "1-High School, 2-Junior College, 3-University, 4-Graducate School" << endl;
	
	do
	{
		cin >> education;
	 	cin.ignore();

		switch (education)
		{
		case 1:
			break;// no bonus for highschool Ed; already init as 0
		case 2:
			bonus_pay = (base_pay * (double(5)/100));
			break;
		case 3:
			bonus_pay = (base_pay * (double(12)/100));
			break;
		case 4:
			bonus_pay = (base_pay * (double(20)/100));
			break;
		default:
			cout << "Education level is an invalid number." << endl;
	 		cout << "Please enter valid level of education (1-4): " << endl;
		}
	} while (education < 1 || education > 4);
	
	return bonus_pay;
}
void display_result()
{
	cout << first << " " << last;
	cout << setw(14); //May need to find length of ID for consistancy
	cout << ID;
	cout << setw(em_code_full.length() + 10);
	
}

int main()
{

	for (int t = 0; t < 25; t++)
	{
		cout << "Iteration: " << t << endl;//deubg

		//Real Init
		//start with irrelevant info
		cout << "Please enter Employee first name: " << endl;
		cin >> first;
		cin.ignore();

		cout << "Please enter Employee last name: " << endl;
		cin >> last;
		cin.ignore();

		Employee_Code();
		Employee_ID();
		
		double JCB;//Job Class Bonus
		double YSB;//Years of Service Bonus
		double ELB;//Education Level Bonus

		JCB = Job_Classification();
		cout << "[DEBUG] Job Class Bonus: $" << (JCB) << endl;
		YSB = Years_of_Service();
		cout << "[DEBUG] Years of Service Bonus: $" << (YSB) << endl;
		ELB = Education_Level();
		cout << "[DEBUG] Education Level Bonus: $" << (ELB) << endl;

		//Now to do math
		double salary_r; //raw salary
		int salary_sec; //affected salary
		double salary; //final salary

		salary_r = (base_pay + JCB + YSB + ELB);
		cout << "[DEBUG] Salary init: $" << salary_r << endl;

		salary_r *= 100;
		cout << "[DEBUG] Salary_r first: $" << salary_r << endl;
		salary_r += 0.5;
		cout << "[DEBUG] Salary_r rounded: $" << salary_r << endl;
		salary_sec = static_cast<int>(salary_r);
		cout << "[DEBUG] Salary_sec: $" << salary_sec << endl;
		salary = (salary_sec / double(100));

		cout << "[DEBUG] Salary: $" << salary << endl;
	}
}
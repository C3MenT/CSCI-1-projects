//Lab Project 5 - Bulk Ticket Price Calculations
//By Ri'chard McCray
//CSCI-1-0101
//

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

const double FC_SUR = 50.00; //first class surcharge
const double SC_SUR = 20.00; //second class surcharge
const double CPM = 0.30; //cost per mile for all class
const int mile_minimum = 50; //minimum miles that can be traveled

//Discounts 
const double Dis1 = 0.031; //3.1%
const double Dis2 = 0.082; //8.2%
const double Dis3 = 0.131; //13.1%
const double Dis4 = 0.152; //15.2%

ostringstream output;//For appendeing to before couts

//standard prototypes//
int FC_Gather(); //Gather tickets for FC
int SC_Gather(); //Gather tickets for SC
int TC_Gather(); //Gather tickets for TC

//Calculate and display costs specific to classes 
double FC_Calc(int); //These are doubles as they should return total costs
double SC_Calc(int);
double TC_Calc(int);

int main()
	{
		cout << fixed;
		cout << setprecision(2);

		string final_output; //What will store the stringstream in the end

		do ////Main Loop////
		{
			int tickets; //number of tickets purchased
			int tickets_1st; //first class tickets purchased
			int tickets_2nd; //second class tickets purchased
			int tickets_3rd; //third class tickets purchased

			double dist_1st;
			double dist_2nd;
			double dist_3rd;

			double raw_first; //Raw cost for first class tickets
			double raw_second; //Raw cost for second class tickets
			double raw_third; //Raw cost for third class tickets
			
			double curr_discount; //the discounted amount removed
			double raw_total;
			double discounted_total;

			//CSCI-1 necessary seperate re-inits for iterations
			tickets_1st = 0;
			tickets_2nd = 0;
			tickets_3rd = 0;

			dist_1st = 0; 
			dist_2nd = 0;
			dist_3rd = 0;

			raw_first = 0;
			raw_second = 0;
			raw_third = 0;

			////Start Func////
			tickets_1st = FC_Gather();
			tickets_2nd = SC_Gather();
			tickets_3rd = TC_Gather();

			raw_first = FC_Calc(tickets_1st);
			raw_second = SC_Calc(tickets_2nd);
			raw_third = TC_Calc(tickets_3rd);

			//Find Discount//
			raw_total = raw_first + raw_second + raw_third;
			if (raw_total >= 1200)
			{
				curr_discount = (raw_total * Dis4);
			}
			else if (raw_total >= 800)
			{
				curr_discount = (raw_total * Dis3);
			}
			else if (raw_total >= 500)
			{
				curr_discount = (raw_total * Dis2);
			}
			else if (raw_total >= 100)
			{
				curr_discount = (raw_total * Dis1);
			}
			else
			{
				curr_discount = 0;
			}

			discounted_total = (raw_total - curr_discount);
			////OUTPUT////
			final_output = output.str();
			cout << final_output;
			cout << "Cost of all tickets before discount: $" << raw_total << endl;
			cout << "Discount applied: $" << curr_discount << endl;
			cout << "Please Pay: $" << discounted_total << endl;

		} while (!cin.peek());// for Debug force-out combination
	return 0;
	} 

int FC_Gather()
{
	int tickets; //local ticket holder
	char Res = ' ';
	do //Make sure user chooses to buy or not 
	{
		cout << "Would you like to buy one or more First Class Tickets?" << endl
			<< "[Y]es or [N]o: " << endl;
		cin >> Res;
		cin.ignore();

		if (tolower(Res) == 'n')
		{
			break;
		}
		else if (!cin)
		{
			cout << "Invalid answer; enter Y or N: " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else //Technically progresses if anything other than n is entered
		{
			do //Make sure that User enters proper int
			{
				cout << "Enter # of First Class Tickets to purchase: " << endl
 					<< "Number of tickets must be at least 1" << endl;
				cin >> tickets;
				cin.ignore();
				if (!cin) //Input Breaks
				{
					cout << "Invalid selection; please enter a whole number: " << endl;
					cin.clear();
					cin.ignore();
				}
				else if (tickets < 1)
				{
					cout << "Invalid selection; please enter number greater than 0: " << endl;
				}
				else
				{
					cout << "[DEBUG] tickets = " << tickets << endl;
					break;
				}
			} while (!cin || tickets < 1);
		}
	} while (!cin);
	return tickets;
}
int SC_Gather()
{
	int tickets; //local ticket holder
	char Res = ' ';
	do //Make sure user chooses to buy or not 
	{
		cout << "Would you like to buy one or more Second Class Tickets?" << endl
			<< "[Y]es or [N]o: " << endl;
		cin >> Res;
		cin.ignore();

		if (tolower(Res) == 'n')
		{
			break;
		}
		else if (!cin)
		{
			cout << "Invalid answer; enter Y or N: " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else //Technically progresses if anything other than n is entered
		{
			do //Make sure that User enters proper int
			{
				cout << "Enter # of Second Class Tickets to purchase: " << endl
 					<< "Number of tickets must be at least 1" << endl;
				cin >> tickets;
				cin.ignore();
				if (!cin) //Input Breaks
				{
					cout << "Invalid selection; please enter a whole number: " << endl;
					cin.clear();
					cin.ignore();
					
				}
				else if (tickets < 1)
				{
					cout << "Invalid selection; please enter number greater than 0: " << endl;
				}
				else
				{
					cout << "[DEBUG] tickets = " << tickets << endl;
					break;
				}
			} while (!cin || tickets < 1);
		}
	} while (!cin);
	return tickets;
}
int TC_Gather()
{
	int tickets; //local ticket holder
	char Res = ' ';
	do //Make sure user chooses to buy or not 
	{
		cout << "Would you like to buy one or more Third Class Tickets?" << endl
			<< "[Y]es or [N]o: " << endl;
		cin >> Res;
		cin.ignore();

		if (tolower(Res) == 'n')
		{
			break;
		}
		else if (!cin)
		{
			cout << "Invalid answer; enter Y or N: " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else //Technically progresses if anything other than n is entered
		{
			do //Make sure that User enters proper int
			{
				cout << "Enter # of Third Class Tickets to purchase: " << endl
 					<< "Number of tickets must be at least 1" << endl;
				cin >> tickets;
				cin.ignore();
				if (!cin) //Input Breaks
				{
					cout << "Invalid selection; please enter a whole number: " << endl;
					cin.clear();
					cin.ignore();
					
				}
				else if (tickets < 1)
				{
					cout << "Invalid selection; please enter number greater than 0: " << endl;
				}
				else
				{
					cout << "[DEBUG] tickets = " << tickets << endl;
					break;
				}
			} while (!cin || tickets < 1);
		}
	} while (!cin);
	return tickets;
}

double FC_Calc(const int tickets)
{
	double cost_temp; //local cost holder for calculating
	cost_temp = 0;
	double cost_total;//Total cost to be returned
	cost_total = 0;
	double distance; //local dist for calc

	//Prep this class' section of the output stream
	output << "=======================================================" << endl;
	output << "Here are details of all first class tickets" << endl;
 	output << "Number of first class tickets: " << tickets << endl;
	output << "............................................................." << endl;
	output << "Ticket Number" << setw(25-13) << "Distance" << setw(25-8) << "Price" << endl;
	output << "...................................................." << endl;

	cout << "We will ask details of first class tickets:" << endl;
	for (int i = 1; i < (tickets + 1); i++) //Loop will iterate and add as necessary
	{
		cost_temp = 0;
		
		cout << "Enter distance to be travelled on Ticket (" << i << ") You must enter a value 50 miles or higher:" << endl;
		do
		{
			while (!(cin >> distance))
			{
				cout << "Invalid Distance, please enter a number. " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			if (distance < 50)
			{
				cout << "Distance is Less than 50 miles, please enter a larger distance: " << endl;
			}
			else
			{
				cost_temp = ((distance * 0.30) + FC_SUR);
				cost_total += cost_temp;
				output << i << setw(10 + ((to_string(distance)).length())) << distance << setw((18 - ((to_string(distance)).length())) + (to_string(cost_temp).length()))<< "$" << cost_temp << endl; //
				output << "...................................................." << endl;
				
			}
		} while (distance < 50);
	}
	output << "Total cost of all first class tickets: $" << cost_total << endl;
	return cost_total;
}
double SC_Calc(const int tickets)
{
	double cost_temp; //local cost holder for calculating
	cost_temp = 0;
	double cost_total;//Total cost to be returned
	cost_total = 0;
	double distance; //local dist for calc

	//Prep this class' section of the output stream
	output << "=======================================================" << endl;
	output << "Here are details of all second class tickets" << endl;
 	output << "Number of second class tickets: " << tickets << endl;
	output << "............................................................." << endl;
	output << "Ticket Number" << setw(25-13) << "Distance" << setw(25-8) << "Price" << endl;
	output << "...................................................." << endl;

	cout << "We will ask details of second class tickets:" << endl;
	for (int i = 1; i < (tickets + 1); i++) //Loop will iterate and add as necessary
	{
		cost_temp = 0;
		
		cout << "Enter distance to be travelled on Ticket (" << i << ") You must enter a value 50 miles or higher:" << endl;
		do
		{
			while (!(cin >> distance))
			{
				cout << "Invalid Distance, please enter a number. " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			if (distance < 50)
			{
				cout << "Distance is Less than 50 miles, please enter a larger distance: " << endl;
			}
			else
			{
				cost_temp = ((distance * 0.30) + SC_SUR);
				cost_total += cost_temp;
				output << i << setw(10 + ((to_string(distance)).length())) << distance << setw((18 - ((to_string(distance)).length())) + (to_string(cost_temp).length()))<< "$" << cost_temp << endl; //
				output << "...................................................." << endl;
				
			}
		} while (distance < 50);
	}
	output << "Total cost of all second class tickets: $" << cost_total << endl;
	return cost_total;
}
double TC_Calc(const int tickets)
{
	double cost_temp; //local cost holder for calculating
	cost_temp = 0;
	double cost_total;//Total cost to be returned
	cost_total = 0;
	double distance; //local dist for calc

	//Prep this class' section of the output stream
	output << "=======================================================" << endl;
	output << "Here are details of all third class tickets" << endl;
 	output << "Number of third class tickets: " << tickets << endl;
	output << "............................................................." << endl;
	output << "Ticket Number" << setw(25-13) << "Distance" << setw(25-8) << "Price" << endl;
	output << "...................................................." << endl;

	cout << "We will ask details of third class tickets:" << endl;
	for (int i = 1; i < (tickets + 1); i++) //Loop will iterate and add as necessary
	{
		cost_temp = 0;
		
		cout << "Enter distance to be travelled on Ticket (" << i << ") You must enter a value 50 miles or higher:" << endl;
		do
		{
			while (!(cin >> distance))
			{
				cout << "Invalid Distance, please enter a number. " << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			if (distance < 50)
			{
				cout << "Distance is Less than 50 miles, please enter a larger distance: " << endl;
			}
			else
			{
				cost_temp = (distance * 0.30);
				cost_total += cost_temp;
				output << i << setw(10 + ((to_string(distance)).length())) << distance << setw((18 - ((to_string(distance)).length())) + (to_string(cost_temp).length()))<< "$" << cost_temp << endl; //
				output << "...................................................." << endl;
			}
		} while (distance < 50);
	}
	output << "Total cost of all third class tickets: $" << cost_total << endl;
	return cost_total;
}
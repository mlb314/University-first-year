#include <iostream>
#include <iomanip>
using namespace std;


//Write a program that asks the user to enter their monthly costs for each of the following:

//Rent or mortgage
//	Internet
//	Gas
//Electricity
//Water

//The program should then display the total monthly cost of those expenses
//and the total annual cost of these expenses.





int main()
{
	long double rent, internet, gas, electric, water;

	cin >> rent >> internet >> gas  >> electric >> water;

	cout << fixed << setprecision(2);
	cout << "Here is your cost breakdown" << endl;
	cout << "Monthly Rent: $" << rent << endl;
	cout << "Yearly Rent: $" << rent * 12 << endl;//rent x12 for the yearly rent
	cout << "Monthly Internet: $" << internet << endl;
	cout << "Yearly Internet: $" << internet * 12 << endl;//internet x12 for the yearly internet bill
	cout << "Monthly Gas: $" << gas << endl;
	cout << "Yearly Gas: $" << gas * 12 << endl;//gas x12 for the yearly gas bill
	cout << "Monthly Electricity: $" << electric << endl;
	cout << "Yearly Electricity: $" << electric * 12 << endl;//electric x12 for the yearly electric bill
	cout << "Monthly Water: $" << water << endl;
	cout << "Yearly Water: $" << water * 12 << endl;//water x12 for the yearly water bill

	//this just displays all the given variable for the given time frames. yearly cost = monthly * 12
}
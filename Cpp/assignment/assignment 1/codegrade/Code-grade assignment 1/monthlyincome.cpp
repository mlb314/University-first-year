#include <iostream>
using namespace std;

int main()
{
	double total, basic, medical, bonus; //initialising variables 
	basic = 5000;
	medical = 0.125;
	bonus = 0.55;

	//calculating the given special variables
	medical = medical * basic;
	bonus = bonus * basic;
	total = basic + medical + bonus;

	cout << "Basic Pay is $" << basic << "\n";
	cout << "Bonus is $" << bonus << "\n";
	cout << "Medical Allowance is $" << medical << "\n";
	cout << "Total is $" << total << "\n";

}
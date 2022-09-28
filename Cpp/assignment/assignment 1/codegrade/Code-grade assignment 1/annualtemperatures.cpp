#include <iostream>
using namespace std;
//The average July high temperate is 85 degrees Fahrenheit in New York City, 88 degrees in Denver and 106 degrees in Phoenix.
//Write a program that calculates and reports what the new average high July temperature would be for each of these cities 
//if the temperatures were to rise by 2 percent.
int main()
{

//initialising variables 
	double NYC = 85;
	double denv = 88;
	double phoenix = 106;
	double rise = 1.15;
	
	//	NY average is 85
	//	Denver average is 88
	//	Pheonix average is 106
	//	If the averages temp rose by 15 %
	//	NY average would be 97.75
	//	Denver average would be 101.2
	//	Pheonix average would be 121.9//


	cout << "NY average is " << NYC<<"\n";
	cout << "Denver average is " << denv << "\n";
	cout << "Pheonix average is " << phoenix << "\n";
	cout << "If the averages temp rose by 15%\n";

	//calculating the given special variables
	NYC = NYC * rise;
	denv = denv * rise;
	phoenix = phoenix * rise;
	
	cout << "NY average would be " << NYC << "\n";
	cout << "Denver average would be " << denv << "\n";
	cout << "Pheonix average would be " << phoenix << "\n";

}
#include <iostream>
#include <iomanip>
using namespace std;
//question:The height of a person is stored in Feet and inches,
//write a program that will take their height in feet and inches, and convert it to meters. An inch is 25.4mm
int main()
{

//initialising variables 
	int feet = 0;
	int inch = 0;
	float meters=0.0;

	cin >> feet;
	cin>> inch;

	//calculating the given special variables
	meters = (((feet * 12) + inch)*25.4)/1000;

	cout << "Height in feet and inches is "<<feet<<"ft, " << inch << "in\n";
	cout<< fixed << setprecision(2) <<"Height in meters is "<< meters<<"m\n";

}
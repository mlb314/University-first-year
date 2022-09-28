
/*Weight Conversion Table

The conversion factors for converting between imperial tonsand poundsand kilograms are :
1 imperial ton = 2240 pounds
1 imperial ton = 1016.05 kilograms
Write two functions toPounds and toKiologram, 
each of which accepts a weight in imperial tons as an argument and return the weight in pounds and kilograms respectively.
Write a program that calls the functions in a loop to generate a table of conversions from tons to pounds and kilograms,
from 2 tons till 20 tons, in increments of 2 tons.
*/

#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int ton = 2;//ton global variable, since its used through out all the code

void  toPounds() 
{
	double pound;//local varialbe for this function
	//1 imperial ton = 2240 pounds
	pound = ton * 2240;//converted from ton to pounds
	cout << pound;

}


void toKilogram() 
{
	double kilo;//local variable
	//1 imperial ton = 1016.05 kilograms
	kilo = ton * 1016.05;//converted from ton to kilograms
	cout << kilo;

}

int main() 
{

	cout << "|--------------------------------| \n|tons      |pounds    |kilograms |\n|--------------------------------| \n";
		while (ton <= 20 && ton >= 0)//list and makes sure that ton is between 2 and 20 aswell as being divisable by 2
		{
		
			if (ton % 2 == 0)
			{
			
				cout <<"|" << setw(10) << left << ton << "|";
				cout << setw(10)<<left;
				toPounds();
				cout << "|";
				cout << setw(10) << left;
				toKilogram();
				cout << "|\n";
			}
			ton++;
		}
	cout << "|--------------------------------| ";
}





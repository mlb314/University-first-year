#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//question:
	//A particular brand of paint covers 340 square feet per gallon. Write a program to determine and report approximately 
	//how many gallons of paint will be needed to pain two coats on a wooden fence that is 6 feet high and 100 feet long.
	int sqrfeet = 0;
	int tin = 0;
	int height=6;
	int length=100;
	//paint, 1 gallon = 340sqr feet.
	//total area = 6*100= 600sqr feet
	sqrfeet = length * height;
	tin = (sqrfeet / 340)+1;
	
	//calculating the amount of squar feet and how many tins are required, +1 to the tin as since they're integers they only deal with whole numbers and i can add it to the total in the tins.
	cout << "For your fence which is " << sqrfeet << "sqft you will need " << tin << " tins of paint";
	// and this is the end of the code :D
	
}
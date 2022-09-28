#include <iostream>
using namespace std;


int main()
{
	//The population of the world is 7.7 billion (7700000000) Write a program to display what the population is if it increases by 10%, 15% and 20%
	
	long int population = 7700000000;
	long int temp1 = 7700000000;

	cout << "The world population is "<<population<<"\n";
	population = temp1 * 1.1;
	cout <<"if the world population rose by 10% it would be "<< population<<" \n";

	population = temp1 * 1.15;
	cout <<"if the world population rose by 15% it would be "<< population << "\n";

	population = temp1 * 1.2;
	cout <<"if the world population rose by 20% it would be "<< population<<"\n";
}
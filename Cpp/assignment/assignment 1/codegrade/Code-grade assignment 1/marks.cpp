#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//initialising variables
	int score1, score2, score3;
	float avg;
	//put responses into the correct variables.

	cin >> score1;
	cin >>score2;
	cin>> score3;

	
	avg = (score1 + score2 + score3) / 3;
	//simple calculations for the average
	cout << "Average mark is " << fixed << setprecision(2) << avg<<"%" << endl;
	//setprecision is for 2 decimal places, as well as the output being placed in the correct location, i hope anyways.


}


//A school holds three terminal examinations every year. Write a program that
//asks the user to enter the percentage of marks they obtained in each terminal examination in a year,
//and then displays their average percentage for the year, correct to two decimal places.
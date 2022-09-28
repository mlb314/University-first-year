#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
	//initialing the variables
	int Kburg,Hburg,Cheeseburg,CandBburg;
	double total;
	cin >> Kburg>>Hburg>>Cheeseburg>>CandBburg;
	
	total = (2.50 * Kburg) + (3.50 * Hburg) + (4.20 * Cheeseburg) + (5.00 * CandBburg);
	//the calculations of the total
	cout << fixed << setprecision(2) << "Total sales for the day $" << total;
	//set precision for the legnth of the double
}

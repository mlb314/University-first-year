#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	float a, b, c;//initialising variables
	double s,area;//s is used for the later equations
	cin >> a >> b >> c;
	if ((a + b > c) && (a + c > b) && (b + c > a))// this statement makes sure that any 2 given sides are always greater than the remaining side
	{
		cout << "Triangle is valid" << endl;
		

		s = (a + b + c) / 2;
		area =sqrt(s * (s - a) * (s - b) * (s - c));// this calculates the area of the triangle, given that a,b and c all have appropriate values.
		cout << fixed << setprecision(2);// this sets all the values to 2 decimal places.
		cout << "area is " << area << endl;


	}
	else
	{
		cout << "This is not a valid triangle";
	}

}
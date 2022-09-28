
/*Create a class name IsoscelesTriangle that has two data members to store the length of the base, and the height of the triangle.
It should have member functions to return the area and perimeter of the triangle, where area is half the product of the base and the height.
The perimeter is:
*/

#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

class IsoscelesTriangle //creating the class IsoscelesTriangle 
{
private: //declaring the variables to be used throughout the code
	double height;
	double base;
	double area;
	double perimeter;




public:

	IsoscelesTriangle(double a, double b, double h, double p)
	{
		area = a;
		base = b;
		perimeter = p;
		height = h;
	}

	void getDimensions()//this function gets both the base and height of the triangle
	{
		cout << "What is the base of the triangle?";
		cin >> base;
		cout << "What is the height of the triangle?";
		cin >> height;
	}

	void Perimeter()//this function calculates the perimeter of the triangle
	{
		perimeter = base + sqrt((base * base) + (4 * height * height));
		cout << "Perimeter " << perimeter << "\n";

	}

	void  Area()//this function calculates the area of the triangle
	{
		area = 0.5 * (base * height);
		cout << "Area " << area << "\n";
	}
};



int main()
{
	IsoscelesTriangle isosceles(0, 0, 0, 0); //creating the object
	isosceles.getDimensions();//calling the function
	isosceles.Area();//calling the function
	isosceles.Perimeter();//calling the function

	return 0;

}





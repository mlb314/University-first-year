
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
//little endien and decimal to binary conversion


int main()
{
	int number;
	int i=0;
	string binary;
	string temp;

	cout << "What is the decimal number?";
	cin >> number;

	while (i <= 12)
	{
		number = number - (2 ^ (12 - i));
		temp = binary;
		if (number < 0) {
			
			binary ="0"+temp;
		}
		else {
			binary = "1"+temp ;
		}
		i--;
	}
	cout << binary;

}
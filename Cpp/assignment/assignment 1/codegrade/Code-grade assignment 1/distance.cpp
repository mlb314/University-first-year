#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() 

{
	int hour,speed_mph,distance;//initialising variables
	int i=1;
	cin >> speed_mph>> hour ;
	
	
	cout <<"Hour  Miles Travelled"<<endl;
	cout << "--------------------------"<<endl;
	while ((hour>0)&&(i<=hour))//runs while hours are more than 0 and that iteractions made are less than or equal to the amount of hours.
	{
		distance=speed_mph*i;
		cout << i<<"     "<<distance<<endl;
		i++;
	}	
	
}

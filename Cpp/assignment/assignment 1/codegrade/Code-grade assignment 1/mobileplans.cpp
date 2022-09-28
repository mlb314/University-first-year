#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

/*
Write a program that calculates the customer’s monthly bill. IT should input customer name, which package the customer has purchased, and how many minutes and data were used.
 IT should then create a bill that includes the input information and the total amount to pay.
 It should also display how much money package A customers would save if they purchased package B or X, and how much money package B customers would save if they purchased package C.
 If there would be no savings, no message should be printed.

*/

int main () 
{
	string plan,CustomerName;
	double data,minutes,planprice;
	double extrachargedata,extrachargeminutes;
	cin >> data>>minutes>>plan>>CustomerName;

	if (plan.compare("a")||plan.compare("A"))//checks to see if the plan selected is A and if they exceed what the plan gives.
	{
		planprice=29.99;
		if (1 < data <3	||	450 < minutes < 900)
		{
			extrachargedata=(3-data)*2;
			extrachargeminutes=(900-minutes)*0.45;
			
			cout <<"Customers Bill"<<endl;
			cout <<"Plan"<<plan<<endl;
			cout <<"Total cost for this month is: $"<<planprice+extrachargedata+extrachargeminutes<<endl;
			cout <<"You would get a better deal on plan B :$39.99"; 
			
		}
		else if (3>data	|| minutes>900)
		{
			extrachargedata=(data-3)*2;
			extrachargeminutes=(minutes-900)*0.45;
			
			cout <<"Customers Bill"<<endl;
			cout <<"Plan"<<plan<<endl;
			cout <<"Total cost for this month is: $"<<planprice+extrachargedata+extrachargeminutes<<endl;
			cout <<"You would get a better deal on plan C :$59.99"; 
		}
		else ()
		{
			cout <<"there are no savings to be made"<<endl;
		}
		
		
	}
	
	else if (plan.compare("b")||plan.compare("B"))//checks if the plan selected is plan B
	{
		planprice=39.99;
		if ((data < 1) || (minutes < 450))
		{
			cout <<"Customers Bill"<<endl;
			cout <<"Plan "<<plan<<endl;
			cout <<"Total cost for this month is: $"<<planprice;
			cout <<"You would get a better deal on plan A :$29.99"<<endl; 
			
		}
		
		else if (data>3	|| minutes>900)
		{
			extrachargedata=(data-3)*2;
			extrachargeminutes=(minutes-900)*0.45;
			cout <<"Customers Bill"<<endl;
			cout <<"Plan "<<plan<<endl;
			cout <<"Total cost for this month is: $"<<planprice+extrachargedata+extrachargeminutes<<endl;
			cout <<"You would get a better deal on plan C :$59.99"; 
		}
	}

	else if (plan.compare("c")||plan.compare("C")//checks to see if the plan selected is A and if they exceed what the plan gives.
		{
			planprice=59.99;
			if (1<data <3	||	450< minutes <900)
			{
				extrachargedata=(3-data)*2;
				extrachargeminutes=(900-minutes)*0.45;
				
				cout <<"Customers Bill"<<endl;
				cout <<"Plan"<<plan<<endl;
				cout <<"Total cost for this month is: $"<<planprice+extrachargedata+extrachargeminutes<<endl;
				cout <<"You would get a better deal on plan B :$39.99"; 
			
			}
			else if (data>3	|| minutes<900)
			{
				extrachargedata=(data-3)*2;
				extrachargeminutes=(minutes-900)*0.45;
			
				cout <<"Customers Bill"<<endl;
				cout <<"Plan"<<plan<<endl;
				cout <<"Total cost for this month is: $"<<planprice+extrachargedata+extrachargeminutes<<endl;
				cout <<"You would get a better deal on plan C :$59.99"; 
			}	
	
		
	}

}
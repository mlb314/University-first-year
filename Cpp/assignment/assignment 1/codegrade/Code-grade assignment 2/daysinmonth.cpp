/*Write a program that can determine the number of days in a month for a specified month and year.
The program should allow a user to enter two integers representing a month and a year,
and it should determine how many days are in the specified month.
The integers 1 through 12 will be used to identify month of January through to December.
IF the user enters 0 0  for the month and year, then the program should print out the current month and how man days in it.

Use the following criteria to identify leap years:

        A year Y is divisible by 100. Then Y is a leap year if and only if it is divisible by 400. For example, 2000 is a leap year but 2100 is not.
        A year Y is not divisible by 100. Then Y is a leap year if and only if it is divisible by 4. For example 2008 is a leap year, but 2009 is not.

*/
#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;



    int  month,year,day;//global variables
    void getMonthAndYear()
    {
        cout << "What is the month and year?";
        cin >> month >> year;
    }



    int main()
    {
        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//the array with the days allocated to all the months

        getMonthAndYear();// calls the functions to get the results for month and year


        if (month == 0 && year == 0)//validation for 0 0 inputs
        {
            cout << "The current Month December has 31 days";
            return 0;
        }


        if (year % 100 == 0 && year % 400 == 0)//checks that the year is correct before changing 28 days to 29
        {
            days[1] = 29;
        }

        else if (year % 4 == 0)//makse sure that the year is divisable by 4
        {
            days[1] = 29;
        }
        int i = month - 1;

        cout << days[i];//displays the value in the array
        cout << " Days";

    }

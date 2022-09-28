/*Write a program that can determine the number of days in a month for a specified month and year. The program should allow a user to enter two integers representing a month and a year, and it should determine how many days are in the specified month. The integers 1 through 12 will be used to identify month of January through to December. IF the user enters 0 0  for the month and year, then the program should print out the current month and how man days in it.

Use the following criteria to identify leap years:

        A year Y is divisible by 100. Then Y is a leap year if and only if it is divisible by 400. For example, 2000 is a leap year but 2100 is not.
        A year Y is not divisible by 100. Then Y is a leap year if and only if it is divisible by 4. For example 2008 is a leap year, but 2009 is not.

*/
#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;





int loshusquare[9];
               

bool IsLoshuSquare()
{
    
    for (int i = 0; i <= 9;)//makes sure that it cycles throughout the array without exceeding the array
    {
        do
        {
            cin>>loshusquare[i];
        } while (loshusquare[i] <= 0);
        i++;
    }

    if (loshusquare[1] + loshusquare[2] + loshusquare[3] == 15 && loshusquare[4] + loshusquare[5] + loshusquare[6] == 15 && loshusquare[7] + loshusquare[8] + loshusquare[9] == 15)
    {
        if (loshusquare[1] + loshusquare[4] + loshusquare[7] == 15 && loshusquare[2] + loshusquare[5] + loshusquare[8] == 15 && loshusquare[3] + loshusquare[6] + loshusquare[9] == 15)
        {
            if (loshusquare[1] + loshusquare[5] + loshusquare[9] == 15 && loshusquare[3] + loshusquare[5] + loshusquare[7] == 15)
            {
                return true;
            }
        }

    }
    else {
        return false;
        }


}

int main()
{
    
    int loshusquare[9];
    bool true_false = IsLoshuSquare();
    if (true_false == true)
    {
        for (int i = 0; i <= 9;)//makes sure that it cycles throughout the array without exceeding the array
                {

                cout << loshusquare[i]<<" ";
                i++;
                if (i % 3 == 0)
                    { 
                    cout << "\n";
                    }
                }
                
                cout << "These numbers are a loshu square";
    }



};
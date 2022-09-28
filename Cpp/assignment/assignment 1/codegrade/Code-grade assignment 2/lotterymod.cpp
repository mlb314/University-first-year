/*A lottery ticket buyer purchases 10 tickets a week, always playing the 10 five-digit “lucky” combinations.
Write a program that initializes an array with these number and then lets the player enter the week winning five-digit number.
The program should perform a linear search through the list of the player’s numbers and report whether one of the tickets is a winner this week.
Here are the numbers (in order):


*/
#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;



int main()
{

    int chosennumber, i, first, last, middle, winnerlist[10] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121 };
    cin >> chosennumber;
  


    for (int i = 0; i >= 0 && i <= 9;)//makes sure that it cycles throughout the array without exceeding the array
    {
        first = 0;
        last = 9;
        middle = (first + last) / 2;//creating the first middle using the starting values of first and last
        while (first <= last) 
        {
            
            if (chosennumber > winnerlist[middle]) //if this is true then the new middle would be make in the middle of the upper part
            {
                first = middle + 1;
            }

            else if (chosennumber == winnerlist[middle])//compares the array with the given number to see if it matches
            {
                cout << "Congratulations, you have won";
                return 0;
            }

            else 
            {
                last = last - 1;// this is done to decrease the total array to be checked
                middle = (first + last) / 2;//creating the new middle using the new last in the array
            }
        }
        i++;
    }
    cout << "Better luck next time";
}
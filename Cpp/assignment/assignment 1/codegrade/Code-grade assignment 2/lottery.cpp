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
   
    int chosennumber = 0;
    cin >> chosennumber;
    int winnerlist[10] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121 };


    for (int i = 0; i >= 0 && i <= 9;)//makes sure that it cycles throughout the array without exceeding the array
    {
        
        if (chosennumber == winnerlist[i])//compares the array with the given number to see if it matches
        {
            cout << "Congratulations, you have won";
            return 0;
        }
        i++;
    }
    cout << "Better luck next time";
}
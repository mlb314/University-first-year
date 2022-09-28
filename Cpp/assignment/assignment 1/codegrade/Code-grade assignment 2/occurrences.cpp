/*Write a program that lets the user enter a name and calculates the number of occurrences of that name in the following list:

 Amy, Rick, John, Patrick, Marina, Richard, Raj, Marcia, Amy, Richard, John, Rick, Patrick, Amy, Raj, John, Patrick, Richard

 Initialize a one-dimensional array with these values. Then use a linear search algorithm to count the number of occurrences.
 If the user enters a name which is in the array, the program should display the number of occurrences of that name; otherwise,
 it should display a message indicating that the name is not in the list*/
#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;



int main()
{

    string name;

    int counter = 0;

    string namelist[18] = { "Amy", "Rick", "John", "Patrick", "Marina", "Richard", "Raj", "Marcia", "Amy", "Richard", "John", "Rick", "Patrick", "Amy", "Raj", "John", "Patrick", "Richard" };
    cout << "What is the name you would like to compare?";
    getline(cin, name);

    for (int i=0;i >= 0 && i <= 18;)//makes sure that i goes through the whole array
    {
        if (name == namelist[i])//compares the inputted name to all the names in the list
        {
            counter++;//if true it adds one to the counter
        }
        i++;
    }

    if (counter > 0)//validation to make sure that the number is within the list
    {
        cout << "The name " << name << " appears " << counter << " times in the list";
    }

    else//other wise this is outputted
    {
        cout << "The name " << name << " does not appear in the list";
    }
}
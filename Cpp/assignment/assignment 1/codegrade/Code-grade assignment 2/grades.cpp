#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;



int main()
{
    int i=0;
    int percentage;
    int counter=0;
    int total[10];

    while (i >= 0 && i <= 9)
    {
        
        do {
            cout << "What is the percentage?";
            cin >> percentage;
            if (percentage<=100 && percentage > 50)//makes sure the percentage inputted is above 50 before adding to the counter
            {
                counter++;
            }
        } while (percentage < 0 || percentage>100);//validation to make sure to keep asking the question until a valid input is accepted.

        total[i] = percentage;//places the percentage into the array
     i++;
    }
    cout <<"the scores you entered include " <<counter<<" percentages over 50.";

}
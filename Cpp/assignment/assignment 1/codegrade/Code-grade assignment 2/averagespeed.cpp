/* Write a function named averageVelocity that accepts the distance between X and Y, and Y and Z in kilometres,
 and the time take to from X to Y, and from Y to Z in hours, as arguments,
 and returns the average velocity I kilometres per hour.
 Write a program that asks the user to input each argument, and then calls the function and displays the average velocity.*/
#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;



void averageVelocity(float xTOyDistance, float yTOzDistance, float xTOyHours, float yTOzHours, float AverageSpeed)
    {

        do {
            cout << "What is the distance between X and Y? (in Kilimeters)";
            cin >> xTOyDistance;
        } while (xTOyDistance <= 0);//continues to ask the question until a correct answer has been inputted
        

        do {
            cout << "What is the distance between Y and Z? (in Kilometers)";
            cin >> yTOzDistance;
        } while (yTOzDistance <= 0);//continues to ask the question until a correct answer has been inputted
        

        do {
            cout << "How long did it take to get from X to Y?";
            cin >> xTOyHours;
        } while (xTOyHours <= 0);//continues to ask the question until a correct answer has been inputted
        

        do {
            cout << "How long did it take to get from Y to Z?";
            cin >> yTOzHours;
        } while (yTOzHours <= 0);//continues to ask the question until a correct answer has been inputted
        


        AverageSpeed = ((xTOyDistance + yTOzDistance) / (xTOyHours + yTOzHours));//this calculates the average velocity of the traveller
        cout << "Average speed was " << AverageSpeed << "Km/H";
    }

int main()
{
    
    averageVelocity(0,0,0,0,0.0);//called the function
    return 0;
}
    





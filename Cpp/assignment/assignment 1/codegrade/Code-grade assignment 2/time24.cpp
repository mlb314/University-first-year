/* Design a class called Time24 that has integer data members to store hours, minutes, and seconds, representing time in 24 - hour notation.
The class should have a three - parameter default constructor that allows the user to set the time when a new Time24 object is created.
The class should only accept 0 - 23 as values for hours, and 0 - 59 as values for minutes and seconds.
If a Time24 object is created without arguments or invalid arguments the default values of 0, 0, 0 should be used.
The class should have member functions to display the following :

•    The time in 24 - hour format(15: 04 : 47)
•    The time in 12 - hour format(03: 03 : 47 PM)
•    A greeting : “Good Morning” if the time is between 6am and 11 : 59 : 59. “Good Afternoon” if the time is between 12 : 00 : 00 and 17 : 59 : 59, “Good Evening” if between 18 : 00 : 00 and 22 : 59 : 59 and “Time to sleep” if between 23 : 00 : 00 and 5 : 59 : 59.

Demonstrate the use of the class in a program that asks the user to input the time.

Output should look like :

12 - hour format : <value> PM
24 - hour format : <value>
<greeting>*/
#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;


class Time24 //creating the class 
{
private: // initialising the variables to be used throughout the code
    int second;
    int minute;
    int hour;

public:
    Time24(int s, int m, int h) {
        second = s;
        minute = m;
        hour = h;
    }


    void getTime()
    {
        cout << "Input hours :";
        cin >> hour;
        if (hour < 0|| hour > 23) //validation to make sure that the input is a valid 
        {
            hour = 0;//if the input is not valid then it defaults to 0
        }
        cout << "Input minutes :";
        cin >> minute;
        if (minute < 0|| minute > 59)//validation to make sure that the input is a valid 
        {
            minute = 0;//if the input is not valid then it defaults to 0
        }

        cout << "Input seconds :";
        cin >> second;
        if (second<0||second>59)//validation to make sure that the input is a valid 
        {
            second = 0;//if the input is not valid then it defaults to 0
        }

    }


    void format12()
    {
        if (hour==12) //checks to see if the hour is equal to 12 to set the time to PM
        {
            cout << "12-hour format: "<< setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second <<" PM\n";
        }
        else if (hour > 12)//checks to make sure the hour is greater than 12 to make the time to PM
        {
            
            cout << "12-hour format: "<< setw(2) << setfill('0') << hour-12 << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " PM\n";
        }
        else//otherwise the time is set to AM
        {
            cout << "12-hour format: "<< setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " AM\n";
        }
    }
   
    void format24()
    {
        cout << "24-hour format: "<< setw(2) <<setfill('0')<< hour << ":" << setw(2) <<setfill('0')<< minute << ":" << setw(2) <<setfill('0') << second<<"\n";
    }

    void greeting()
    {
        if (hour>=6 && hour <= 11)//validation to make sure the hour is between 6 and 11 then proceed
        {
            cout << "Good Morning";
        }
        else if (hour>=12 && hour <= 17)//validation to make sure the time is between 12 and 17 then proceed
        {
            cout << "Good Afternoon";
        }
        else if (hour>=18 &&hour <= 22)//validation to make sure the time is between 18 and 22 then proceed
        {
            cout << "Good Evening";
        }
        else if(hour==23||hour<6)//validation to make sure the hour is equal to 23 and less than 6 then proceed.
        {
            cout << "Time to Sleep";
        }
    }
};


int main()
{
    Time24 dayOne (0, 0, 0); // make the object
    dayOne.getTime(); //calling the getTime function for its output/result
    dayOne.format12();//calling the format12 function for its output/result
    dayOne.format24();//calling the format24function for its output/result
    dayOne.greeting();//calling the greeting function for its output/result
    return 0;
};


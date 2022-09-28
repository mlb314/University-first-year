#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
//quick comment here, this code DOES work, but i have no clue upon how to deter all the inputs from one line into an array
//if it was multiple inputs on multiple lines i'd be fine but the inputs of code grade made this annoying since it works but code grade doesnt think so.


    int loshusquare[9];

    bool IsLoshuSquare()
    {
		 for (int i = 0; i <= 8;)//makes sure that it cycles throughout the array without exceeding the array     and this is the few lines which take the input doesnt work with codegrades input
        {                                                                                                                         //<<<<<<
                cin >> loshusquare[i];                                                                                            //<<<<<<
                i++;                                                                                                              //<<<<<<   
        }                                                                                                                         //<<<<<<
		
        if (loshusquare[0] + loshusquare[1] + loshusquare[2] == 15 && loshusquare[3] + loshusquare[4] + loshusquare[5] == 15 && loshusquare[6] + loshusquare[7] + loshusquare[8] == 15)
        {
            if (loshusquare[0] + loshusquare[3] + loshusquare[6] == 15 && loshusquare[1] + loshusquare[4] + loshusquare[7] == 15 && loshusquare[2] + loshusquare[5] + loshusquare[8] == 15)
            {
                if (loshusquare[0] + loshusquare[4] + loshusquare[8] == 15 && loshusquare[2] + loshusquare[4] + loshusquare[6] == 15)
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

  bool true_false = IsLoshuSquare();
    if (true_false == true)
    {
        for (int i = 0; i <= 9;)//makes sure that it cycles throughout the array without exceeding the array
            {

            cout << loshusquare[i];
                i++;
                if (i % 3 == 0)
                { 
                cout << "\n";
                }
                else
                {
                    cout << " ";
                }
            }
                
                cout << "These numbers are a loshu square";
    }
};
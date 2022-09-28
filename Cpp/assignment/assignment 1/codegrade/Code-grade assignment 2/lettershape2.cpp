#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;



int main()
{
    string letter[7] = { "       a","      bb","     ccc","    dddd","   eeeee", "  ffffff"," ggggggg" };

    for (int i = 0; i <=6 ; i++)//cycles through the array using a loop, making sure that the placement started at 0 and goes until it reaches 6
    {
        cout << letter[i]<<endl;   
    }


}
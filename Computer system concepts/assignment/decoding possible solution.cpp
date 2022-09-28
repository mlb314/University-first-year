#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
#include<sstream>
#include <vector>
using namespace std;

string EncodeAddAndMoveFunction(vector<string>Assemberinput)
{
    int index = 0;
    cout << Assemberinput[0] << " " << Assemberinput[1] << " " << Assemberinput[2]<<endl;
    string wholearray = Assemberinput[2];
    cout << wholearray<<endl;
    return "";

}

int main()
{
        vector<string> AssemblerInput;

        // Get the String

        string str = "";
        cout << "Please input your command. In either Assembler (example:add a, 46), or in Hexadecimal(example:812435H)"<<endl;
        getline(cin, str);
        // Initialise the istringstream
        // with the given string
        istringstream iss(str);

        // Iterate the istringstream
        // using do-while loop
        do
        {
            string subs;

            // Get the word from the istringstream
            iss >> subs;

            // add the words to a vector<string>
            AssemblerInput.push_back(subs);

        } while (iss);

        EncodeAddAndMoveFunction(AssemblerInput);

        
}



int main()
{
    string Assemberinput;
    cout << "Yo";
    getline(cin, Assemberinput);
    int index = 0;
    cout << Assemberinput;
    string wholearray = "";
    int templength = Assemberinput.size();
    Assemberinput = Assemberinput.substr(0, templength - 1);
    cout << Assemberinput<< endl;

}

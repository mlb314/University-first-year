#include <iomanip>
#include <cmath>
#include <iostream>
#include <string>
#include<sstream>
#include <vector>
using namespace std;
//little endien and decimal to binary conversion
/*

Disclaimer!
This code does work but i was having an issue with getting the hex.
it was giving /x(hex) instead of just the hex. i had tried alot of methods to try and fix this but was unable to implement one.


string binToHex(string binary) {
    //get input
    cout << "Please enter a binary number with no spaces: "<<endl;
    string binaryInput = binary;

    //make sure the input's length is a multiple of 4
    while ((binaryInput.length() % 4) != 0) {
        binaryInput = "0" + binaryInput;
    }

    string hexOutput = "";

    //now look at each group of 4 digits, and convert to hexadecimal.
    int index = 0;
    while (index + 3 < binaryInput.length()) {
        int j=0;
        string fourDigits = binaryInput.substr(index, 4);

        int intAllocatedHex[10] = {0,1,2,3,4,5,6,7,8,9};
        string strAllocatedHex[6] = {"A","B","C","D","E","F"};
        string Binaryarray[16] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};

        for (int i = 0; i < 16; i++){
            if (fourDigits == Binaryarray[i]&&i>10)
            {
                hexOutput += strAllocatedHex[i-11];
            }
            else if (fourDigits == Binaryarray[i] && i <= 10)
            {
                hexOutput += intAllocatedHex[i];
            }
            j++;

        }
    index = index + 4;

    }
    cout <<hexOutput;
    hexOutput = stoi(hexOutput);
    int i = hexOutput;
    stringstream ss;
    ss << i;
    string str = ss.str();
    hexOutput = i;

    cout <<hexOutput;
    return hexOutput;
}


*/

int sBinToDec(string binary) {

    //read in the string so we can parse through it, character by character.
    string binaryNumber = binary;

    //get the length of the string, then create a variable called 'currentBit' that will point
    //to the last bit
    int stringLength = binaryNumber.length();
    int currentBit = stringLength - 1;

    //the variable bitValue will start at 1 and double each time we move to the next bit along
    int bitValue = 1;
    //decimalOutput will keep a total and will add up to the result.
    int decimalOutput = 0;

    //once currentBit has gone past the first character in the string, we stop.
    while (currentBit > -1) {

        /*
         * Here, we read the current bit, and multiply it by the value of the column we are in.
         * Because we are reading a character, C++ converts it to it's ASCII equivalent, so we
         * subtract '0' to get the integer value 0 or 1.
         */

         //if we are on the last column, then the value should be a negative number
        if (currentBit == 0) {
            bitValue = bitValue * -1;
        }

        decimalOutput += (bitValue * (int)(binaryNumber[currentBit] - '0'));

        //move to the next bit along, where the value is double the last column.
        bitValue = bitValue * 2;
        --currentBit;
    }

    return decimalOutput;
}


string hexToBin(string input) {
    //get the input
    string hexInput = input;
    string binaryOutput = "";

    int hexIndex = 0;
    while (hexIndex < hexInput.length()) {
        switch (hexInput[hexIndex]) {
        case '0': binaryOutput = binaryOutput + "0000";
            break;
        case '1': binaryOutput = binaryOutput + "0001";
            break;
        case '2': binaryOutput = binaryOutput + "0010";
            break;
        case '3': binaryOutput = binaryOutput + "0011";
            break;
        case '4': binaryOutput = binaryOutput + "0100";
            break;
        case '5': binaryOutput = binaryOutput + "0101";
            break;
        case '6': binaryOutput = binaryOutput + "0110";
            break;
        case '7': binaryOutput = binaryOutput + "0111";
            break;
        case '8': binaryOutput = binaryOutput + "1000";
            break;
        case '9': binaryOutput = binaryOutput + "1001";
            break;
        case 'A': binaryOutput = binaryOutput + "1010";
            break;
        case 'B': binaryOutput = binaryOutput + "1011";
            break;
        case 'C': binaryOutput = binaryOutput + "1100";
            break;
        case 'D': binaryOutput = binaryOutput + "1101";
            break;
        case 'E': binaryOutput = binaryOutput + "1110";
            break;
        case 'F': binaryOutput = binaryOutput + "1111";
            break;
        }
        hexIndex++;
    }
    return binaryOutput;
}

string decToSBin(string input) {

    //read in the string and convert it to an integer.

    int decimalNumber = stoi(input);

    string binaryOutput = "";

    bool isNegative = false;
    if (decimalNumber < 0) {
        isNegative = true;
        //we need to convert it as a positive number
        //then afterwards flip the bits and add one.
        //if we subtract one from the positive value,
        //this has the same effect
        decimalNumber = (decimalNumber * -1) - 1;
    }

    //while the number is greater than 1, we divide it by 2.
    while (decimalNumber > 0) {
        //dividing an integer by two gives us a whole number answer, not a fraction.
         //so we work out the remainder first using % operand
        int remainder = decimalNumber % 2;
        //then we divide the number by two for the next step.
        decimalNumber = decimalNumber / 2;
        //now we add the remainder to our binary output.
        binaryOutput = binaryOutput + to_string(remainder);
    }

    //add a zero to the end because we're dealing with signed binary now
    binaryOutput = binaryOutput + "0";

    //let's group this into 8 bits - this loop will add zeros until we have a
    //multiple of 8 digits in our output.
    while (binaryOutput.length() % 8 != 0) {
        binaryOutput = binaryOutput + "0";
    }

    //now we have to read the remainders backwards for the output.
    reverse(binaryOutput.begin(), binaryOutput.end());

    //flip the bits if the number was originally negative
    if (isNegative) {

        int index = 0;
        //loop through and turn all 0s to 1s and vice versa
        while (index < binaryOutput.length()) {
            if (binaryOutput[index] == '0') {
                binaryOutput[index]++;
            }
            else {
                binaryOutput[index]--;
            }
            index++;
        }
    }

    cout << binaryOutput;
    return binaryOutput;
}

string binToHex(string input) {
    string binaryInput = input;

    //make sure the input's length is a multiple of 4
    while ((binaryInput.length() % 4) != 0) {
        binaryInput = "0" + binaryInput;
    }

    string hexOutput = "";

    //now look at each group of 4 digits, and convert to hexadecimal.
    int index = 0;
    while (index + 3 < binaryInput.length()) {
        string fourDigits = binaryInput.substr(index, 4);
        if (fourDigits == "0000") {
            hexOutput = hexOutput + "0";
        }
        else if (fourDigits == "0001") {
            hexOutput = hexOutput + "1";
        }
        else if (fourDigits == "0010") {
            hexOutput = hexOutput + "2";
        }
        else if (fourDigits == "0011") {
            hexOutput = hexOutput + "3";
        }
        else if (fourDigits == "0100") {
            hexOutput = hexOutput + "4";
        }
        else if (fourDigits == "0101") {
            hexOutput = hexOutput + "5";
        }
        else if (fourDigits == "0110") {
            hexOutput = hexOutput + "6";
        }
        else if (fourDigits == "0111") {
            hexOutput = hexOutput + "7";
        }
        else if (fourDigits == "1000") {
            hexOutput = hexOutput + "8";
        }
        else if (fourDigits == "1001") {
            hexOutput = hexOutput + "9";
        }
        else if (fourDigits == "1010") {
            hexOutput = hexOutput + "A";
        }
        else if (fourDigits == "1011") {
            hexOutput = hexOutput + "B";
        }
        else if (fourDigits == "1100") {
            hexOutput = hexOutput + "C";
        }
        else if (fourDigits == "1101") {
            hexOutput = hexOutput + "D";
        }
        else if (fourDigits == "1110") {
            hexOutput = hexOutput + "E";
        }
        else if (fourDigits == "1111") {
            hexOutput = hexOutput + "F";
        }
        index = index + 4;
    }
    return hexOutput;
}

string EncodeLoadFunction(vector<string>Assembler)//function uses the vector from the main
{
    string binary = "01";
    string Binaryarray[5] = { "000","001","010","011","100" };//an array of all the acceptable binary it can be
    string assemblerarray[5] = { "A,","B,","C,","D,","E," };//an array of all the possible letters

    for (int i = 0; i < 6; i++)
    {
        if (Assembler[1] == assemblerarray[i])
        {
            binary += Binaryarray[i] + "110";
        }//a parrellel array which then adds the result to binary

    }
    string temparray = Assembler[2];//this does the little endien
    string adr = "";
    adr += temparray[2];
    adr += temparray[3];
    adr += temparray[0];
    adr += temparray[1];

    cout << "The binary is:" << binary << endl;

    string conversionresult = binToHex(binary);
    conversionresult = conversionresult + adr + "H";//outputs the result
    cout << conversionresult;
    return conversionresult;//returns the result
}

string EncodeAddAndMoveFunction(vector<string>Assemberinput)
{
    string binary = "";
    if (Assemberinput[0] == "MOVE")//since add and move are basically the same an if statment differentiates between whether its add or move
    {
        binary = "01";
    }
    else if (Assemberinput[0] == "ADD")
    {
        binary = "00";
    }
    string Binaryarray[5] = { "000","001","010","011","100" };//all the binary which would be used 
    string assemblerarray[5] = { "A,","B,","C,","D,","E," };//an array of the possible srcreg inputs
    string letterarray[5] = { "A","B","C","D","E" };//an array of the possible destreg inputs
    int temp = 0;
    string dectoSbinresult;
    string SbintoHexresult;
    string conversionresult;
    for (int i = 0; i < 5; i++)
    {
        if (Assemberinput[1] == assemblerarray[i]) { binary += Binaryarray[i]; }//a parrellel array which then adds the result to binary
    }
    for (int i = 0; i < 5; i++)
    {
        if (Assemberinput[2] == letterarray[i])
        {
            binary += Binaryarray[i];//a parrellel array which then adds the result to binary
            cout << "The binary is :" << binary << endl;
            conversionresult = binToHex(binary);
            conversionresult += "H";
            cout << conversionresult;
            return conversionresult;
        }

        else if (Assemberinput[2] != assemblerarray[i] && i == 4)//makes sure that when its a match has not been made and variable 'i' is at its highest before conintuing
        {
            SbintoHexresult = binToHex(binary + "101" + decToSBin(Assemberinput[2]));

            cout << endl << SbintoHexresult << "H";
        }

    }
    return SbintoHexresult;//return the hex result

}


string EncodeStoreFunction(vector<string>input)
{

    string binary = "01";
    string Binaryarray[5] = { "000","001","010","011","100" };//an array of the attainable binary outputs
    string assemblerarray[5] = { "A","B","C","D","E" };//an array of the possible inputs

    for (int i = 0; i < 5; i++)
        if (input[2] == assemblerarray[i])//compares the arrays together to make sure there is a match
        {
            binary = binary + "110" + Binaryarray[i];
        }

    cout << "The binary is: " << binary << endl;
    string hexresult = binToHex(binary);//this grabs the hex result from the function

    string temparray = input[1];//this does little endiend
    string adr = "";
    adr += temparray[2];
    adr += temparray[3];
    adr += temparray[0];
    adr += temparray[1];
    cout << "The Hex is: " << hexresult << adr << "H" << endl;
    return "";
}

string EncodeJMPFunction(vector<string>Assemberinput)
{
    string binary = "";
    if (Assemberinput[0] == "JMP") { binary += "10000000"; }     //a list of is statements that determine which binary to be added
    else if (Assemberinput[0] == "JPZ") { binary += "10000001"; }
    else if (Assemberinput[0] == "JPP") { binary += "10000010"; }
    else if (Assemberinput[0] == "JPN") { binary += "10000011"; }
    cout << "The Binary is: " << binary << endl;
    string hexresult = binToHex(binary);//gets the restult from the function and put it into the hexresult


    string temparray = Assemberinput[1];//little endien
    string adr = "";
    adr += temparray[2];
    adr += temparray[3];
    adr += temparray[0];
    adr += temparray[1];
    cout << "The Hex is: " << hexresult << adr << "H" << endl;
    return "";
}

string DecodeJMPFunction(vector<string>hex) {

    string tempstring = hex[0];
     string assembler = "";
     if (tempstring[0]=='8'&&tempstring[1]=='0')//compares the first and second char of the hex to see what JMP it falls under 
     {
         assembler += "JMP ";
     }
     else if (tempstring[0]=='8'&&tempstring[1]=='1')
     {
         assembler +="JPZ ";
     }
     else if (tempstring[0]=='8'&&tempstring[1]=='2')
     {
         assembler += "JPP ";
     }
     else if (tempstring[0]=='8'&&tempstring[1]=='3')
     {
         assembler += "JPN ";
     }

    
     string temp= hex[0];
     string littleEndien = "";//converts the hex into little endien format
     littleEndien += temp[4];
     littleEndien += temp[5];
     littleEndien += temp[2];
     littleEndien += temp[3];
    cout <<endl<< "The assembler code is: " << assembler + littleEndien+"H";//output the result
    return assembler;
}

string DecodeMoveStoreLoadFunction(string hexadecimal) {
    
    string binaryresult=hexToBin(hexadecimal); // converts bin to hex
    string destreg = "";
    string srcreg = "";
    string assembler = "";
    int temp = 0;
    string binary;
    if (binaryresult[0] == '0' && binaryresult[1] == '1'&&binaryresult[5]=='1'&&binaryresult[6]=='1' && binaryresult[7]=='0')//makes sure that the input  alligns up with the LOAD opp code
    {
        assembler += "LOAD ";
        if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '0')//a list of if statements which conclude what the src
        {
            srcreg += "A,";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '1')
        {
            srcreg += "B,";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '0')
        {
            srcreg += "C,";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '1')
        {
            srcreg += "D,";
        }
        else if (binaryresult[2] == '1' && binaryresult[3] == '0' && binaryresult[4] == '0')
        {
            srcreg += "E";
        }
        string hex1 = hexadecimal.substr(2, 4);// this does little endien using string
        string hex2 = hexadecimal.substr(4, 6);
        string hex3 = hex2 + hex1;
        hex3 = hex3.substr(0, 4);
            cout <<assembler<< srcreg <<" "<< hex3 <<"H";
        
    }
    else if (binaryresult[0] == '0' && binaryresult[1] == '1' && binaryresult[2] == '1' && binaryresult[3] == '1' && binaryresult[4] == '0')//makes sure that the input  alligns up with the STORE opp code
    {
        assembler += "STORE ";//stores the string to assembler
        if (binaryresult[5] == '0' && binaryresult[6] == '0' && binaryresult[7] == '0')//a group of if statements that decide what the result is and adds it to the destreg
        {
            destreg += "A";
        }
        else if (binaryresult[5] == '0' && binaryresult[6] == '0' && binaryresult[7] == '1')
        {
        destreg += "B";
        }
        else if (binaryresult[5] == '0' && binaryresult[6] == '1' && binaryresult[7] == '0')
        {
            destreg += "C";
        }
        else if (binaryresult[5] == '0' && binaryresult[6] == '1' && binaryresult[7] == '1')
        {
           destreg += "D";
        }
        else if (binaryresult[5] == '1' && binaryresult[6] == '0' && binaryresult[7] == '0')
        {
           destreg += "E";
        }

        string hex1 = hexadecimal.substr(2, 4);
        string hex2 = hexadecimal.substr(4, 6);
        string hex3 = hex2 + hex1;
        hex3 = hex3.substr(0, 4);
        cout <<endl<< assembler <<hex3<<"H, " << destreg<<" ";
        
    }
    else if (binaryresult[0] == '0' && binaryresult[1] == '1' && binaryresult[5] == '1' && binaryresult[6] == '0' && binaryresult[7] == '1')//makes sure that the input  alligns up with the LOAD op code
    {
        assembler += "MOVE ";//stores the string into the assembler
        if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '0')//a group of if statements that decide what is to be added to the srcreg
        {
            srcreg += "A";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '1')
        {
            srcreg += "B";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '0')
        {
            srcreg += "C";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '1')
        {
            srcreg += "D";
        }
        else if (binaryresult[2] == '1' && binaryresult[3] == '0' && binaryresult[4] == '0')
        {
            srcreg += "E";
        }
        int length = binaryresult.size();
        int number = sBinToDec(binaryresult.substr(8,length));//converts the binary to an int number
        cout << endl<< assembler << " " << srcreg << ", " << number;

    }
    else
    {
        string destred = "";
        srcreg += "Move ";
        if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '0')//group of if statements that decide what string would be allocated to the srcreg
        {
            srcreg += "A";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '1')
        {
            srcreg += "B";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '0')
        {
            srcreg += "C";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '1')
        {
            srcreg += "D";
        }
        else if (binaryresult[2] == '1' && binaryresult[3] == '0' && binaryresult[4] == '0')
        {
            srcreg += "E";
        }



        if (binaryresult[5] == '0' && binaryresult[6] == '0' && binaryresult[7] == '0')//a group of if statements what decide what is to be allocated to the destreg
        {
            destreg += "A";
        }
        else if (binaryresult[5] == '0' && binaryresult[6] == '0' && binaryresult[7] == '1')
        {
            destreg += "B";
        }
        else if (binaryresult[5] == '0' && binaryresult[6] == '1' && binaryresult[7] == '0')
        {
            destreg += "C";
        }
        else if (binaryresult[5] == '0' && binaryresult[6] == '1' && binaryresult[7] == '1')
        {
            destreg += "D";
        }
        else if (binaryresult[5] == '1' && binaryresult[6] == '0' && binaryresult[7] == '0')
        {
            destreg += "E";
        }
        cout <<endl<< assembler << srcreg <<", " << destreg;//outputs the result of the function
    }
       
    return assembler;
}


string DecodeAddFunction(string hexadecimal)
{
    string binaryresult = hexToBin(hexadecimal);
    string destreg = "";
    string srcreg = "";
    string assembler = "";
    int temp = 0;
    string binary;
    if ( binaryresult[5] == '1' && binaryresult[6] == '0' && binaryresult[7] == '1')//a group of if statements that decide what is to be allocated to the srcreg
    {
        assembler += "ADD ";
        if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '0')
        {
           srcreg += "A";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '1')
        {
            srcreg += "B";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '0')
        {
            srcreg += "C";
        }
        else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '1')
         {
            srcreg += "D";
        }
        else if (binaryresult[2] == '1' && binaryresult[3] == '0' && binaryresult[4] == '0')
        {
            srcreg += "E";
        }
        int length = binaryresult.size();
        int number = sBinToDec(binaryresult.substr(8, length));//converts the binary into an int number
        cout << endl << assembler << " " << srcreg << ", " << number;//outputs the result
    }

    else
    {
    srcreg += "ADD ";
    if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '0')//a group of if statements that decide what is to be allocated to the srcreg
    {
        srcreg += "A";
    }
    else if (binaryresult[2] == '0' && binaryresult[3] == '0' && binaryresult[4] == '1')
    {
        srcreg += "B";
    }
    else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '0')
    {
        srcreg += "C";
    }
    else if (binaryresult[2] == '0' && binaryresult[3] == '1' && binaryresult[4] == '1')
    {
        srcreg += "D";
    }
    else if (binaryresult[2] == '1' && binaryresult[3] == '0' && binaryresult[4] == '0')
    {
        srcreg += "E";
    }



    if (binaryresult[5] == '0' && binaryresult[6] == '0' && binaryresult[7] == '0')//a group of if statements that decide what is to be allocated to the destreg
    {
        destreg += "A";
    }
    else if (binaryresult[5] == '0' && binaryresult[6] == '0' && binaryresult[7] == '1')
    {
        destreg += "B";
    }
    else if (binaryresult[5] == '0' && binaryresult[6] == '1' && binaryresult[7] == '0')
    {
        destreg += "C";
    }
    else if (binaryresult[5] == '0' && binaryresult[6] == '1' && binaryresult[7] == '1')
    {
        destreg += "D";
    }
    else if (binaryresult[5] == '1' && binaryresult[6] == '0' && binaryresult[7] == '0')
    {
        destreg += "E";
    }
    cout << endl << assembler << srcreg << ", " << destreg;//output the result
    return assembler;
    }
    
}

int main()
{
    string binary = "";
    vector<string> AssemblerInput;

    // Get the String

    string str = "";
    cout << "Please input your command. In either Assembler (example:add a, 46), or in Hexadecimal(example:812435H)" << endl;
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


    if (AssemblerInput[0] != "" && AssemblerInput[1] == "")//validation to make sure that there is at least one input and no second on. as hex is only 1 input
    {
        int tempsize = AssemblerInput[0].size();
        if (AssemblerInput[0].substr(tempsize - 1, tempsize) != "H")//add H to the end of the hex code for it to be valid
        {
            AssemblerInput[0] += "H";
        }

        cout <<"Your input is: " << AssemblerInput[0] << endl;
        
        string temp = AssemblerInput[0];
        int templength = AssemblerInput[0].size();
        temp = temp.substr(0, templength - 1);//removes the H from the end of the hex code because i just want the hex code not including the H at the end
        


        binary = hexToBin(temp);//converts the input from the first input to binary
        cout << "The binary is: "<<binary;
        if (binary.substr(0, 2) == "00")//if the first 2 numbers of the binary are 00 send to the decodeadd
        {
            DecodeAddFunction(AssemblerInput[0]);
        }
        else if (binary.substr(0, 2) == "01")//if the first 2 numbers of the binary are 01 send to the decodeadd
        {
            DecodeMoveStoreLoadFunction(temp);
        }
        else if (binary.substr(0, 1) == "1")//if the first number of binary is 1 then send to the decodeadd
        {
            DecodeJMPFunction(AssemblerInput);
        }
    }

    else if (AssemblerInput[0] != "" && AssemblerInput[1] != "" || AssemblerInput[2] != "")//validation for assembly inputs, must have atleast 3 inputs separated by a space
    {
        for (int j = 0; j < 3; j++)
        {
            string temp = AssemblerInput[j];
            for (int i = 0; i < AssemblerInput[j].length(); i++)//loops through the length of the inputs
            {
                temp[i] = toupper(temp[i]);//converts all values in the assembler to their uppercase forms

            }
            AssemblerInput[j] = temp;
        }
        cout << "You have inputted: " << AssemblerInput[0] + " " << AssemblerInput[1] << " " << AssemblerInput[2] << endl;



        if (AssemblerInput[0] == "ADD")//inputs that decide which function to be directed to
        {
            EncodeAddAndMoveFunction(AssemblerInput);
        }
        else if (AssemblerInput[0] == "MOVE")
        {
            EncodeAddAndMoveFunction(AssemblerInput);
        }
        else if (AssemblerInput[0] == "STORE")
        {
            EncodeStoreFunction(AssemblerInput);
        }
        else if (AssemblerInput[0] == "LOAD")
        {
            EncodeLoadFunction(AssemblerInput);
        }
        else if (AssemblerInput[0] == "JPP" || AssemblerInput[0] == "JPZ" || AssemblerInput[0] == "JPN" || AssemblerInput[0] == "JMP")
        {
            EncodeJMPFunction(AssemblerInput);
        }
        else {
            main();//returns back for another input if nothing accuratly was inputted
        }

    }
}


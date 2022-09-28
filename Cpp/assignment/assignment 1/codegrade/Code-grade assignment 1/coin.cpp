
//The outcome of tossing a fair coin can be either ‘Heads’ of ‘Tails’. Write a program to simulate a coin toss. 
//The program should ask the user to enter either ‘H’ or ‘T’. The program should then simulate tossing the coin by randomly generating either 1,
// representing heads or 0 representing tails. If the user's input should match the outcome of the toss, the program should display “You Win”. Otherwise, it should display “You Lose”.

//Output Should be either :

//You Win

//or

//You Lose

#include <iostream>
#include <string>
using namespace std;

int main()
{

	string userinput = "";

	cin >> userinput;
	unsigned seed = time(0);
	srand(seed);
	int Nrandom = rand() % 2 + 1;
	// the above is to create a random number between 1 and 2
	
	//userinput.compare is used to compare the users input with the desired input in the (),and if its correct it continues to the second part of the if statement.
	if (userinput.compare("H") && Nrandom == 1)
	{
		cout << "You win!";
	}
	else if (userinput.compare("T") && Nrandom == 1)
	{
		cout << "You win!";
	}
	else
	{
		cout << "You Lose!";
	}
}

#include <iostream>
using namespace std;

int main()
{
	int daybob; 
	int totalbob;
	int totaldayb;
	int remainderb;
	int dayjenny;
	int totaljenny;
	int totaldayj; 
	int remainderj;

	cout << "how many days has bob and jenny worked respectfully?\n";
	cin >> daybob;
	cin >> dayjenny;
	totalbob = daybob * 270;
	totaljenny = dayjenny * 195;

	totaldayb = totalbob / 60;
	remainderb = totalbob % 60;

	totaldayj = totaljenny / 60;
	remainderj = totaljenny % 60;

	cout << "Bob worked a total of " << totaldayb << " hours and " << remainderb << " minutes on the project\n";
	cout << "Jenny worked a total of " << totaldayj << " hours and " << remainderj << " minutes on the project\n";
	//Bob worked a total of 22 hours and 30 minutes on the project
	//Jenny worked a total of 29 hours and 15 minutes on the project
}
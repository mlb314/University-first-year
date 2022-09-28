#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
using namespace std;


class Patient
{

private:
	string name, email, phonenumber;//string variables
	float weight, height, bmiData;//float variables
	vector<float>weights;//store a list of all the weights
	vector<float> BMIs;//store a list of calculated BMI(s)

public:



	void addPatientData()
	{

		cout << "Input the patient information" << endl;
		cout << "Type in new name :";
		getline(cin >> ws, name);//collects the whole line and inputs it as the name, allowing for spaces


		cout << "Email :";
		cin >> email;//getting email
		cout << "\n";

		cout << "Phonenumber :";
		cin >> phonenumber;//getting the phonenumber
		cout << "\n";

		cout << "Current Height :";
		cin >> height;//getting the height
		cout << "\n";

		cout << "Current Weight :";
		cin >> weight;//getting the weight
		weights.push_back(weight);//pushing the wight variable into the weights vector, this used later for the displaying all the patients historic BMI(S)
		cout << "\n";
	};

	vector<float> getBMI()
	{
		return BMIs;//returns the vector
	}

	void calcBMI()
	{
		bmiData = weight / (height * height);//calculations
		BMIs.push_back(bmiData);//pushing back the bmi data to the BMI vector
	}

	void BMIDisplay()
	{
		calcBMI();
		for (unsigned int i = 0; i < BMIs.size(); i++)//looping through and displaying all the historic BMI(s) if there are any
		{
			cout << " " << BMIs[i] << "";
		}
	}



	float getBMIcalc()
	{
		bmiData = weight / (height * height);//used to calculate the bmidata
	};


	float getLastestBMIFromVector()
	{
		calcBMI();//calls the function
		
		return  BMIs[BMIs.size() - 1];
		

	};

	void patientBMIHistory()
	{
		cout << "Name: " << name << endl;//displays the patient information
		cout << "Email: " << email << endl;
		cout << "Phone Number: " << phonenumber << endl;
		cout << "BMI(s) ";
		BMIDisplay();//calls the BMIdisplay function
		cout << "\n";
	};

	void getweight(ofstream& outputfile)//function that just outputs all the the vector to a file in reverse order as when its being read from the file itll be in reverse order.
	{
		//create the outpurfile object
		for (int i = 0; i < weights.size(); i++)//loops through the vector for the end to the beginning
		{
			outputfile << weights[i] << endl;
		}
	}
	int getweightsize()
	{
		int tempweight = weights.size();
		return tempweight;
	};

	void setname(string tempname)
	{
		name = tempname;//changes the name to the tempname from the loaded in file
	};

	void setEmail(string tempemail)
	{
		email = tempemail;//changes the email to the tempname from the loaded in file
	};

	void setPhonenumber(string tempPhoneNo)
	{
		phonenumber = tempPhoneNo;//changes the phonenumber to the tempname from the loaded in file
	};

	void setHeight(float tempheight)
	{
		height = tempheight;//changes the height to the tempname from the loaded in file
	};

	void setWeight(float tempweight)
	{
		weight = tempweight;//changes the weight to the tempname from the loaded in file
		weights.push_back(weight);//adds the weight to the weight vector since the vector is now empty and is being filled with data from the file.
	};

	string getName()
	{
		return name;//returns name
	}

	string getEmail()
	{
		return email;//returns email
	}

	string getPhonenumber()
	{
		return phonenumber;//returns phonenumber
	};

	float getHeight()
	{
		return height;//returns height
	}

	void displayAllPatientData()//function that displays the patients information, not including recent or past bmi
	{
		cout << "Name: " << name << endl;
		cout << "Email: " << email << endl;
		cout << "Phone Number: " << phonenumber << endl;

	}

	void updateWeight()
	{
		cout << "Update the patients weight" << endl;
		cin >> weight;//collects the weight
		weights.push_back(weight);//pushs the weight into the weights vector
	}

	void updatePatient()
	{
		string choice;
		cout << "Update Email? Y/N";
		cin >> choice;
		if (choice == "Y" || choice == "y")//selects the choice
		{
			cout << "New Email: ";
			cin >> email;//updates the email
		}


		cout << "Update PhoneNumber? Y/N";
		cin >> choice;
		if (choice == "Y" || choice == "y")//selects the choice
		{
			cout << "New Phonenumber:";
			cin >> phonenumber;//updates the phone number
		}
	};


};






class Menu
{

private:
	bool keepMenuGoing = true;
	vector<Patient> patients;//vector to hold all people names

	void printPersonVector()
	{

		for (unsigned int i = 0; i < patients.size(); i++)//looping through all the patients that exist in the patients vector
		{
			cout << (i + 1) << " " << patients[i].getName() << " " << endl;//displaying the names
		}
	}


	void addnewpatient()
	{
		Patient patient;//
		patient.addPatientData();//calls the new patients function
		patients.push_back(patient);//pushes the results of the object into the patients vector(contains all patient information)
	};

	void addNewWeight()
	{
		if (patients.size() != 0)//validation to make sure that only accessable when there is a(n) patient that exists
		{
			printPersonVector();//calls the function that displays the list of all current patients

			int input;
			cin >> input;

			patients[input - 1].updateWeight();
		}
	};

	void showPatientData() {
		if (patients.size() != 0)//validation to make sure that only accessable when there is a(n) patient that exists
		{
			printPersonVector();//the function that displays all current patients
			int input;
			cin >> input;

			patients[input - 1].displayAllPatientData();
		}
		else cout << "Please create a new patient or load from a file";
	};

	void PatientBMIHistory()
	{
		if (patients.size() != 0)//validation to make sure that only accessable when there is a(n) patient that exists
		{
			printPersonVector();//the function that displays all current patients

			int input;
			cin >> input;


			patients[input - 1].patientBMIHistory();//going to the selected patients BMIhistory function
		}
		else cout << "Please create a new patient or load from a file";
	};

	void updateContact()
	{
		if (patients.size() != 0)//validation to make sure that only accessable when there is a(n) patient that exists
		{
			printPersonVector();//the function that displays all current patients

			int input;
			cin >> input;

			patients[input - 1].updatePatient();//going to the selected patients BMIhistory function
		}
		else cout << "Please create a new patient or load from a file";
	}

	void sort()
	{
		if (patients.size() != 0)//validation to make sure that only accessable when there is a(n) patient that exists
		{

			Patient patient;//making an object
			patient.getBMI();

			Patient temppatientBMI;

			//This is a bubble sort
			for (unsigned int i = 0; i < patients.size(); i++)//loop throughs all the patients 
			{
				for (unsigned int j = i + 1; j < patients.size(); j++)//making sure that this selects the patient next to the previous one
				{
					if (patients[i].getLastestBMIFromVector() < patients[j].getLastestBMIFromVector())//compares the bmi values of all the patients and sorts the accordingly, highest to lowest
					{
						temppatientBMI = patients[i];//patient location swapping within the vector
						patients[i] = patients[j];
						patients[j] = temppatientBMI;
					}

				}
			}
			printPersonVector();//displays the new list of the sorted patients
		}
		else cout << "Please create a new patient or load from a file";
	}


	void writeToFile()
	{
		ofstream outputfile;//create the outpurfile object
		Patient patient;//create a temp patient object

		outputfile.open("Patient_records.txt");//opens the folder
		outputfile << patients.size() << endl;//writes the size of the patients vector
		for (int i = 0; i < patients.size(); i++)//loops through all the patients in the patients vector
		{
			outputfile << patients[i].getName() << endl;//writes the name to the file
			outputfile << patients[i].getEmail() << endl;//writes the email to the file
			outputfile << patients[i].getPhonenumber() << endl;//writes the phonenumber to the file
			outputfile << patients[i].getHeight() << endl;//writes the height to the file
			outputfile << patients[i].getweightsize() << endl;
			int tempsize = patients[i].getweightsize();

			for (int l = 0; l < tempsize; l++)
			{
				patients[i].getweight(outputfile);
			}
		}
	};

	void loadDataFromFile()
	{
		ifstream inputfile;//created an ifstream object
		inputfile.open("Patient_records.txt");//opens the file
		string tempvar;//string that'll being constantly changed 
		float tempnumber = 0;//float thatll be constantly changed
		Patient patient;
		int NumberOfPatients = 0;
		inputfile >> NumberOfPatients;

		for (int i = 0; i < NumberOfPatients; i++)
		{
			inputfile >> tempvar;//var set to name
			patient.setname(tempvar);//set the name
			inputfile >> tempvar;//variable used for email
			patient.setEmail(tempvar);//set the email
			inputfile >> tempvar;//variable used for phonenumber
			patient.setPhonenumber(tempvar);//set the patient phonenumber

			inputfile >> tempnumber;//tempnumber set to height
			patient.setHeight(tempnumber);//go to the setheight function to set the height

			int numberOfWeights = 0;
			inputfile >> numberOfWeights;
			for (int i = 0; i < numberOfWeights; i++)
			{
				inputfile >> tempnumber;//variable used for email
				patient.setWeight(tempnumber);//set the email
			}
			patients.push_back(patient);//pushes the patien record into the patients vector
		}
	}
	void saveAndQuit()
	{
		writeToFile();//writes the information to the file
		keepMenuGoing = false;//disables the menu when it returns to the beginning
	};
public:
	void start()
	{
		while (keepMenuGoing)//makes sure that the code always comes back here to input another option
		{
			cout << "1.Create a new patient" << endl;
			cout << "2.Update patient weight" << endl;
			cout << "3.Update patient contact information" << endl;
			cout << "4.Display patient information" << endl;
			cout << "5.Show patient BMI history data" << endl;
			cout << "6.Show a list of all Patients sorted by recent BMI" << endl;
			cout << "7.Load in patient data" << endl;
			cout << "8.Save the patients details to a file and quit" << endl;


			int choice = 0;
			cin >> choice;
			switch (choice)//swithc statement with cases to select which option you'd like to choose and do
			{
			case 1:
				addnewpatient();
				break;
			case 2:
				addNewWeight();
				break;
			case 3:
				updateContact();
				break;
			case 4:
				showPatientData();
				break;
			case 5:
				PatientBMIHistory();
				break;
			case 6:
				sort();
				break;
			case 7:
				loadDataFromFile();
				break;
			case 8:
				saveAndQuit();
				break;

			}
		}
	}
};

int main()
{
	Menu m;//menu object that starts the code
	m.start();//calls the start function
}
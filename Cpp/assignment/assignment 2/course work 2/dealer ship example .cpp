#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
enum VehicleType
{
	CAR = 1,
	TRUCK = 2,
	MOTORCYCLE = 3
};

class Vehicle
{
protected:
	string make;
	string model;
	float price;
public:
	Vehicle() { make = ""; model = "", price = 0; };
	Vehicle(string make, string model, float price)
	{
		this->make = make;
		this->model = model;
		this->price = price;
	}
	virtual void inputDetails() = 0;
	virtual void displayDetails() = 0;
	virtual void writeToFile(ofstream& output) = 0;
	virtual void readFromFile(ifstream& input) = 0;
};

class Car :public Vehicle
{
private:
	int seats;
public:
	Car() { make = ""; model = ""; seats = 0; price = 0; };
	Car(string make, string model, int seats, float price) :Vehicle(make, model, price)
	{
		this->seats = seats;
	}
	void inputDetails()
	{
		cout << "Input Make" << endl;
		cin >> make;
		cout << "Input Model" << endl;
		cin >> model;
		cout << "Input Seats" << endl;
		cin >> seats;
		cout << "Input Price" << endl;
		cin >> price;
	}
	void displayDetails()
	{
		cout << "Car: " << make << " " << model << " " << seats << " " << price << endl;
	}
	void writeToFile(ofstream& output)
	{
		output << VehicleType::CAR << " " << make << " " << model << " " << seats << " " << price;
	}
	void readFromFile(ifstream& input)
	{
		input >> make;
		input >> model;
		input >> seats;
		input >> price;
	}
};

class Truck :public Vehicle
{
private:
	float weight;
public:
	Truck() { make = ""; model = ""; weight = 0; price = 0; };
	Truck(string make, string model, float weight, float price) :Vehicle(make, model, price)
	{
		this->weight = weight;
	}
	void inputDetails()
	{
		cout << "Input Make" << endl;
		cin >> make;
		cout << "Input Model" << endl;
		cin >> model;
		cout << "Input Weight" << endl;
		cin >> weight;
		cout << "Input Price" << endl;
		cin >> price;
	}
	void displayDetails()
	{
		cout << "Truck: " << make << " " << model << " " << weight << " " << price << endl;
	}
	void writeToFile(ofstream& output)
	{
		output << VehicleType::TRUCK << " " << make << " " << model << " " << weight << " " << price;
	}
	void readFromFile(ifstream& input)
	{
		input >> make;
		input >> model;
		input >> weight;
		input >> price;
	}
};

class Motorcycle :public Vehicle
{
private:
	int engineSize;
public:
	Motorcycle()
	{
		make = ""; model = ""; price = 0; engineSize = 0;
	}
	void inputDetails()
	{
		cout << "Input Make" << endl;
		cin >> make;
		cout << "Input Model" << endl;
		cin >> model;
		cout << "Input Engine Size" << endl;
		cin >> engineSize;
		cout << "Input Price" << endl;
		cin >> price;
	}
	void displayDetails()
	{
		cout << "Motorcycle: " << make << " " << model << " " << engineSize << " " << price << endl;
	}
	void writeToFile(ofstream& output)
	{
		output << VehicleType::MOTORCYCLE << " " << make << " " << model << " " << engineSize << " " << price;
	}
	void readFromFile(ifstream& input)
	{
		input >> make;
		input >> model;
		input >> engineSize;
		input >> price;
	}
};

class Dealership
{
private:
	vector<Vehicle*> vehicles;
public:
	void createVehicle()
	{
		cout << "What type?" << endl;
		cout << VehicleType::CAR << ": Car" << endl;
		cout << VehicleType::TRUCK << ": Truck" << endl;
		cout << VehicleType::MOTORCYCLE << ": Motorcycle" << endl;
		int usrInput;
		cin >> usrInput;

		switch (usrInput)
		{
		case VehicleType::CAR:
		{
			Car* car = new Car();
			car->inputDetails();
			vehicles.push_back(car);
			break;
		}
		case VehicleType::TRUCK:
		{
			Truck* truck = new Truck();
			truck->inputDetails();
			vehicles.push_back(truck);
			break;
		}
		case VehicleType::MOTORCYCLE:
		{
			Motorcycle* motorCycle = new Motorcycle();
			motorCycle->inputDetails();
			vehicles.push_back(motorCycle);
			break;
		}
		default:
			break;
		}
	}

	void listVehicles()
	{
		int i = 1;
		for (auto x : vehicles)
		{
			cout << i << ": ";
			x->displayDetails();
			i++;
		}
		cout << endl;
	}
	void writeToFile()
	{
		ofstream output("dealership.txt");
		for (int i = 0; i < vehicles.size(); i++)
		{
			if (i != 0)
			{
				output << endl;
			}
			vehicles[i]->writeToFile(output);
		}
	}

	void readFromFile()
	{
		ifstream input("dealership.txt");
		if (input)
		{
			while (!input.eof())
			{
				int vehicleType;
				input >> vehicleType;
				switch (vehicleType)
				{
				case VehicleType::CAR:
				{
					Car* car = new Car();
					car->readFromFile(input);
					vehicles.push_back(car);
					break;
				}
				case VehicleType::TRUCK:
				{
					Truck* t = new Truck();
					t->readFromFile(input);
					vehicles.push_back(t);
					break;
				}
				case VehicleType::MOTORCYCLE:
				{
					Motorcycle* mc = new Motorcycle();
					mc->readFromFile(input);
					vehicles.push_back(mc);
					break;
				}
				default:
					break;
				}
			}
		}	
	}

	void editVehicle()
	{
		cout << "Which vehicle? " << endl;
		listVehicles();
		int usrInput;
		cin >> usrInput;
		vehicles[usrInput - 1]->inputDetails();
	}
};

int main()
{
	Dealership d;
	d.readFromFile();
	while (true)
	{
		cout << "1. Enter new Vehcile" << endl;
		cout << "2. Display all Vehicles" << endl;
		cout << "3. Write to file" << endl;
		cout << "4. Edit a vehicle" << endl;

		int userInput;
		cin >> userInput;
		switch (userInput)
		{
		case 1:
		{
			d.createVehicle();
			break;
		}
		case 2:
		{
			d.listVehicles();
			break;
		}
		case 3:
		{
			d.writeToFile();
			break;
		}
		case 4:
		{
			d.editVehicle();
			break;
		}
		default:
			break;
		}
	}

}
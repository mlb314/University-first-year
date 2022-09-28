#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
using namespace std;



class MusicShop;

class Instrument
{
protected:
	string InstrumentName;
	string Make;
	string Model;
	string Notes;
	string type;
	float Price;

public:
	Instrument() { InstrumentName = ""; Make = ""; Model = ""; Notes = ""; Price = 0; type = ""; };
	Instrument(string InstrumentName, string Make, string Model, string Notes, float price, string type)
	{
		this->InstrumentName = InstrumentName;
		this->Make = Make;
		this->Model = Model;
		this->Notes = Notes;
		this->Price = price;
		this->type = type;
	}
	void addNewInstrument()
	{
		cout << "What is the name of the instrument?" << endl;
		getline(cin >> ws, InstrumentName);
		cout << endl << "What is the make of the instrument?" << endl;
		getline(cin >> ws, Make);
		cout << endl << "What is the model? " << endl;
		getline(cin >> ws, Model);

		string choice;
		cout << "Any notes about the instrument? Y/N" << endl;
		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			cout << "Notes: " << endl;
			getline(cin >> ws, Notes);
		}

	};
	string getinstrumenttype()
	{
		return type;
	}
	string getinstrumentname()
	{
		return InstrumentName;
	}
	double getinstrumentPrice()
	{
		return Price;
	};
	string getinstrumentmake()
	{
		return Make;
	}

	string getinstrumentmodel()
	{
		return Model;
	}
	string getinstrumentnotes()
	{
		return Notes;
	}


	virtual void inputDetails() = 0;
	virtual void displayDetails() = 0;
	virtual void writeToFile(ofstream& output) = 0;
	virtual void readFromFile(ifstream& input) = 0;

};

class Customer
{
	string name;
	string Address;
	string PhoneNumber;
	string Notes;

public:
	void addnewCustomer()
	{
		cout << "What is the customers name?" << endl;
		getline(cin >> ws, name);
		cout << endl << "What is the address ? " << endl;
		getline(cin >> ws, Address);
		cout << endl << "What is the phone number?" << endl;
		cin >> PhoneNumber;
		cout << endl << "Any notes from the customer? Y/N" << endl;
		string choice = "";
		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			cout << "Notes: ";
			getline(cin >> ws, Notes);
		}
		else { Notes = "N/A"; }
	}
	string getname()
	{
		return name;
	}
	string getaddress()
	{
		return Address;
	}
	string getPhonenumber()
	{
		return PhoneNumber;
	}
	string getNotes()
	{
		return Notes;
	}

	void writeToFile(ofstream& output)
	{
		output << name << endl << Address << endl << PhoneNumber << endl << Notes << endl;
	}

	void readFromFile(ifstream& input)
	{
		getline(input >>ws, name);
		getline(input >>ws, Address);
		input >> PhoneNumber;
		getline(input >> ws, Notes);
	};
};


class Accessory
{
private:
	string AccessoryName;
	double Price;
	int NumberInStock;
	string choice;
	bool stringtype = false;
	bool brasstype = false;
	bool woodwindtype = false;
	//suitable for Instruments(a vector or array of instruments the accessory is suitable for)
public:
	void addNewAccessory()
	{
		cout << "Name of the accessory? :" << endl;
		cin >> AccessoryName;
		cout << "Price of the accessory? :" << endl;
		cin >> Price;
		cout << "Number in stock? :" << endl;
		cin >> NumberInStock;
		cout << "accessory used for string? : Y/N" << endl;

		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			stringtype = true;
		}
		cout << "accessory used for Brass? : Y/N" << endl;

		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			brasstype = true;
		}
		cout << "accessory used for woodwind? : Y/N" << endl;

		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			woodwindtype = true;
		}
	}
	void displayDetails()
	{
		cout << "Accessory:" << endl;
		cout << "===================================================" << endl;
		cout << "Accessory Name: " << AccessoryName << endl;
		cout << "Accessory Price: " << Price << endl;
		cout << "Accessory Stick: " << NumberInStock << endl;
		cout << "Accessory Used for: " << endl;
		if (stringtype == true)
		{
			cout << "String" << endl;
		}
		if (brasstype == true)
		{
			cout << "Brass " << endl;
		}
		if (woodwindtype == true)
		{
			cout << "WoodWind" << endl;
		}


	}
	string getaccessoryName()
	{
		return AccessoryName;
	};
	double getaccessoryPrice() { return Price; };
	int getaccessoryStock() { return NumberInStock; };
	bool getaccessorystring() { return stringtype; };
	bool getaccessorybrass() { return brasstype; };
	bool getaccessorywoodwind() { return woodwindtype; };
	void writeToFile(ofstream& output)
	{
		output << AccessoryName << endl << Price << endl << NumberInStock << endl << stringtype << endl << brasstype << endl << woodwindtype << endl; ;


	}
	void readFromFile(ifstream& input)
	{
		input >> AccessoryName;
		input >> Price;
		input >> NumberInStock;
		input >> stringtype;
		input >> brasstype;
		input >> woodwindtype;
	}
};


class Booking
{
private:
	vector<Accessory*> accessories;
	vector<Instrument*> instruments;
	vector<Customer*> customers;
	Customer* tempcustomer;
	Instrument* tempinstrument;


	string lessonRequired;
	string Date;
	int BookingBlock;
	double QuotedPrice;
	string Notes;
	int standardRate = 25;
	int customerchoice;
	int instrumentchoice;
	string buyinginst="n";
	string buyingaccess="n";
	int selectedaccess;
	int buyingaccessquantity=0;
public:
	void addNewBooking(vector<Customer*> customers, vector<Instrument*>instruments,vector<Accessory*>accessories)
	{
		for (unsigned int i = 0; i < customers.size(); i++)
		{
			cout << (i + 1) << ". " << customers[i]->getname() << endl;
		}
		cin >> customerchoice;
		customerchoice=customerchoice-1;
		tempcustomer = customers[customerchoice];

		for (unsigned int i = 0; i < instruments.size(); i++)
		{
			cout << (i + 1) << ". " << instruments[i]->getinstrumentname() << endl;
		}
		cin >> instrumentchoice;
		instrumentchoice=instrumentchoice-1;
		tempinstrument = instruments[instrumentchoice];
		cout << "What level are you at with the instrument? :" << endl;
		cin >> lessonRequired;
		cout << "What day do you with to do with booking on? :" << endl;
		cin >> Date;
		cout << "How many weeks do you wish to book for?" << endl;
		cin >> BookingBlock;
		if (BookingBlock <= 0)
		{
			BookingBlock = 1;
		}
		cout << "Are you going to buy the instrument after the booking period?: Y/N" << endl;
	
			cin >> buyinginst;
			if (buyinginst == "Y" || buyinginst == "y")
			{
				QuotedPrice = instruments[instrumentchoice]->getinstrumentPrice() + (BookingBlock * standardRate);
			}
			else {
				QuotedPrice = (instruments[instrumentchoice]->getinstrumentPrice() / 10) + (BookingBlock * standardRate);
			}
			cout << "Are you going to buy any accessories?: Y/N" << endl;
			cin >> buyingaccess;
			if (buyingaccess == "Y" || buyingaccess == "y")
			{
				cout << "Which accessory do you wish to buy?: "<<endl;
				for (unsigned int i = 0; i < accessories.size(); i++)
				{
					cout << (i + 1) << ". " << accessories[i]->getaccessoryName()<<endl;
				}
				cin >> selectedaccess;
				selectedaccess = selectedaccess - 1;
				cout << "How many do you want to buy?";
			
				cin >> buyingaccessquantity;
				if (buyingaccessquantity <= 0)
				{
					buyingaccessquantity = 1;
				}
				QuotedPrice += accessories[selectedaccess]->getaccessoryPrice() * buyingaccessquantity;
			}
		cout << "Quoted price: $" << QuotedPrice << endl;
 	};

	void readFromFile(ifstream& input,vector<Instrument*>instruments,vector<Customer*>customers,int instrumentchoice,int customerchoice) 
	{
		tempinstrument = instruments[instrumentchoice];
		tempcustomer = customers[customerchoice];
		getline(input >>ws, lessonRequired);
		input >> Date;
		input >> BookingBlock;
		getline(input >>ws, buyinginst);
		getline(input >>ws, buyingaccess);
		input >> selectedaccess;
		input >> buyingaccessquantity;
		input >> QuotedPrice;
	}

	

	void writeinstrumentToFile(ofstream& output)
	{
		output << instrumentchoice << endl;//this only writes which instrument was chosen to the txt file
	};

	void writecustomerToFile(ofstream& output)
	{
		output << customerchoice<<endl;//this only writes which customer was chosen to the txt file
	}

	void writetheresttofile(ofstream& output)
	{//writes any additional information to the txt file.
		output << lessonRequired << endl << Date << endl << BookingBlock << endl<<buyinginst<<endl<<buyingaccess<<endl<<selectedaccess<<endl<<buyingaccessquantity<<endl<< QuotedPrice << endl;
	}


	

	Instrument* gettempinstrument()
	{
		return tempinstrument;
	}
	
	string getdate()
	{
		return Date;
	}
	double getquotedprice()
	{
		return QuotedPrice;
	}
	string getbuyinginstrument() { return buyinginst; };
	string getbuyingaccessory() { return buyingaccess; };
	int getaccessquantitiy() { return buyingaccessquantity; };
	string getnotes()
	{
		return Notes;
	}
	int getbookingblock()
	{
		return BookingBlock;
	}
	string getlessondifficulty()
	{
		return lessonRequired;
	}
	string getcustomername(int i, vector<Customer*>customers)
	{
		return customers[i]->getname();//an issue arrises if you have created more bookings than customers by here. and try to display all bookings
	}
	string getcustomeraddress(int i, vector<Customer*>customers)
	{
		return customers[i]->getaddress();
	}
	string getcustomerphonenumber(int i, vector<Customer*>customers)
	{
		return customers[i]->getPhonenumber();
	}
	string getcutstomernotes(int i, vector<Customer*>customers)
	{
		return customers[i]->getNotes();
	}
	string getinstrumentname(int i, vector<Instrument*>instruments)
	{
		return instruments[i]->getinstrumentname();
	}
	string getinstrumentmake(int i, vector<Instrument*>instruments)
	{
		return instruments[i]->getinstrumentmake();
	}
	string getinstrumentmodel(int i, vector<Instrument*>instruments)
	{
		return instruments[i]->getinstrumentmodel();
	}
	string getinstrumentnotes(int i, vector<Instrument*>instruments)
	{
		return instruments[i]->getinstrumentnotes();
	}
	double getinstrumentprice(int i, vector<Instrument*>instruments)
	{
		return instruments[i]->getinstrumentPrice();
	}
	string getinstrumenttype(int i, vector<Instrument*>instruments)
	{
		return instruments[i]->getinstrumenttype();
	}
};


class String : public Instrument
{
private:

	int NumberOfStrings;
	string TypeOfInstrument;
	string colour;
public:
	String() { TypeOfInstrument = ""; colour = ""; NumberOfStrings = 0; };
	String(string InstrumentName, string Make, string  Model, string Notes, string TypeOfInstrument, string colour, int NumberOfStrings, float Price, string type) :Instrument(InstrumentName, Make, Model, Notes, Price, type)
	{
		this->NumberOfStrings = NumberOfStrings;
		this->TypeOfInstrument = TypeOfInstrument;
		this->colour = colour;
	}

	void inputDetails()
	{
		type = "string";
		cout << "Instrument name? :" << endl;
		cin >> InstrumentName;
		cout << "Make? :" << endl;
		cin >> Make;
		cout << "Model? :" << endl;
		cin >> Model;
		cout << "Price? :" << endl;
		cin >> Price;
		cout << "Number of strings? :" << endl;
		cin >> NumberOfStrings;
		cout << "Colour(s)? :" << endl;
		getline(cin >> ws, colour);
		cout << "Type of instrument? :" << endl;
		getline(cin >> ws, TypeOfInstrument);
		cout << "Any notes about the instrument? Y/N" << endl;
		string choice;
		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			cout << "Notes: " << endl;
			getline(cin >> ws, Notes);
		}
		else
		{
			Notes = "N/A";
		}
	}
	string gettype()
	{
		return type;
	}
	int getnumberofstrings()
	{
		return NumberOfStrings;
	}
	void displayDetails()
	{
		cout << "Stringed instrument: " << endl;
		cout << "=============================================================" << endl;
		cout << "Instrument name: " << InstrumentName << endl;
		cout << "Price: " << Price << endl;
		cout << "Make: " << Make << endl;
		cout << "Model: " << Model << endl;
		cout << "Number of strings: " << NumberOfStrings << endl;
		cout << "Colour(s): " << colour << endl;
		cout << "Type of instrument: " << TypeOfInstrument << endl;
		cout << "Notes: " << Notes << endl << endl;


	}
	void writeToFile(ofstream& output)
	{
		output << "1" << endl << type << endl << InstrumentName << endl << Price << endl << Make << endl << Model << endl << NumberOfStrings << endl << colour << endl << TypeOfInstrument << endl << Notes << endl;


	}
	void readFromFile(ifstream& input)
	{
		input >> type;
		input >> InstrumentName;
		input >> Price;
		input >> Make;
		input >> Model;
		input >> NumberOfStrings;
		input >> colour;
		input >> TypeOfInstrument;
		getline(input >> ws, Notes);

	}
};

class Brass : public Instrument
{
private:
	int NumberOfValves;
	string Key;
	string Material;
	string Finish;
public:
	Brass() { Finish = ""; Material = ""; Key = ""; NumberOfValves = 0; };
	Brass(string InstrumentName, string Make, string Model, string Notes, float Price, string Finish, int NumberOfValves, string Key, string Material, string finish, string type) :Instrument(InstrumentName, Make, Model, Notes, Price, type)
	{
		this->NumberOfValves = NumberOfValves;
		this->Key = Key;
		this->Material = Material;
		this->Finish = Finish;
	}


	void inputDetails()
	{
		type = "brass";
		cout << "Instrument name? :" << endl;
		cin >> InstrumentName;
		cout << "Make? :" << endl;
		cin >> Make;
		cout << "Model? :" << endl;
		cin >> Model;
		cout << "Price? :" << endl;
		cin >> Price;
		cout << "Number of Valves? :" << endl;
		cin >> NumberOfValves;
		cout << "What key is it in? :" << endl;
		cin >> Key;
		cout << "Material the instrument is made from? :" << endl;
		cin >> Material;
		cout << "What is the instruments finish? :" << endl;
		cin >> Finish;
		cout << "Any notes about the instrument? Y/N" << endl;
		string choice;
		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			cout << "Notes: " << endl;
			getline(cin >> ws, Notes);
		}
		else
		{
			Notes = "N/A";
		}
	};
	void displayDetails()
	{
		cout << "Brass instrument: " << endl;
		cout << "=============================================================" << endl;
		cout << "Instrument name: " << InstrumentName << endl;
		cout << "Price: " << Price << endl;
		cout << "Make: " << Make << endl;
		cout << "Model: " << Model << endl;
		cout << "Number of strings: " << NumberOfValves << endl;
		cout << "Key: " << Key << endl;
		cout << "Type of Material: " << Material << endl;
		cout << "Finish: " << Finish << endl;
		cout << "Notes: " << Notes << endl << endl;

	};
	string gettype()
	{
		return type;
	}
	void writeToFile(ofstream& output)
	{
		output << "2" << endl << type << endl << InstrumentName << endl << Price << endl << Make << endl << Model << endl << NumberOfValves << endl << Key << endl << Material << endl << Finish << endl << Notes << endl;

	};
	void readFromFile(ifstream& input)
	{
		input >> type;
		input >> InstrumentName;
		input >> Price;
		input >> Make;
		input >> Model;
		input >> NumberOfValves;
		input >> Key;
		input >> Material;
		input >> Finish;
		getline(input >> ws, Notes);
	};
};

class WoodWind : public Instrument
{
private:
	int NumberOfKeys;
	string Material;
	string Key;
public:
	WoodWind() { Material = ""; Key = ""; NumberOfKeys = 0; };
	WoodWind(string InstrumentName, string Make, string Model, string Notes, float Price, int NumberOfKeys, string Key, string Material, string type) :Instrument(InstrumentName, Make, Model, Notes, Price, type)
	{
		this->NumberOfKeys = NumberOfKeys;
		this->Key = Key;
		this->Material = Material;
	}
	void inputDetails()
	{
		type = "woodwind";
		cout << "Instrument name? :" << endl;
		cin >> InstrumentName;
		cout << "Make? :" << endl;
		cin >> Make;
		cout << "Model? :" << endl;
		cin >> Model;
		cout << "Price? :" << endl;
		cin >> Price;
		cout << "Number of Keys? :" << endl;
		cin >> NumberOfKeys;
		cout << "What key is it in? :" << endl;
		cin >> Key;
		cout << "Material the instrument is made from? :" << endl;
		cin >> Material;
		cout << "Any notes about the instrument? Y/N" << endl;
		string choice;
		cin >> choice;
		if (choice == "Y" || choice == "y")
		{
			cout << "Notes: " << endl;
			getline(cin >> ws, Notes);
		}
		else
		{
			Notes = "N/A";
		}
	};
	string gettype()
	{
		return type;
	}
	void displayDetails()
	{
		cout << "WoodWind instrument: " << endl;
		cout << "=============================================================" << endl;
		cout << "Instrument name: " << InstrumentName << endl;
		cout << "Price: " << Price << endl;
		cout << "Make: " << Make << endl;
		cout << "Model: " << Model << endl;
		cout << "Number of strings: " << NumberOfKeys << endl;
		cout << "Key: " << Key << endl;
		cout << "Type of Material: " << Material << endl;
		cout << "Notes: " << Notes << endl << endl;
	};
	void writeToFile(ofstream& output)
	{
		output << "1" << endl << type << endl << InstrumentName << endl << Price << endl << Make << endl << Model << endl << NumberOfKeys << endl << Key << endl << Material << endl << Notes << endl;

	};
	void readFromFile(ifstream& input)
	{
		input >> type;
		input >> InstrumentName;
		input >> Price;
		input >> Make;
		input >> Model;
		input >> NumberOfKeys;
		input >> Key;
		input >> Material;
		getline(input >> ws, Notes);

	};
};

class MusicShop
{

private:
	bool keepMenuGoing = true;
	vector<Booking*> bookings;
	vector<Customer*> customers;
	vector<Instrument*> instruments;
	vector<Accessory*> accessories;
	double totalsales;


public:


	void createCustomer()
	{
		Customer* customer = new Customer();
		customer->addnewCustomer();
		customers.push_back(customer);

	};

	void showCustomers()
	{
		cout << "Customers: " << endl;
		for (unsigned int i = 0; i < customers.size(); i++)
		{
			cout << "--------------------------------------" << endl;
			cout << (i + 1) << " " << customers[i]->getname() << " " << endl;
			cout << "Address:" << customers[i]->getaddress() << " " << endl;
			cout << "Phone Number: " << customers[i]->getPhonenumber() << " " << endl;
			if (customers[i]->getNotes() != "")
			{
				cout << "Notes: " << customers[i]->getNotes() << " ";
			}
			cout << endl << endl;
		}
	};

	void createInstrument()
	{
		cout << "What type?" << endl;
		cout << 1 << ": String" << endl;
		cout << 2 << ": Brass" << endl;
		cout << 3 << ": WoodWind" << endl;
		int usrInput;
		cin >> usrInput;

		switch (usrInput)
		{
		case 1:
		{
			String* stringed = new String();
			stringed->inputDetails();
			instruments.push_back(stringed);
			break;
		}
		case 2:
		{
			Brass* brass = new Brass();
			brass->inputDetails();
			instruments.push_back(brass);
			break;
		}
		case 3:
		{
			WoodWind* woodwind = new WoodWind();
			woodwind->inputDetails();
			instruments.push_back(woodwind);
			break;

		}
		default:
			break;
		}

	};

	void showInstruments() {
		int i = 1;
		for (auto x : instruments)
		{
			x->displayDetails();//displaying all instruments using a for auto loop is required as instruments have inheritence.
		}
	};

	void createAccessory()
	{
		Accessory* a = new Accessory();
		a->addNewAccessory();
		accessories.push_back(a);
	};

	void showAccessories()
	{
		cout << "Accessories: " << endl;
		for (unsigned int i = 0; i < accessories.size(); i++)
		{
			cout << "--------------------------------------" << endl;
			cout << (i + 1) << " " << accessories[i]->getaccessoryName() << " " << endl;
			cout << "Price of accessory: " << accessories[i]->getaccessoryPrice() << " " << endl;
			cout << "Number of Stock:  " << accessories[i]->getaccessoryStock() << " " << endl;
			cout << "Instrument type used for: " << endl;
			if (accessories[i]->getaccessorystring() == true)
			{
				cout << "Stringed" << endl;
			}
			if (accessories[i]->getaccessorybrass() == true)
			{
				cout << "Brass" << endl;
			}
			if (accessories[i]->getaccessorywoodwind() == true)
			{
				cout << "Woodwind" << endl;
			}
			cout << endl << endl;
		}
	};

	void createBooking()
	{
		Booking* b = new Booking();
		b->addNewBooking(customers, instruments,accessories);
		bookings.push_back(b);
	};

	void showListOfBookings(int j)
	{
		cout << "Bookings: " << endl;
		for (unsigned int i = 0 + j; i < bookings.size(); i++)
		{
			displaybookings(i);
		}
	};

	void displaybookings(int i)
	{

		cout << "Bookings: " << endl;
	
		cout << (i + 1) << ". " << endl;
		cout << "-------------------------------" << endl;
		cout << "Customer Name: " << bookings[i]->getcustomername(i, customers) << endl;
		
		cout << "Quoted Price: " << bookings[i]->getquotedprice() << endl;
		cout << "Number of weeks:  " << bookings[i]->getbookingblock() << endl << endl;
		bookings[i]->gettempinstrument()->displayDetails();
		if (bookings[i]->getbuyingaccessory() == "Y" || bookings[i]->getbuyingaccessory() == "y")
		{
			accessories[i]->displayDetails();
		}
		
	}

	void listOfBookingOnSpecificDay() 
	{
		string chosendate;
		cout << "What day do you want a list of all bookings? :";
		cin >> chosendate;
		for (unsigned int i=0; i<bookings.size();i++)
			if (chosendate == bookings[i]->getdate())
			{
				displaybookings(i);
			}
	};

	void showSpecificAccessoryOrInstrument()
	{
		cout << "What are you searching for? :" << endl;
		cout << "1. Instrument name." << endl;
		cout << "2. Accessory name. " << endl;
		int choice = 0;
		int secondchoice = 0;
		int thirdchoice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			searchInstrumentName();
			break;
		case 2:
			searchAccessoryName();
			break;

		default:
			break;
		}
	};

	void searchInstrumentName()
	{
		string name;
		cout << "What is the instrument name? :" << endl;
		cin >> name;
		for (unsigned int i = 0; i < instruments.size(); i++)
		{
			string tempname = instruments[i]->getinstrumentname();
			if (name.find(tempname))
			{
				instruments[i]->displayDetails();
			}
		}
	}

	void searchAccessoryName()
	{
		string name;
		cout << "What is the Accessory name? :" << endl;
		cin >> name;
		for (unsigned int i = 0; i < accessories.size(); i++)
		{
			string tempname = accessories[i]->getaccessoryName();
			if (name.find(tempname))
			{
				accessories[i]->displayDetails();
			}
		}
	}

	void salesReport() 
	{
		for (unsigned int i = 0; i < bookings.size(); i++)
		{
			totalsales += bookings[i]->getquotedprice();
		}
		cout << "The total revenue from all bookings and purchases is: " << totalsales<<endl;
	};

	void loadFromFile()
	{
		int numberOfInstruments = 0;
		ifstream Iinput("instruments.txt");
		Iinput >> numberOfInstruments;
		for (int i = 0; i < numberOfInstruments; i++)
		{
			int instrumenttype;
			Iinput >> instrumenttype;
			switch (instrumenttype)
			{
			case 1:
			{
				String* s = new String();
				s->readFromFile(Iinput);
				instruments.push_back(s);
				break;
			}
			case 2:
			{
				Brass* b = new Brass();
				b->readFromFile(Iinput);
				instruments.push_back(b);
				break;
			}
			case 3:
			{
				WoodWind* ww = new WoodWind();
				ww->readFromFile(Iinput);
				instruments.push_back(ww);
				break;
			}
			default:
				break;
			}
		}

		int numberofcustomers = 0;
		ifstream Cinput("customers.txt");
		Cinput >> numberofcustomers;
		for (int i = 0; i < numberofcustomers; i++)
		{
			Customer* c = new Customer();
			c->readFromFile(Cinput);
			customers.push_back(c);
		}

		int numberOfAccessories = 0;
		ifstream Ainput("Accessories.txt");
		Ainput >> numberOfAccessories;
		for (int i = 0; i < numberOfAccessories; i++)
		{
			Accessory* a = new Accessory();
			a->readFromFile(Ainput);
			accessories.push_back(a);
		}

		int numberofbookings = 0;
		ifstream Binput("booking.txt");
		Binput >> numberofbookings;
		for (int i = 0; i < numberofbookings; i++)
		{
			int instchoice, custchoice;
			Binput >> instchoice;
			Binput >> custchoice;
			Booking* b = new Booking();
			b->readFromFile(Binput,instruments,customers,instchoice,custchoice);
			bookings.push_back(b);
		}
	};

	void saveAndQuit()
	{
		if (instruments.size() > 0)
		{
			ofstream output("instruments.txt");
			output << instruments.size() << endl;
			for (unsigned int i = 0; i < instruments.size(); i++)
			{

				instruments[i]->writeToFile(output);
			}
		}
		if (customers.size() > 0)
		{
			ofstream output("customers.txt");

			output << customers.size() << endl;
			for (unsigned int i = 0; i < customers.size(); i++)
			{
				customers[i]->writeToFile(output);
			}
		}
		if (accessories.size() > 0)
		{
			ofstream output("accessories.txt");
			output << accessories.size() << endl;
			for (unsigned int i = 0; i < accessories.size(); i++)
			{
				accessories[i]->writeToFile(output);
			}
		}

		if (bookings.size() > 0)
		{
			ofstream output("booking.txt");
			output << bookings.size() << endl;
			for (unsigned int i = 0; i < bookings.size(); i++)
			{
				bookings[i]->writeinstrumentToFile(output);
				bookings[i]->writecustomerToFile(output);
				bookings[i]->writetheresttofile(output);
			}
		}

		if (bookings.size() > 0)
		{
			ofstream output("SalesReport.txt");
			for (unsigned int i = 0; i < bookings.size();i++)
			{
				totalsales += bookings[i]->getquotedprice();
			}
			output << totalsales<<endl;
		}
		


		keepMenuGoing = false;
	};


	void start()
	{
		while (keepMenuGoing)//makes sure that the code always comes back here to input another option
		{
			cout << "1.Create new customer." << endl;
			cout << "2.show list of customers." << endl;
			cout << "3.Create instrument." << endl;
			cout << "4.Show list of instruments." << endl;
			cout << "5.Create accessory. " << endl;
			cout << "6.Show list of accessories." << endl;
			cout << "7.Create bookings." << endl;
			cout << "8.Show list of bookings." << endl;
			cout << "9.Show bookings on speicific day." << endl;
			cout << "10.Show Specific instrument/accessory." << endl;
			cout << "11.Produce total sales report." << endl;
			cout << "12.Load from file." << endl;
			cout << "13.Save and quit." << endl;


			int  choice = 0;
			cin >> choice;
			if (choice < 1 || choice>13)
			{
				cout << "FUCK YEAH" << endl;
				start();
			}
			else
			{
				switch (choice)//swithc statement with cases to select which option you'd like to choose and do
				{
				case 1:
					createCustomer();
					break;
				case 2:
					showCustomers();
					break;
				case 3:
					createInstrument();
					break;
				case 4:
					showInstruments();
					break;
				case 5:
					createAccessory();
					break;
				case 6:
					showAccessories();
					break;
				case 7:
					createBooking();
					break;
				case 8:
					showListOfBookings(0);
					break;
				case 9:
					listOfBookingOnSpecificDay();
					break;
				case 10:
					showSpecificAccessoryOrInstrument();
					break;
				case 11:
					salesReport();
					break;
				case 12:
					loadFromFile();
					break;
				case 13:
					saveAndQuit();
					break;

				}
			}
		}
	}
};

int main()
{
	MusicShop ms;//menu object that starts the code
	ms.start();//calls the start function
}
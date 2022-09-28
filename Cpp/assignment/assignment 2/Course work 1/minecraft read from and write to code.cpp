#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Item
{
private:
	string name;
	int value;
	string material;
public:
	Item() { value = 0; };
	Item(string name, int value, string material)
	{
		this->name = name;
		this->value = value;
		this->material = material;
	}
	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Value: " << value << endl;
		cout << "Material: " << material << endl<<endl;
	}
	void writeToFile(ofstream& outputfile)
	{
		outputfile << name << endl;
		outputfile << value << endl;
		outputfile << material << endl;
	}
	void readFromFile(ifstream& inputfile)
	{
		getline(inputfile, name);
		inputfile >> value;
		inputfile.ignore(1000, '\n');
		inputfile.clear();
		getline(inputfile, material);
	}
};

class Character
{
private:
	string name;
	int level;
	vector<Item> items;
public:
	Character() { level = 0; };
	Character(string name, int level, vector<Item> items)
	{
		this->name = name;
		this->level = level;
		this->items = items;
	}

	void display()
	{
		cout << "name: " << name << endl;
		cout << "level: " << level << endl;
		cout << "--------------------------------" << endl;
		cout << "Items:" << endl;		
		for (auto x : items)
		{
			x.display();
		}
	}
	void writeToFile(ofstream &outputfile)
	{
		outputfile << name << endl;
		outputfile << level << endl;
		outputfile << items.size() << endl;
		for (auto x : items)
		{
			x.writeToFile(outputfile);
		}
	}
	void readFromFile(ifstream& inputfile)
	{
		int numberOfItems;
		getline(inputfile, name);
		inputfile >> level;
		inputfile >> numberOfItems;
		inputfile.ignore(1000, '\n');
		inputfile.clear();
		for (int i = 0; i < numberOfItems; i++)
		{
			Item item;
			item.readFromFile(inputfile);
			items.push_back(item);
		}		
	}
};

class InventoryManager
{
private:
	vector<Character> characters;
public:
	InventoryManager() {};
	InventoryManager(vector<Character> characters)
	{
		this->characters = characters;
	}

	void display()
	{
		for (auto x : characters)
		{ 
			cout << "Character: " << endl;
			x.display();
			cout << "************************************" << endl;
		}
		
	}

	void writeToFile()
	{
		ofstream outputfile("inventory.txt");
		outputfile << characters.size() << endl;
		for (auto x : characters)
		{
			x.writeToFile(outputfile);
		}
	}
	
	void readFromFile()
	{
		ifstream inputfile("inventory.txt");
		int numberOfCharacters;
		inputfile >> numberOfCharacters;
		inputfile.ignore(1000, '\n');
		inputfile.clear();
		for (int i = 0; i < numberOfCharacters; i++)
		{
			Character c;
			c.readFromFile(inputfile);
			characters.push_back(c);
		}
	}
};

int main()
{
	Item pickaxe("Pickaxe", 10, "Diamond");
	Item sword("sword", 5, "Iron");
	Item ironOre("Iron Ore", 1, "Iron");
	Item coal("Coal", 1, "Coal");
	Item bow("Bow", 7, "Wood");
	Item shovel("Shovel", 4, "Stone");
	Item torch("Torch", 2, "Word");
	Item diamondSword("Diamond Sword", 5, "Diamond");

	Character steve("Steve", 10, { pickaxe,sword,shovel,ironOre,bow });
	Character alex("Alex", 12, { ironOre,coal,bow,torch,diamondSword,pickaxe });
	InventoryManager im({ steve,alex });

	im.writeToFile();

	InventoryManager im2;
	im2.readFromFile();

	im2.display();
}
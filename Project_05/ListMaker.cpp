#include "stdafx.h"
#include "ListNode.h"
#include "LinkedList.h"
#include "FileMaster.h"

//prototypes
void mainMenu(std::string &name);
void displayMainMenu();
int getSelection();
void listMenu(static std::string name, FileMaster * file);
void displayListMenu();
void addMenu(LinkedList &list);
void displayAddMenu();
void removeMenu(LinkedList &list);
void displayRemoveMenu();

int main()
{
	//variables
	std::string name;		//name of the list

	//display the main menu
	mainMenu(name);

	//create the file object
	FileMaster file(name);

	//display the list menu
	listMenu(name, &file);

	return 0;
}

//displays the menu and options
void mainMenu(std::string &name)
{
	//display the menu text
	displayMainMenu();

	//keep the main menu options up until the user selects one
	bool menuLoop(true);

	do {
		//get the user's menu selection
		int selection = getSelection();

		switch (selection)
		{
		case(1):
			//get the new name from the user
			std::cout << "Enter the name for the new list: ";
			std::cin.ignore();
			std::getline(std::cin, name);
			menuLoop = false;
			break;
		case(2):
			//prompt for the name of the file that holds our existing list
			std::cout << "Enter the name of the file (excluding extension): ";
			std::cin.ignore();
			std::getline(std::cin, name);
			name = name + ".txt";
			menuLoop = false;
			break;
		case(3):
			displayMainMenu();
			break;
		case(4):
			exit(0);
			break;
		}
	} while (menuLoop);
}

//display the main menu text
void displayMainMenu()
{
	//display the main menu of the program
	std::cout << "----- List Editor v1 -----\n"
		<< "--------------------------\n"
		<< "(1) Create new list ------\n"
		<< "(2) Modify existing list -\n"
		<< "(3) Redisplay menu -------\n"
		<< "(4) Exit -----------------\n"
		<< "--------------------------\n";
}

//get the user's menu selection
int getSelection()
{
	bool isInput(false);
	int selection(0); //used to store the user's menu selection

	do {
		//prompt the user to chose a menu option
		std::cout << "Please select an option: ";
		
		std::cin >> selection;

		if (!std::cin)
		{
			std::cerr << "Invalid input!";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max());			
			isInput = false;
		}
		else
			isInput = true;
	} while (!isInput);

	return selection;
}

//list menu for editing the currently open list
void listMenu(static std::string name, FileMaster * file)
{
	//create a LinkedList using the name variable
	LinkedList list(name);
	//fill the list with the values from the file
	file->readFile(list);

	//display the listMenu
	displayListMenu();

	//keeps the program in editing mode while true
	bool keepEdit(true);

	do {		

		int selection = getSelection();
		std::string input("");

		switch (selection)
		{
		case(1):
			addMenu(list);
			keepEdit = true;
			break;
		case(2):
			removeMenu(list);
			keepEdit = true;
			break;
		case(3):
			list.printList();
			keepEdit = true;
			break;
		case(4):
			displayListMenu();
			keepEdit = true;
			break;
		case(5):
			file->writeFile(&list);
			keepEdit = false;
			break;
		}

	} while (keepEdit);
}

//display the list menu text
void displayListMenu()
{	
	std::cout << "\n----- List Menu -----\n"
		<< "--------------------------\n"
		<< "(1)- Add Item ------------\n"
		<< "(2)- Remove Item ---------\n"
		<< "(3)- Print List ----------\n"
		<< "(4)- Redisplay Menu ------\n"
		<< "(5)- Save and Exit -------\n"
		<< "--------------------------\n";		
}

//menu to add items to the list
void addMenu(LinkedList &list)
{
	//display the add menu text
	displayAddMenu();

	bool keepAdding(true);

	do {
		//get the user's menu selection
		int selection = getSelection();
		std::string input("");

		switch (selection)
		{
		case(1):
			std::cout << "Enter value to be added: ";
			std::cin.ignore();
			std::getline(std::cin, input);
			list.addFront(input);
			keepAdding = true;
			break;
		case(2):
			std::cout << "Enter value to be added: ";
			std::cin.ignore();
			std::getline(std::cin, input);
			list.addBack(input);
			keepAdding = true;
			break;
		case(3):
			displayAddMenu();
			keepAdding = true;
			break;
		case(4):
			displayListMenu();
			keepAdding = false;
			break;
		}

	} while (keepAdding);
}

//display the add menu
void displayAddMenu()
{
	std::cout << "\n----- Add Menu -----\n"
		<< "--------------------------\n"
		<< "(1) Add Item to begining -\n"
		<< "(2) Add Item to end ------\n"
		<< "(3) Redisplay Menu -------\n"
		<< "(4) Return to List Menu --\n"
		<< "--------------------------\n";
}

//menu to remove items from the list
void removeMenu(LinkedList &list)
{
	//display the add menu text
	displayRemoveMenu();

	bool keepRemoving(true);

	do {
		//get the user's menu selection
		int selection = getSelection();
		std::string input("");

		switch (selection)
		{
		case(1):
			list.removeFirst();
			keepRemoving = true;
			break;
		case(2):
			list.removeLast();
			keepRemoving = true;
			break;
		case(3):
			std::cout << "Enter value to be removed: ";
			std::cin.ignore();
			std::getline(std::cin, input);
			list.removeValue(input);
			keepRemoving = true;
			break;
		case(4):
			displayRemoveMenu();
			keepRemoving = true;
			break;
		case(5):
			displayListMenu();
			keepRemoving = false;
			break;
		}

	} while (keepRemoving);
}

//display the remove menu
void displayRemoveMenu()
{
	std::cout << "\n----- Remove Menu -----\n"
		<< "--------------------------\n"
		<< "(1) Remove first item ----\n"
		<< "(2) Remove last item -----\n"
		<< "(3) Remove item  by name -\n"
		<< "(4) Redisplay Menu -------\n"
		<< "(5) Return to List Menu --\n"
		<< "--------------------------\n";
}
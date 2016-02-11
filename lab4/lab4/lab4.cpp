// file lab4.cpp
// Runs the program using only the StoreManager class
// Author: Blong Thao

#include "storemanager.h"

int main()
{
	// reads in each file
	ifstream infile1("data4movies.txt");
	ifstream infile2("data4customers.txt");
	ifstream infile3("data4commands.txt");

	// checks if the file exists
	if (!infile1 || !infile2 || !infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	StoreManager store("Many Overzealous Videos Ignite & Entertain");
	store.buildInventory(infile1);      // fills the inventory for the store
	store.createAccounts(infile2);      // fills the accounts for the store
	store.runCommands(infile3);         // executes commands given in file

	return 0;
}

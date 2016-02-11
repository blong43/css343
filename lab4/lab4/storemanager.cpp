//  file storemanager.cpp
//  Function definitions for the StoreManager class
//  Authors: Blong Thao

#include "storemanager.h"

//-----------------------------------------------------------------------------
// Constructor
// Creates a StoreManager objectand initializes the store's name with the param

StoreManager::StoreManager(const string theStore) {
	storeName = theStore;
}

//-----------------------------------------------------------------------------
// Destructor
// Nothing to free, memory allocations that are made will be freed later

StoreManager::~StoreManager() {}

//-----------------------------------------------------------------------------
// buildInventory
// Creates the movies and stores them into the inventory container

void StoreManager::buildInventory(istream& infile) {
	// generate movies from data in the infile param until the end of file
	for (;;) {
		// reads in the first letter to determine which bucket drop the info in
		infile >> movieCode;
		if (infile.eof()) break;

		// create the product, if it meets the hash criteria
		Product* ptr = pFactory.createObject(movieCode, infile);

		// when ptr has an object, not NULL, then insert it into the inventory
		if (ptr != NULL) {
			// set the data into one of the criterias, C, D, F
			ptr->setData(infile);

			// inserts into the inventory
			bool success = 
		    inventory[pFactory.getLocation(movieCode)].insert(ptr, MAX_COPIES);

			// delete the ptr if it was a duplicate
			if (!success)
				delete ptr;
		}	
	}
}

//-----------------------------------------------------------------------------
// createAccounts
// Creates the customer accounts and stores them into accounts container

void StoreManager::createAccounts(istream& infile) {
	// creates the accounts for incoming customers, in the text file
	for (;;) {
		// makes a new customer, and sets their data
		Customer* ptr = new Customer();
		ptr->setData(infile);
		
		// will always initialize customers even at the end of file, frees it
		if (infile.eof()) {
			delete ptr;
			ptr = NULL;
			break;
		}

		if (ptr->getID() > MIN_NUM && ptr->getID() < MAX_NUM) {
			// inserts the new customer into the accounts table
			accounts[ptr->getID()] = *ptr;
		}
		delete ptr;
		ptr = NULL;
	}
}

//-----------------------------------------------------------------------------
// runCommands
// Reads in all the commands and store them into history
// Also can display inventory with 'S' and history with 'H'

void StoreManager::runCommands(istream& infile) {
	// temporary variables that hold each type of code, customerID
	char cmdCode = ' ', movieCode = ' ', mediaCode = ' ';
	int custID = 0;
	
	bool found = false;             // retrieving customers from the tree 
	bool foundCust = false;         // check if customer is in accounts
	string mediaType = "", temp;    // media type, and temp = discarded text
	Customer* tempCust = NULL;      // pointer to a temporary customer
	Product* movieLoc = NULL;       // pointer to the movie location
	Product* tempMovie = NULL;      // pointer to a temporary movie

	// reads in the infile txt until the end-of-file
	for (;;) {
		infile >> cmdCode;

		if (infile.eof()) break;

		// when the command code is 'S', display inventory
		if (cmdCode == 'S')
			display();
		// otherwise, create and store new commands
		else {
			// a new command
			Command* newCmdPtr = cFactory.createObject(cmdCode, infile);

			if (newCmdPtr != NULL) {
				infile >> custID;
				if (infile.eof()) break;

				// boolean: check if customer is already in the system
				if (custID > MIN_NUM && custID < MAX_NUM)
					foundCust = true;

				// customer is found, now store commands in the history section
				if (foundCust) {

					// pointer to the customer
					tempCust = &accounts[custID];

					// if its a history command, it will display the history
					bool isHist = newCmdPtr->storeCommand
						(mediaType, movieLoc, tempCust);

					// not a history command, keep reading the file
					if (isHist) {
						infile >> mediaCode;
						mediaType = pFactory.getMediaType(mediaCode);

						// has a media type
						if (mediaType != "") {
							infile >> movieCode;

							// created a new object of a movie
							tempMovie = pFactory.createObject
								(movieCode, infile);

							// there is a movie, keep reading the file
							if (tempMovie != NULL) {
								// reads the file and sets it this way
								tempMovie->setCmdData(infile);

								// retrieves the movie from the inventory
								found = inventory[pFactory.getLocation
								   (movieCode)].retrieve(*tempMovie, movieLoc);

								// not found, its not the right movie
								if (!found) {
									cout << "Invalid Movie: " 
									     << tempMovie->getProd() << endl;
								}
								delete tempMovie;
								tempMovie = NULL;

								// used for the insertion of a command
								newCmdPtr->storeCommand
									(mediaType, movieLoc, tempCust);

								// store the command into history
								if (found && mediaType != "")
									accounts[custID].appendCommand(*newCmdPtr);
								delete newCmdPtr;
								newCmdPtr = NULL;
							} // end if
							else { // tempMovie == NULL
								cout << "Genre: " << movieCode << " not found"
									 << endl;
								freeCmdPtr(newCmdPtr);
							}
						} // end 'if'
						else { // mediaType == ""
							cout << "Invalid Media Code: "
								 << mediaCode << endl;							
							freeCmdPtr(newCmdPtr);
							getline(infile, temp, '\n');
						}
					} // end 'if'
					else // !hist
						freeCmdPtr(newCmdPtr);
				} // end 'if'
				else { // !foundCust
					cout << "Customer ID: " << custID
						 << " not found" << endl;
					freeCmdPtr(newCmdPtr);
					getline(infile, temp, '\n');
				}
			} // end 'if'
			else { // newCmdPtr == NULL
				cout << "Command Code: " << cmdCode
					 << " not found" << endl;
				freeCmdPtr(newCmdPtr);
			}
		} // end 'if'

		// resets the variables for the next line in the text file
		found = foundCust = false;
		custID = 0;
		movieLoc = tempMovie = NULL;
	}
}

//-----------------------------------------------------------------------------
// display
// Prints the header and the inventory

void StoreManager::display() const {
	// the store header
	cout << endl << storeName << " (MOVIE)\n"
		<< "--------------------------------------------------------------\n";


	// displays the inventory, movies
	for (int i = 0; i < MAX_TYPES; i++) {
		// only displays the inventory spots that are not empty
		if (!inventory[i].isEmpty())
			cout << inventory[i];
	}
}

//-----------------------------------------------------------------------------
// freeCmdPtr
// Frees the command pointer to prevent memory leaks

void StoreManager::freeCmdPtr(Command* ptr) const {
	// free if ptr is not NULL
	if (ptr != NULL) {
		delete ptr;
		ptr = NULL;
	}
}

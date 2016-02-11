// file history.cpp
// Function definitions for the History Class
// Author: Blong Thao

#include "history.h"

//-----------------------------------------------------------------------------
// Default Constructor
// Initialize the command type

History::History() {
	commandType = "History";
}

//-----------------------------------------------------------------------------
// Destructor
// Frees something

History::~History() {
}

//-----------------------------------------------------------------------------
// create
// makes a history object

Command* History::create() const {
	return new History();
}

//-----------------------------------------------------------------------------
// storeCommand
// displays the history of a customer, does not store a command

bool History::storeCommand(string media, Product* theProd, Customer* cust) {
	// calls a customer function to display the history
	cust->printHistory();
	return false;
}

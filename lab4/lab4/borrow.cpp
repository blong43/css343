// file borrow.cpp
// Function definitions for the Borrow Class
// Author: Blong Thao

#include "borrow.h"

//-----------------------------------------------------------------------------
// Default Constructor
// Initialize the commandType

Borrow::Borrow() {
	commandType = "Borrow";
}

//-----------------------------------------------------------------------------
// Destructor
// Frees stuff (nothing)

Borrow::~Borrow() {
}

//-----------------------------------------------------------------------------
// create
// Instantiates a borrow object and returns it

Command* Borrow::create() const {
	return new Borrow();
}

//-----------------------------------------------------------------------------
// storeBorrow
// sets the mediaType and product, but also decrements the copies by one
// and if amount in doesn't change for that product then there are no copies

bool Borrow::storeCommand(string media, Product* theProd, Customer* cust) {
	// product ptr is pointing to something, set the data
	if (theProd != NULL) {
		mediaType = media;
		aProduct = theProd;

		// mediaType is something, reduce copies by one and check for change
		if (mediaType != "") {
			// holds the current amount for checking later
			int curAmountIn = aProduct->getAmountIn();
			aProduct->decreaseCopies();	

			// checks if the amount in changed, if not then there are no copies
			if (aProduct->getAmountIn() == curAmountIn) {
				cout << "Copies IN: No more copies for '" 
					 << aProduct->getProd() << "'" << endl;
			}
		}
	}
	return true;
}

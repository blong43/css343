// file return.cpp
// Function definitions for the Return Class
// Author: Blong Thao

#include "return.h"

//-----------------------------------------------------------------------------
// Default Constructor
// Initializes the command type

Return::Return() {
	commandType = "Return";
}

//-----------------------------------------------------------------------------
// Destructor
// Does nothing

Return::~Return() {
}

//-----------------------------------------------------------------------------
// create
// instantiates a return object

Command* Return::create() const {
	return new Return();
}

//-----------------------------------------------------------------------------
// storeReturn
// sets the mediaType and product, but also increments the copies by one
// and if amount in doesn't change for that product then at max capacity

bool Return::storeCommand(string media, Product* theProd, Customer* cust) {
	// product ptr is pointing to something, set the data
	if (theProd != NULL) {
		mediaType = media;
		aProduct = theProd;

		// mediaType is something, reduce copies by one and check for change
		if (mediaType != "") {
			// holds the current amount for checking later
			int curAmountIn = aProduct->getAmountIn();
			aProduct->increaseCopies();
			
			// checks if the amount in changed, if not then there are no copies
			if (aProduct->getAmountIn() == curAmountIn) {
				cout << "Copies IN: At maximum capacity '"
					 << aProduct->getProd() << "'" << endl;
			}
		}

	}
	return true;
}

// file product.cpp
// Function definitions for the Product class
// Author: Blong Thao

#include "product.h"

//-----------------------------------------------------------------------------
// Constructor
// Assigns default values to the max and current amount of copies

Product::Product() {
	maxCopies = 0;
	amtOfCopies = -1;
}

//-----------------------------------------------------------------------------
// Destructor
// Used to delete the strings properly

Product::~Product() {}

//-----------------------------------------------------------------------------
// setMaxCopy
// sets the maximum amount of copies

void Product::setMaxCopy(const int newMax) {
	maxCopies = newMax;

	if (amtOfCopies < 0)
		amtOfCopies = maxCopies;
}

//-----------------------------------------------------------------------------
// increaseCopies
// increment the copies by one

void Product::increaseCopies() {
	if (amtOfCopies <= maxCopies)
		amtOfCopies++;
}

//-----------------------------------------------------------------------------
// decreaseCopies
// decrement the copies by one

void Product::decreaseCopies() {
	if (amtOfCopies <= maxCopies && amtOfCopies > NONE)
		amtOfCopies--;
}

//-----------------------------------------------------------------------------
// getAmountIn
// return the number of copies checked-in

int Product::getAmountIn() const {
	return amtOfCopies;
}

//-----------------------------------------------------------------------------
// getAmountOut
// return the number of copies checked-out

int Product::getAmountOut() const {
	return maxCopies - amtOfCopies;
}

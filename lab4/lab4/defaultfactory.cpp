// file productfactoy.cpp
// Function definitions for the DefaultFactory class
// Author: Blong Thao

#include "defaultfactory.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class

DefaultFactory::DefaultFactory() {}

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion

DefaultFactory::~DefaultFactory() {}

//-----------------------------------------------------------------------------
// getLocation
// Returns the subscript of the location that ch would belong

int DefaultFactory::getLocation(char ch) const {
	return hash(ch);
}

//-----------------------------------------------------------------------------
// hash
// hashes the param to put it into a hashtable of size 26, returns an integer

int DefaultFactory::hash(char ch) const {
	return ch - 'A';
}


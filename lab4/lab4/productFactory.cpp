// file productfactoy.cpp
// Function definitions for the ProductFactory class
// Author: Blong Thao

#include "productfactory.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class

ProductFactory::ProductFactory() : DefaultFactory() {
	// initialize hashtable to null pointers to avoid garbage
	for (int i = 0; i < MAX_TYPES; i++) {
		productTypes[i] = NULL;
		mediaFormat[i] = "";
	}
	// creates new product objects
	productTypes[2] = new Classic();
	productTypes[3] = new Drama();
	productTypes[5] = new Comedy();

	mediaFormat[3] = "DVD";
}

//-----------------------------------------------------------------------------
// Destructor
// Frees memory allocation inside the product types hash table

ProductFactory::~ProductFactory() {
	for (int i = 0; i < MAX_TYPES; i++) {
		if (productTypes[i] != NULL) {
			delete productTypes[i];
			productTypes[i] = NULL;
		}
	}
}

//-----------------------------------------------------------------------------
// createObject
// Makes a ProductFactory object, which returns as a Product pointer.

Product* ProductFactory::createObject(char ch, istream& infile) {
	int subscript = hash(ch);

	// removes the infile lines that contain invalid movie code
	if (productTypes[subscript] == NULL) {
		string temp;
		getline(infile, temp, '\n');
		return NULL;
	}
	// creates the object from the right spot in the hashtable
	else
		return productTypes[subscript]->create();
}

//-----------------------------------------------------------------------------
// getMediaType
// Makes a ProductFactory object, which returns as a Product pointer.

string ProductFactory::getMediaType(char ch) const {
	return mediaFormat[hash(ch)];
}

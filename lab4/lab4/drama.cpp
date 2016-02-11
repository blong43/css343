// file drama.cpp
// Function definitions for the Drama class
// Author: Blong Thao

#include "drama.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class

Drama::Drama() : Movie() { 
	director = title = "";
	genre = "DRAMA";
	year = 0;
}

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion

Drama::~Drama() {}

//-----------------------------------------------------------------------------
// create
// Makes a Drama object, which returns as a Product pointer.

Product* Drama::create() const {
	return new Drama();
}

//-----------------------------------------------------------------------------
// setCmdData
// Sets the class's data members to the infile text;
// but for the command data, title and year only

void Drama::setCmdData(istream& infile) {
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');
}

//-----------------------------------------------------------------------------
// operator<
// Checks to see which object is smaller, that way the program can sort
// the objects correctly into the BST

bool Drama::operator<(const Product& rhs) const {
	// casting the Product 'rhs' over to a Drama type
	const Drama& dramaMovie = static_cast<const Drama&>(rhs);

	// lhs title is shorter than rhs, return true
	if (director < dramaMovie.director)
		return true;
	// lhs title is equal to rhs, return depends which year is smaller
	else if (director == dramaMovie.director)
		return title < dramaMovie.title;
	// lhs title is larger than rhs, return false
	else
		return false;
}

//-----------------------------------------------------------------------------
// operator==
// Checks to see which object is ==, that way the program can sort
// the objects correctly into the BST

bool Drama::operator==(const Product& rhs) const {
	// casting the Product 'rhs' over to a Drama type
	const Drama& dramaMovie = static_cast<const Drama&>(rhs);

	// both title and year are equal, return true, otherwise, return false
	return (title == dramaMovie.title) && (director == dramaMovie.director);
}

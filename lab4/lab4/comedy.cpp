// file comedy.cpp
// Function definitions for the Comedy class
// Author: Blong Thao

#include "comedy.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class

Comedy::Comedy() : Movie() {
	director = title = "";
	genre = "COMEDY";
	year = 0;
}

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion

Comedy::~Comedy() {}

//-----------------------------------------------------------------------------
// create
// Makes a Comedy object, which returns as a Product pointer.

Product* Comedy::create() const {
	return new Comedy();
}

//-----------------------------------------------------------------------------
// setCmdData
// Sets the class's data members to the infile text;
// but for the command data, title and year only

void Comedy::setCmdData(istream& infile) {
	infile.get();
	getline(infile, title, ',');
	infile >> year;
}

//-----------------------------------------------------------------------------
// operator<
// Checks to see which object is smaller, that way the program can sort
// the objects correctly into the BST

bool Comedy::operator<(const Product& rhs) const {

	// casting the Product 'rhs' over to a Comedy type
	const Comedy& comedyMovie = static_cast<const Comedy&>(rhs);

	// lhs title is shorter than rhs, return true
	if (title < comedyMovie.title)
		return true;
	// lhs title is equal to rhs, return depends which year is smaller
	else if (title == comedyMovie.title)
		return year < comedyMovie.year;
	// lhs title is larger than rhs, return false
	else
		return false;
}

//-----------------------------------------------------------------------------
// operator==
// Checks to see which object is ==, that way the program can sort
// the objects correctly into the BST


bool Comedy::operator==(const Product& rhs) const {

	// casting the Product 'rhs' over to a Comedy type
	const Comedy& comedyMovie = static_cast<const Comedy&>(rhs);

	// both title and year are equal, return true, otherwise, return false
	return (title == comedyMovie.title) && (year == comedyMovie.year);
}

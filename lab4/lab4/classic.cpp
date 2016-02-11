// file classic.cpp
// Function definitions for the Classic class
// Author: Blong Thao

#include "classic.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class

Classic::Classic() : Movie() { 
	director = title = actorFirst =	actorLast = "";
	month = year = 0;
	genre = "CLASSIC";
}

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion

Classic::~Classic() {}

//-----------------------------------------------------------------------------
// setData
// Sets the class's data members to the infile text;
// director, title, actor, and year

void Classic::setData(istream& infile) {

	infile.get();
	getline(infile, director, ',');
   
	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> actorFirst >> actorLast;  // input star's name
	infile >> month >> year;
}

//-----------------------------------------------------------------------------
// setCmdData
// Sets the class's data members to the infile text;
// but for the command data, date and famous actor only

void Classic::setCmdData(istream& infile) {
	infile >> month >> year >> actorFirst >> actorLast;
}

//-----------------------------------------------------------------------------
// display
// Displays one line of the title, director, and year

void Classic::display() const {
	cout << left << setw(22) << title.substr(0, MAX_CHARS_TITLE) 
		<< setw(16) << director.substr(0, MAX_CHARS_DIRECTOR) 
		<< setw(5) << year << right << setw(2) << month << "  " << left
		<< actorFirst << " " << actorLast << endl;
}

//-----------------------------------------------------------------------------
// displayHeader
// For displaying categories of movies, when the subclass does not override, 
// this will be used since all movies have these data sets

void Classic::displayHeader() const {
	cout << genre << endl << "*IN* *OUT*" << endl
         << "DVD  DVD TITLE                 DIRECTOR        "
		 << "YEAR MO  ACTOR" << endl;
}

//-----------------------------------------------------------------------------
// create
// Makes a Classic object, which returns as a Product pointer.

Product* Classic::create() const {
	return new Classic();
}

//-----------------------------------------------------------------------------
// operator<
// Checks to see which object is smaller, that way the program can sort
// the objects correctly into the BST

bool Classic::operator<(const Product& rhs) const {

	// casting the Product 'rhs' over to a Classic type
	const Classic& classicMovie = static_cast<const Classic&>(rhs);

	// when year is smaller than rhs, return true
	if (year < classicMovie.year)
		return true;
	
	//when month is smaller than rhs, while both year are equal, return true
	else if ((month < classicMovie.month) && (year == classicMovie.year))
		return true;

	// when month and year are both eqaul to rhs, check the actor's name
	else if ((month == classicMovie.month) && (year == classicMovie.year)) {
		
		// when actor's last name is smaller than rhs, return true
		if (actorFirst < classicMovie.actorFirst)
			return true;

		// when actor's last name is equal to rhs, return depends on first name
		else if (actorLast == classicMovie.actorLast)
			return (actorFirst < classicMovie.actorFirst);
		
		// actor's last name was larger than rhs, return false
		else
			return false;
	}
	// month and year was larger than rhs, return false
	else
		return false;
}

//-----------------------------------------------------------------------------
// operator==
// Checks to see which object is ==, that way the program can sort
// the objects correctly into the BST

bool Classic::operator==(const Product& rhs) const {

	// casting the Product 'rhs' over to a Classic type
	const Classic& classicMovie = static_cast<const Classic&>(rhs);

	// actor name and date are equal, return true, otherwise, return false
	return (year == classicMovie.year && month == classicMovie.month && 
		actorFirst == classicMovie.actorFirst && 
		actorLast == classicMovie.actorLast);
}

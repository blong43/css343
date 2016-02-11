// file movie.h
// Function definitions for the Movie class
// Authors: Blong Thao

#include "movie.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class

Movie::Movie() { 
	director = title = genre = "";
	year = 0;
}

//-----------------------------------------------------------------------------
// Destructor
// Enables proper deletion

Movie::~Movie() {}

//-----------------------------------------------------------------------------
// setData
// sets the classes data to the input file reads

void Movie::setData(istream& infile) {

	infile.get();
	getline(infile, director, ',');
   
	infile.get();
	getline(infile, title, ',');
   
	infile.get();
	infile >> year;
}

//-----------------------------------------------------------------------------
// display
// Displays one line of the title, director, and year

void Movie::display() const {
	cout << left << setw(22) << title.substr(0, MAX_CHARS_TITLE) 
		<< setw(16) << director.substr(0, MAX_CHARS_DIRECTOR) 
		<< setw(5) << year << endl;
}

//-----------------------------------------------------------------------------
// displayHeader
// For displaying categories of movies, when the subclass does not override, 
// this will be used since all movies have these data sets

void Movie::displayHeader() const {
	cout << genre << endl << "*IN* *OUT*" << endl
         << "DVD  DVD TITLE                 DIRECTOR        YEAR" << endl;
}

//-----------------------------------------------------------------------------
// getProd
// Returns the title of the movie

string Movie::getProd() const {
	return title;
}

//-----------------------------------------------------------------------------
// getDirector
// Returns a string 'director'

string Movie::getDirector() const {
	return director;
}

//-----------------------------------------------------------------------------
// getTitle
// Returns a string 'title'

string Movie::getTitle() const {
	return title;
}

//-----------------------------------------------------------------------------
// create
// Returns an integer 'year'

int Movie::getYear() const {
	return year;
}

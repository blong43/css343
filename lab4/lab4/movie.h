/*-----------------------------------------------------------------------------
  file movie.h
  Pure virtual Movie class that keeps track of director, title, and year
  Authors: Blong Thao

  Implementation:
    -- Adds director, title, and year of release on top of name
    -- Still pure virtual for some function, defined later by child classes
	-- Contains some default functions to be used by child classes
-----------------------------------------------------------------------------*/

#pragma once

#include "product.h"

class Movie : public Product {

public:
	// Constructors
	Movie();
	virtual ~Movie();

	// sets the data from a file of movies
	virtual void setData(istream&);
	// sets the data from a file of commands
	virtual void setCmdData(istream&) = 0;
	// the two displays that output the inventory
	virtual void display() const;
	virtual void displayHeader() const;
	// makes the object
	virtual Product* create() const = 0;
	// check for smaller than and equal to between products, for the BST
	virtual bool operator<(const Product&) const = 0;
	virtual bool operator==(const Product&) const = 0;
	// gets the product title
	virtual string getProd() const;

	// getters
	string getDirector() const;
	string getTitle() const;
	int getYear() const;

protected:
	static const int MAX_CHARS_TITLE = 21;    // max length to display
	static const int MAX_CHARS_DIRECTOR = 15; // max length to display

	string director, title, genre;            // the needed variables
	int year;
};

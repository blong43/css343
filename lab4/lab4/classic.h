/*-----------------------------------------------------------------------------
  file classic.h
  Specific movie class for movies belonging to the Classic category.
  Authors: Blong Thao

  Implementation:
    -- Adds members for release month and famous actor
    -- Classics are represented by a ‘C’
	-- Sorted by release date and then famous actor.
-----------------------------------------------------------------------------*/

#pragma once

#include "movie.h"

class Classic : public Movie {

public:
	// Constructors
	Classic();
	~Classic();

	// the two different setData funcs for different text file reads
    virtual void setData(istream&);
	virtual void setCmdData(istream&);
	// displays for body and header
	virtual void display() const;
	virtual void displayHeader() const;
	// creates the Classic object
	virtual Product* create() const;
	virtual bool operator<(const Product&) const;
	virtual bool operator==(const Product&) const;

private:
	// unique attributes for Classic movies
   int month;
   string actorFirst, actorLast;
};

/*-----------------------------------------------------------------------------
  file drama.h
  Specific movie class for movies belonging to the Drama category.
  Authors: Blong Thao

  Assumptions:
    -- Sorted by director and then title
    -- Classics are represented by a ‘D’
-----------------------------------------------------------------------------*/

#pragma once

#include "movie.h"

class Drama : public Movie {

public:
	// Constructors
	Drama();
	~Drama();

	// for command data file
	virtual void setCmdData(istream&);
	// instantiates a Drama object
	virtual Product* create() const;
	virtual bool operator<(const Product&) const;
	virtual bool operator==(const Product&) const;
};

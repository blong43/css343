/*-----------------------------------------------------------------------------
  file comedy.h
  Specific movie class for movies belonging to the Comedy category.
  Authors: Blong Thao

  Assumptions:
    -- Comedy is represented by the letter ‘F’ in the data file
	-- Sorted by title and then date.
-----------------------------------------------------------------------------*/

#pragma once

#include "movie.h"

class Comedy : public Movie {

public:
	// Constructors
	Comedy();
	~Comedy();

	// for command data file
	virtual void setCmdData(istream&);
	// instantiates a Comedy object
	virtual Product* create() const;
	virtual bool operator<(const Product&) const;
	virtual bool operator==(const Product&) const;
};

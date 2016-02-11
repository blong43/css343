/*-----------------------------------------------------------------------------
  file productfactory.h
  Factory class that outputs a certain type of Product object
    depending on multiple character inputs.
  Authors: Blong Thao

  Assumptions:
    -- Product hash will actually be hashing different movie types
	-- Violates the open-closed principle since it does not contain
	      different types of products, and also has mediaFormat
-----------------------------------------------------------------------------*/

#pragma once

#include "product.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"
#include "defaultfactory.h"

class ProductFactory : public DefaultFactory {

public:
	// Constructors
    ProductFactory();
    ~ProductFactory();
	// makes the object knowing the movie code from the text file
    Product* createObject(char, istream&);
	// getter
	string getMediaType(char) const;

private:
	Product* productTypes[MAX_TYPES];   // container for products, hashtable
	string mediaFormat[MAX_TYPES];      // container for medias, hashtable
};

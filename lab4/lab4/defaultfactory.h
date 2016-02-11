/*-----------------------------------------------------------------------------
  file defaultfactory.h
  An abstract factory for extension
  Authors: Blong Thao
  
  Assumptions:
    -- Used for extension, but has set in stone hash and getlocation functions
-----------------------------------------------------------------------------*/

#pragma once

#include <iostream>
using namespace std;
const int MAX_TYPES = 26;       // maximum size for the hashtable

class DefaultFactory {

public:
	// Constructors
	DefaultFactory();
	virtual ~DefaultFactory();
	// gets the location within the hash table
	int getLocation(char) const;

protected:
	// hashes a character
    int hash(char) const;
};

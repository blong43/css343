/*-----------------------------------------------------------------------------
  file borrow.h
  Specific type of command for borrowing a movie.
  Authors: Blong Thao

  Implementation:
    - Inherits from Command, borrows a movie if it’s inventory
    - storeCommand function calls decreaseCopies() from Product to
		reduce the amount of copies when the borrow command is used
-----------------------------------------------------------------------------*/

#pragma once

#include "command.h"

class Borrow : public Command {

public:
	// Constructors
	Borrow();
	virtual ~Borrow();
	
	// creates a new borrow object
	virtual Command* create() const;
	// stores the borrow command
	virtual bool storeCommand(string, Product*, Customer*);
};

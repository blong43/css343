/*-----------------------------------------------------------------------------
  file displayhistory.h
  Specific type of command for displaying customer history.
  Authors: Blong Thao

  Implementation:
    -- Inherits from Command, displays the history of a specific customer.
    -- storeCommand function will call the customer’s history’s printHistory
-----------------------------------------------------------------------------*/

#pragma once

#include "command.h"

class History : public Command {

public:
	// Constructors
	History();
	virtual ~History();
	
	// makes a new history object
	virtual Command* create() const;
	// displays the history of a customer
	virtual bool storeCommand(string, Product*, Customer*);
};

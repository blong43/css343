/*-----------------------------------------------------------------------------
  file returncommand.h
  Specific type of command for returning a movie.
  Authors: Blong Thao

  Implementation:
    -- Inherits from Command, returns a movie if the customer in has it. 
    -- storeCommand function calls increaseCopies() from Product to
		increase the amount of copies when the return command is used
-----------------------------------------------------------------------------*/

#pragma once

#include "command.h"

class Return : public Command {

public:
	// Constructors
	Return();
	virtual ~Return();
	
	// creates a return object
	virtual Command* create() const;
	// stores the return command
	virtual bool storeCommand(string, Product*, Customer*);
};

/*-----------------------------------------------------------------------------
  file commandfactory.h
  Factory class that outputs a type of Command object based on command code
  Authors: Blong Thao

  Implementation:
    -- Implemented as a standard hash table. Only unique elements will
	     be the hash for the commands
-----------------------------------------------------------------------------*/

#pragma once

#include "command.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "defaultfactory.h"

class CommandFactory : public DefaultFactory {

public:
	// creates the command object slots for each command
    CommandFactory();

	// frees memory allocations
    ~CommandFactory();

	// creates the object if it has the correct command code
    Command* createObject(char, istream&);

private:
    Command* commands[MAX_TYPES];  // container for commmands
};

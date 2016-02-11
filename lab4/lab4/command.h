/*-----------------------------------------------------------------------------
  file command.h
  Command class for use in the command design pattern. Commands will be used
    to change things in Product, such as borrowing and returning movies.
  Authors: Blong Thao

  Implementation:
    -- Will store commands as needed and display commands as well
	-- Also creates new command objects, virtual so child classes can use it
-----------------------------------------------------------------------------*/

#pragma once

#include "product.h"
#include "customer.h"
class CustomerHistory;

class Command {

public:
	// sets the default data for command and media type and product ptr
	Command();
	Command(const Command&);
	virtual ~Command();
	
	// creates a new command object
	virtual Command* create() const;

	// prints out the command format
	virtual void display() const;

	// stores the command into the command and media type + product
	virtual bool storeCommand(string, Product*, Customer*);

	// getters for media and command type, a product
	string getMediaType() const;
	string getCommandType() const;
	Product* getProd() const;

protected:
	string commandType, mediaType;   // holds a type of media and command
	Product* aProduct;               // holds a pointer to the product
};

/*-----------------------------------------------------------------------------
  file customer.h
  Class representing a customer, holding an id, name, and command History
  Author: Blong Thao

  Implementation:
    -- Customers hold id, name, and their command History
    -- placeOrder() is part of the command design pattern
  Assumptions:
    -- Customer is the “agent” in the command design pattern
-----------------------------------------------------------------------------*/

#pragma once

// #include "command.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Command;

class Customer {

public:
	// -- Constructors --
	// initializes to default values
    Customer();
	// initializes to values from a file
	Customer(istream&);
	// copies another customer
	Customer(const Customer&);
    ~Customer();

	// initializes the variables of a customer
	void setData(istream&);
	// adds commands to the customer history
	void appendCommand(Command);
	// displays a customer's history
    void printHistory() const;

	// getters for id, lastname, firstname
	int getID() const;
	string getLastName() const;
	string getFirstName() const;

	//equality operators
	virtual bool operator==(const Customer&);
	virtual bool operator!=(const Customer&);

private:
   int id;							// customerID#
   string lastName, firstName;      // customers' name in seperate strings
   vector<Command> commandHistory;  // customers' command history, in a vector
};

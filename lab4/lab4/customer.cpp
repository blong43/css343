// file customer.cpp
// Function definitions for the Customer Class
// Author: Blong Thao

#include "customer.h"
#include "command.h"

//-----------------------------------------------------------------------------
// Default Constructor
// Sets the customer data to default values

Customer::Customer() {
	lastName = firstName = "";
	id = 0;
}

//-----------------------------------------------------------------------------
// Constructor
// Sets the customer data to values from a file

Customer::Customer(istream& infile) {
	setData(infile);
}

//-----------------------------------------------------------------------------
// Copy Constructor
// Copies another customer's name and id

Customer::Customer(const Customer& toCopy) {
	lastName = toCopy.lastName;
	firstName = toCopy.firstName;
	id = toCopy.id;
}

//-----------------------------------------------------------------------------
// Destructor
// Just the default destructor

Customer::~Customer() {
}

//-----------------------------------------------------------------------------
// setData
// initializes the variables of a customer

void Customer::setData(istream& infile) {
	infile >> id;
	if (infile.eof()) return;

	infile.get();
	infile >> lastName;
		
	infile.get();
	infile >> firstName;
}

//-----------------------------------------------------------------------------
// appendCommand
// adds a command to a customer's history

void Customer::appendCommand(Command newCommand) {
	commandHistory.push_back(newCommand);
}

//-----------------------------------------------------------------------------
// printHistory
// Displays the customer's history

void Customer::printHistory() const {
	cout << "  *** Customer ID = " << id << "  "
		<< lastName << " " << firstName << endl;

	if (commandHistory.size() > 0) {
		for (int i = 0; i < (int)commandHistory.size(); i++) {
			commandHistory[i].display();
			commandHistory[i].getProd()->display();
		}
		cout << endl;
	}
	else
		cout << "No history to display for this customer\n\n";
}

//-----------------------------------------------------------------------------
// getID
// Getter for id

int Customer::getID() const {
	return id;
}

//-----------------------------------------------------------------------------
// getLastName
// Getter for last name

string Customer::getLastName() const {
	return lastName;
}

//-----------------------------------------------------------------------------
// getFirstName
// Getter for first name

string Customer::getFirstName() const {
	return firstName;
}

//-----------------------------------------------------------------------------
// getFirstName
// checks if customers are the same

bool Customer::operator==(const Customer& rhs) {
	return (id == rhs.id);
}

//-----------------------------------------------------------------------------
// getFirstName
// checks if customers are different

bool Customer::operator!=(const Customer& rhs) {
	return (id != rhs.id);
}

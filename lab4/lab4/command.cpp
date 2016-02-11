// file command.cpp
// Function definitions for the Command Class
// Author: Blong Thao

#include "command.h"

//-----------------------------------------------------------------------------
// Default Constructor
// Defines the default data for the command and media type and the product ptr

Command::Command() {
	commandType = "Command";
	mediaType = "";
	aProduct = NULL;
}

//-----------------------------------------------------------------------------
// Copy Constructor
// Copies another command

Command::Command(const Command& toCopy) {
	commandType = toCopy.commandType;
	mediaType = toCopy.mediaType;
	aProduct = toCopy.aProduct;
}

//-----------------------------------------------------------------------------
// Destructor
// Enables viable deletion for the child classes

Command::~Command() {
}

//-----------------------------------------------------------------------------
// create
// Makes a new Command object

Command* Command::create() const {
	return new Command();
}

//-----------------------------------------------------------------------------
// display
// Prints out the media and command type in this format

void Command::display() const {
	cout << mediaType << " " << commandType << " ";
}

//-----------------------------------------------------------------------------
// storeCommand
// Sets the command and stores it, always returns true

bool Command::storeCommand(string media, Product* theProd, Customer* cust) {
	mediaType = media;
	aProduct = theProd;
	return true;
}

//-----------------------------------------------------------------------------
// getMediaType
// Returns the media type

string Command::getMediaType() const {
	return mediaType;
}

//-----------------------------------------------------------------------------
// getCommandType
// Returns the command type

string Command::getCommandType() const {
	return commandType;
}

//-----------------------------------------------------------------------------
// getProd
// Returns the product

Product* Command::getProd() const {
	return aProduct;
}
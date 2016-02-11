// file commandfactory.cpp
// Function definitions for the CommandFactory class
// Author: Blong Thao

#include "commandfactory.h"

//-----------------------------------------------------------------------------
// Constructor
// Defines the default values for this class and creates the needed commands

CommandFactory::CommandFactory() : DefaultFactory() {
	// initialize hashtable to null pointers to avoid garbage
	for (int i = 0; i < MAX_TYPES; i++)
		commands[i] = NULL;

	// hard-coded creations of objects
	commands[1] = new Borrow();
	commands[7] = new History();
	commands[17] = new Return();
}

//-----------------------------------------------------------------------------
// Destructor
// Frees each command type in the command factory

CommandFactory::~CommandFactory() {
	// traverses the hashtable to free the memory allocations
	for (int i = 0; i < MAX_TYPES; i++) {
		if (commands[i] != NULL) {
			delete commands[i];
			commands[i] = NULL;
		}
	}
}

//-----------------------------------------------------------------------------
// createObject
// Makes a CommandFactory object, which returns as a Product pointer.

Command* CommandFactory::createObject(char ch, istream& infile) {
	int subscript = hash(ch);

	// must have an open bucket to create the commmand
	if (commands[subscript] == NULL) {
		// leaves infile text in a tempory string and returns NULL
		string temp;
		getline(infile, temp, '\n');
		return NULL;
	}
	// there is an open bucket, create the command
	else
		return commands[subscript]->create();
}

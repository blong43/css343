/*-----------------------------------------------------------------------------
  file storemanager.h
  Authors: Blong Thao
  
  StoreManager class:  a class that manages all the processes and data related
     to handling products offered by the store. 
	 The class:
    -- Allows the input of customer data
    -- Allows the partial input of customer commands
    -- Allows the partial input of product data  
    -- Allows the output of customer history
    -- Allows the output of the store's products
    -- Holds the customer and product data

  Implementation and Assumptions:  
    -- The data must be formatted correctly
    -- If a new product needs to be added the input data shall change,
         therefore, the productfactory and the I/O need
         to be modified to fit the new product    
    -- The products will be contained in a hash table, and the
         product types will be contained in a hash table, the final
         concrete class product will be contained in a binary search tree
-----------------------------------------------------------------------------*/

#pragma once

#include "bintree.h"
#include "customer.h"
#include "commandfactory.h"
#include "productfactory.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int MAX_COPIES = 10;           // limit of copies allowed
const int MAX_ACCOUNTS = 10000;      // accounts will go from 1000-9999
const int MAX_NUM = 10000;           // highest acct# that can be registered
const int MIN_NUM = 999;             // lowest acct# that can be registered
class StoreManager {

public:
	// initializes the name of the store
	StoreManager(string = "STORE NAME");
    ~StoreManager();

	// stocks the inventory of movies from an input file
    void buildInventory(istream&);

	// makes customer accounts from an input file
    void createAccounts(istream&);

	// runs commands and stores it into history
    void runCommands(istream&);

private:
	char movieCode;                  // determines which object to create
	string storeName;                // the name of the store
	
	CommandFactory cFactory;         // factory for commands
    ProductFactory pFactory;         // factory for products
	BinTree inventory[MAX_TYPES];    // container for the inventory, size 26
	Customer accounts[MAX_ACCOUNTS]; // container for customer accounts
	
	// -- helper functions -- 
	// used to free the command pointer as needed
	void freeCmdPtr(Command*) const;
	// prints the header and all the available inventory
	void display() const;
};

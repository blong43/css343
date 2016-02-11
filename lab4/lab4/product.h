/*-----------------------------------------------------------------------------
  file product.h
  Pure virtual class representing a general product, controls distribution
  Authors: Blong Thao

  Assumptions:
    -- Controls the product distribution of the copies
-----------------------------------------------------------------------------*/

#pragma once

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
const int NONE = 0;  // for checking zero, or no copies

class Product {

public:
	// Constructors
    Product();
    virtual ~Product();

	// two setData, one for product data, other is for command data
    virtual void setData(istream&) = 0;
	virtual void setCmdData(istream&) = 0;
	// two displays, for body and header, resp.
    virtual void display() const = 0;
    virtual void displayHeader() const = 0;
	// instantiates a product object
	virtual Product* create() const = 0;
    virtual bool operator<(const Product&) const = 0;
    virtual bool operator==(const Product&) const = 0;
	// getter for the product type
	virtual string getProd() const = 0;

	// -- Product class functions --
	// sets the max amount for copies in
	void setMaxCopy(const int);
	// increments copies by one
	void increaseCopies();
	// decrements copies by one
	void decreaseCopies();
	// getter for amounts in/out
	int getAmountIn() const;
	int getAmountOut() const;
    
private:
    int maxCopies;   // limit of copies in at one time
	int amtOfCopies; // copies actually in at one time
};

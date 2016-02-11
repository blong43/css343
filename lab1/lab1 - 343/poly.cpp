//-----------------------------------------------------------------------------
// poly.cpp
// Member function definitions for the Poly class 
// Author: Blong Thao
//-----------------------------------------------------------------------------

#include "poly.h"

//------------------- Constructor ---------------------------------------------
// Default constructor for the Poly Class
// Preconditions:  The exponent cannot be negative, if so default it to zero
// Postconditions: A polyArray is created and contains the coeffecient 
//   and the size is initialized to the exponent + 1 to account for 
//   the exponent and its coefficient                 

Poly::Poly(int coeff, int exponent) {
	// non-negative exponent
	if (exponent > -1) {
		size = exponent + 1;
		polyArray = new int[size];

		for (int i = 0; i < size; i++)
			polyArray[i] = 0;

		polyArray[exponent] = coeff;
	}
	// negative exponent, makes a default array of size one with a 0 coeff/expo
	else {
		size = 1;
		polyArray = new int[size];
		polyArray[0] = 0;
	}
}

//--------------------- Copy --------------------------------------------------
// Copy constructor for the Poly Class
// Preconditions:  Must have valid Poly object to copy over, non-negative expo
// Postconditions: Copies over all of the toCopy Poly values and size

Poly::Poly(const Poly& toCopy) {
	size = toCopy.size;
	polyArray = new int[size];

	for (int i = 0; i < size; i++)
		polyArray[i] = toCopy.polyArray[i];
}

//------------------- Destructor ----------------------------------------------
// Destructor for the Poly Class
// Preconditions:  Needs allocated memory
// Postconditions: Frees all allocated memory

Poly::~Poly() {
	delete [] polyArray;
}

//-------------------- operator= ----------------------------------------------
// The assignment operator for the Poly class
// Preconditions:  Must have non-negative exponents
// Postconditions: If current Poly is not equal to rhs, a new array is created
//                 and copies over all the values from the right hand side,
//                 which also initializes the appropriate size

Poly& Poly::operator=(const Poly& rhs) {
	if (*this != rhs) {
		// resizes the poly array
		if (this->size < rhs.size) {
			delete [] this->polyArray;
			this->size = rhs.size;
			this->polyArray = new int[this->size];
			for (int i = 0; i < this->size; i++)
				this->polyArray[i] = rhs.polyArray[i];
		}
		// does not resize, but resets the array and copies values
		else {
			for (int i = 0; i < this->size; i++)
				this->polyArray[i] = 0;
			for (int i = 0; i < rhs.size; i++)
				this->polyArray[i] = rhs.polyArray[i];
		}
	}
	return *this;
}

//-------------------- operator+ ----------------------------------------------
// The addition operator for the Poly class
// Preconditions:  Always use the larger poly array to add values to
// Postconditions: Return the new temp Poly, contains correct values

Poly Poly::operator+(const Poly& rhs) const {
	// checks for empty objects
	if (rhs.size == 0 && this->size == 0)
		return *this;
	// checks the array sizes to determine which to copy into the temp Poly
	if (this->size >= rhs.size) {
		Poly temp(*this);
		addArrays(temp.polyArray, rhs);
		return temp;
	}
	else {
		Poly temp(rhs);
		addArrays(temp.polyArray, rhs);
		return temp;
	}
}

//-------------------- operator- ----------------------------------------------
// The subtraction operator for the Poly class
// Preconditions:  Use the larger Poly object
// Postconditions: Returns  temp Poly object, contains the correct values

Poly Poly::operator-(const Poly& rhs) const {
	// checks for empty objects
	if (rhs.size == 0 && this->size == 0)
		return *this;
	
	// checks the array sizes to determine which to copy into the temp Poly
	if (this->size >= rhs.size) {
		Poly temp(*this);
		subtractArrays(temp.polyArray, rhs);
		return temp;
	}
	else {
		Poly temp(rhs);
		subtractArrays(temp.polyArray, rhs);
		return temp;
	}
}

//-------------------- operator* ----------------------------------------------
// The multiply operator for the Poly class
// Preconditions:  Have a valid size, non-negative
// Postconditions: Returns the temp Poly object, contains correct values

Poly Poly::operator*(const Poly& rhs) const {
	// checks for empty objects
	if (rhs.size == 0 && this->size == 0)
		return *this;
	
	// otherwise, make a Poly object which has a size of the sum of both sizes
	else {
		int newExponent = this->size + rhs.size;
		Poly temp(0, newExponent);
		// stores the multication of both array values into the correct spot
		multiplyArrays(temp.polyArray, rhs);
		return temp;
	}
}

//-------------------- operator+= ---------------------------------------------
// The addition assignment operator for the Poly class
// Preconditions:  Uses both the assignment and addition operators 
// Postconditions: Assigned the current Poly to the new one (a + b).

Poly& Poly::operator+=(const Poly& rhs) {
	// makes the array larger to compensate for adding both arrays
	if (this->size < rhs.size)
		resizeArray(rhs.size);
	
	addArrays(polyArray, rhs);
	return *this;
}

//-------------------- operator-= ---------------------------------------------
// The subtraction assignment operator for the Poly class
// Preconditions:  Uses both the assignment and subtraction operators 
// Postconditions: Assigned the current Poly to the new one (a - b).

Poly& Poly::operator-=(const Poly& rhs) {
	// makes the array larger to compensate for subtracting both arrays
	if (this->size < rhs.size)
		resizeArray(rhs.size);
	
	subtractArrays(polyArray, rhs);
	return *this;
}

//-------------------- operator*= ---------------------------------------------
// The multiply assignment operator for the Poly class
// Preconditions:  Uses both the assignment and multiply operators
// Postconditions: Assigned the current Poly to the new one (a * b)

Poly& Poly::operator*=(const Poly& rhs) {
	// make the temp array to hold the newExponent size
	int newExponent = this->size + rhs.size;
	int* temp = new int[newExponent];
	
	for (int i = 0; i < newExponent; i++)
		temp[i] = 0;

	// put the new values into the temp array that is of the correct size
	multiplyArrays(temp, rhs);

	// assign the polyArray pointer to the temp array
	delete [] polyArray;
	size = newExponent;
	polyArray = temp;
	temp = NULL;
	return *this;
}

//-------------------- operator== ---------------------------------------------
// The equality operator for the Poly class
// Preconditions:  Valid input values to compare, integers only
// Postconditions: Returns a boolean indicating the equality status
bool Poly::operator==(const Poly& rhs) const {
	// both polynomials are empty
	if (rhs.size == 0 && this->size == 0)
		return true;

	// there are polynomials to compare
	else if (rhs.size > -1 && this->size > -1) {
		int largerSize = this->size, smallerSize = rhs.size;

		if (this->size <= rhs.size) {
			largerSize = rhs.size;
			smallerSize = this->size;
		}

		// compares the smaller array to the other array
		int i = 0;
		for (; i < smallerSize; i++)
			if (this->polyArray[i] != rhs.polyArray[i])
				return false;

		// checks the larger array for values that are not zero
		for (; i < largerSize; i++) 
			if (rhs.polyArray[i] != 0)
				return false;

		// all checks were made and none returned, so the polys must be equal
		return true;
	}
	// else, polynomials are not of correct length (size < 0)
	return false;
}

//-------------------- operator!= ---------------------------------------------
// The inequality operator for the Poly class
// Preconditions:  None. (Calls the equality operator, so == has to work first)
// Postconditions: Returns a boolean indicating the equality status

bool Poly::operator!=(const Poly& rhs) const {
	return !(*this == rhs);
}

//-------------------- setCoeff -----------------------------------------------
// The function that sets the coeffecients and exponent manaully
// Preconditions:  All exponents must be non-negative integers
// Postconditions: The coefficient and exponent have been successfully set.

void Poly::setCoeff(const int coeff, const int exponent) {
	if (exponent > -1) {
		// a larger array is created when the exponent is larger than size
		if (exponent >= this->size) {
			int newSize = exponent + 1;
			resizeArray(newSize);
		}
		// set the coeff in the correct spot in the array
		polyArray[exponent] = coeff;
	}
}

//-------------------- getCoeff -----------------------------------------------
// Gets the coeffecient at the location target
// Preconditions:  The Poly object must contain values to get the coefficient
// Postconditions: The target has been retrieved from the Poly object,
//                   otherwise, was a non-existant term, returns zero.

int Poly::getCoeff(const int target) const {
	if (size > 0 && size > target && target > -1) {
		if ( polyArray[target] != 0)
			return polyArray[target];
	}
	// else, non-existant term
	return 0;
}

//------------------- resizeArray --------------------------------------------
// Makes a new polyArray that fits the correct size
// Preconditions:  Cannot shrink the array (size < newSize)
// Postconditions: The polyArray's length becomes the new size value

void Poly::resizeArray(const int newSize) {
	// create a temporary array to take on the new size and polyArray's values
	int* temp = new int[newSize];
	
	for (int i = 0; i < newSize; i++)
		temp[i] = 0;

	for (int i = 0; i < this->size; i++)
		temp[i] = this->polyArray[i];
	
	delete [] polyArray;
	this->size = newSize;
	polyArray = temp;
	temp = NULL;
}

//------------------- addArrays -----------------------------------------------
// Adds the values in the two arrays 
// Preconditions:  Can only be used in operators+ and +=
// Postconditions: Adds values togets and stores it into a temporary array

void Poly::addArrays(int* temp, const Poly& rhs) const {
	// find the smaller size, used to tell how far to traverse arrays
	int smallerSize = this->size;
	if (this->size > rhs.size)
		smallerSize = rhs.size;

	// only traverse through the smaller length to do the addition
	for (int i = 0; i < smallerSize; i++)
		temp[i] = this->polyArray[i] + rhs.polyArray[i]; 
}

//------------------- subtractArrays ------------------------------------------
// Subtracts the values in the two arrays
// Preconditions:  Can only be used in operators- and -=
// Postconditions: Subtracts values and stores it into a temporary array

void Poly::subtractArrays(int* temp, const Poly& rhs) const {
	// Used to tell which array is larger and how far to traverse the arrays
	int largerSize = this->size, smallerSize = rhs.size;
	if (this->size < rhs.size) {
		largerSize = rhs.size;
		smallerSize = this->size;
	}
	
	// traverse the smaller sections and do subtraction there
	int i = 0;	
	for (; i < smallerSize; i++)
		temp[i] = this->polyArray[i] - rhs.polyArray[i];

	// if rhs is larger, make the rest of the array values negative
	if (largerSize == rhs.size)
		for (; i < largerSize; i++)
			temp[i] -= rhs.polyArray[i] * 2;

}

//------------------- multiplyArrays ------------------------------------------
// Multiplies the values in the two arrays
// Preconditions:  Can only be used in the operators* and *= 
// Postconditions: Multiplied values are in the correct indexes of temp array

void Poly::multiplyArrays(int* temp, const Poly& rhs) const {
	// multiplies each value to one another from each arrays
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < rhs.size; j++) {
			temp[i+j] += this->polyArray[i] * rhs.polyArray[j]; 
		}
	}
}

//-------------------- operator<< ---------------------------------------------
// Output operator for the Poly class
// Preconditions:  None.
// Postconditions: Poly object is printed out from highest exponent to lowest

ostream& operator<<(ostream& output, const Poly& a) {
	// isPrinted checks if there was any output, if not then print zero
	bool isPrinted = false;

	// prints the poly equation in the correct format
	for (int expo = a.size-1; expo >= 0; expo--) {
		int coeff = a.polyArray[expo];
		if (coeff != 0) {
			isPrinted = true;

			// checks to see if the coeff is positive or negative
			if (coeff > 0)
				output << " +" << coeff;
			else
				output << " " << coeff;

			// checks to see if the exponent is one or if larger than one
			if (expo == 1)
				output << "x";
			else if (expo > 1)
				output << "x^" << expo;
		}
	}

	// if all values in the array is zero, output zero
	if (!isPrinted)
		output << " 0";

	return output;
}

//-------------------- operator>> ---------------------------------------------
// Input operator for the Poly class
// Preconditions:  Input for coeff can be any number, 
//                 but exponent can only have positive numbers
// Postconditions: The object becomes populated if there was input

istream& operator>>(istream& input, Poly& a) {
	// variables that hold the coefficient and exponent during input
	int coeff = 0, exponent = 0;
	
	// exit the input stream when both the coeff and exponent are -1
	while (coeff != -1 && exponent != -1) {
		input >> coeff >> exponent;
		// does not allow negative exponents
		if (exponent > -1)
			a.setCoeff(coeff, exponent);
	}
	return input;
}

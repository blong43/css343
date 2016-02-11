////-----------------------------------------------------------------------------
//// TEST.CPP
//// Driver for unit testing, then do regression testing,
////     afterwards switch to main.cpp
//
//// DO NOT change anything in this file. Your code must compile and give the
//// correct output with this main on the linux machines.
//
//// Make sure the file containing the member function source is: poly.cpp
//// Use all lowercase in the file names.
//
//// This main does not do a thorough job of testing.  When testing arrays,
//// be sure to test the middle and also all the boundary conditions.  Test
//// values on the boundary and outside the boundaries, i.e., too big/small.
////-----------------------------------------------------------------------------
//
//#include "poly.h"
//#include <iostream>
//using namespace std;
//
//int main () {
//   Poly A(5, 7), B(3,4), C(2), X, Y1, Y2, Y3;
//   Poly A2, B2, C2, Z1, Z2;
//
//   // set polynomials A and B to desired values
//   // A = +5x^7 -4x^3 +10x -2
//   // B = +3x^4 +1x^3 
//   A.setCoeff(10, 1);
//   A.setCoeff(-4, 3);
//   A.setCoeff(-2, 0);
//   B.setCoeff(1, 3);
//
//   A2.setCoeff(2, 3); 
//   A2.setCoeff(-1, 0); // A2 = 2x^3 -1
//
//   B2.setCoeff(2, 3); // B2 = 2x^3
//
//   cout << "Testing subtraction" << endl;
//   cout << "A2 - B2 =" << A2-B2 << endl << endl;
//
//   cout << "Unit Testing: assignment, addition, subtraction, multiplication \n"
//      << "equal/not equal, +=, -=, *=, getCoeff, setCoeff, getSize, etc.\n\n";
//
//
//   cout << "A =" << A << endl;
//   cout << "B =" << B << endl << endl;
//
//   cout << "Default Constructor: C(2)" << endl;
//   cout << "C =" << C << endl << endl;
//
//   cout << "Copy Constructor: D(A)" << endl;
//   Poly D(A);
//   cout << "D =" << D << endl << endl;
//
//   cout << "Assignment Operator: A = B" << endl;
//   A = B;
//   cout << "A =" << A << endl << endl;
//
//   cout << "Addition Operator: A + B\n";
//   cout << "A + B =" << A + B << endl << endl;
//
//
//
//   //A2 = A;
//   //B2 = B;
//   //C = A + B;  
//   //cout << "Compute C = A + B: " << C << endl << endl;
//
//   //cout <<  ( (Y2 == Y3) ? "Y2 == Y3" : "Y2 is not == Y3" ) << endl;
//   //cout <<  ( (B == A) ? "B == A" : "B is not == A" ) << endl;
//   //cout <<  ( (A == B) ? "A == B" : "A is not == B" ) << endl;
//   //cout <<  ( (A != B) ? "A is not == B" : "A == B" ) << endl << endl;
//
//   //Z1 = A2 - B2;
//   //cout << "Compute  Z1 = A2 - B2: " << Z1 << endl;
//   //Z2 = B2 - A2;
//   //cout << "Compute  Z2 = B2 - A2: " << Z2 << endl << endl;
//
//   //cout << "Compute  D = A * B - 15" << endl;
//   //cout << "Before: D =" << D << endl;
//   //D = A * B - 15;
//   //cout << "After:  D =" << D << endl << endl;
//
//   //cout << "Test assignment operators" << endl;
//   //X = C = D = D;  
//   //Y1 += A -= B *= A;
//   ////Y1 -= B;
//   ////cout << "Y1 =" << Y1 << endl << endl;
//   ////B *= A;
//   //cout << "X =" << X << endl;
//   ////cout << "B =" << B << endl << endl;
//   //cout << "Y1 =" << Y1 << endl << endl;
//
//
//   cout << "Get and Set coefficient" << endl;
//   int coeff = D.getCoeff(8); 
//   cout << "coeff of subscript 8 of D is: " << coeff << endl;
//   cout << "Doing getCoeff for term -20000" << endl;
//   coeff = D.getCoeff(-20000);              // handle value out of range
//   D.setCoeff(50,0);                        // set x^0 coeff to 50
//   D.setCoeff(50,20000);                    // set x^20000 coeff to 50
//   cout << "D =" << D << endl << endl;
//
//   return 0;
//}

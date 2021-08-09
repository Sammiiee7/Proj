/*-------------------------------------------------------------------------------------------------------------------
FILENAME:	Polynomial.h
DESCRIPTION:  Header file for Polynomial.cpp and poly_class.cpp
COMPILER:	G++ Linux
NOTES:	header file for class polynomial and all the operators
MODIFICATION HISTORY:
AUTHOR			DATE			VERSION
--------------- ------------------------   -------------------------------
Samuel Ayeju	      2018-03-25	   1.0(private, public,friend class, 
					   constructor, operators, destructor)
Samuel Ayeju	      2018-04-02	   1.1(added indefinite integration)
Samuel Ayeju	      2018-04-04	   1.2(added definite integration)	 	        
-------------------------------------------------------------------------------------------------------------------*/

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <iostream>
#include <math.h>	

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;
const char PROGRAMMER_NAME[] = "Samuel Ayeju"; // Global constant

class Polynomial
{
    private:
        int degree; 		// Degree of the polynomial
	double coef[9]; 		// Array of coefficients

    public:
	friend ostream &operator << (ostream& , const Polynomial&); // Poly output
	friend istream &operator >> (istream& , Polynomial&); // Poly input

        Polynomial();					//Constructor
	Polynomial(int d, double c[]);			//Overloaded Constructor
	Polynomial(const Polynomial&);			//Copy Constructor
 
	~Polynomial();					//Destructor

	Polynomial operator + (const Polynomial &);	//Add
	Polynomial operator - (const Polynomial &);	//Subtract
	Polynomial operator * (const Polynomial &);	//Multiply
	Polynomial operator --(int);			//Differntiation
        Polynomial operator ++(int);                    //Indef Integration
	Polynomial& operator ++();                      //Def Integration
	Polynomial& operator = (const Polynomial &);	//Assign
	bool operator == (const Polynomial &);		//Equality
	double  operator ()(double);			//Evaluate
};

#endif /* __POLYNOMIAL_H__ */


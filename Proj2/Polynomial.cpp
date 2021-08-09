/* -------------------------------------------------------------------------------------------------------------------------------
FILE:              Polynomial.cpp
DESCRIPTION:       This is an implementation file with a constructor
                     destrcutor and member functions. 
COMPILER:          G ++ Linux
NOTES:             
MODIFICATION HISTORY:
Author                  Date               Version
 --------------         ----------         -----------------------
Samuel Ayeju		2018-03-25	   1.0 (created member functions, constr						uctor and destructor)
Samuel Ayeju		2018-04-02	   1.1 (added indefinite integration)
Samuel Ayeju	        2018-04-04	   1.2 (added definite integration)	
/-------------------------------------------------------------------------------------------------------------------------------- */

#include "Polynomial.h"

/*-----------------------------------------------------------------------------------/
 FUNCTION:	Polynomial()
 DESCRIPTION:   Constructor
 RETURNS:	Nothing
 NOTES:		
/-----------------------------------------------------------------------------------*/
// Constructor
Polynomial::Polynomial()		//Constructor
{					//sets all values to start at 0
    degree = 0;

    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;
}

/*-----------------------------------------------------------------------------------/
 FUNCTION:	Polynomial()
 DESCRIPTION:	Destructor
 RETURNS:	Nothing
 NOTES:		
/-----------------------------------------------------------------------------------*/
// Destrcutor
Polynomial::~Polynomial()
{
	degree =0;
	for (int i = 0; i < ARRAY_SIZE(coef); i++)
        	coef[i] = 0;
cout << "Destructor is working"<< endl;
}


/*-----------------------------------------------------------------------------------/
 FUNCTION:      Polynomial::Polynomial(const Polynomial &f)
 DESCRIPTION:   Copy Constrcutor
 RETURNS:       Nothing
 NOTES:         Copies existing polynomial, creates new one
/-----------------------------------------------------------------------------------*/

// Copies existing polynomial, creates new one
Polynomial::Polynomial(const Polynomial &f)
{

   degree = f.degree;
   
   for (int i = 0; i <= degree; i++)
        coef[i] = f.coef[i];
}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      Polynomial::Polynomial(int d, double c[])
 DESCRIPTION:   Overloaded Constructor
 RETURNS:       Nothing
 NOTES:        Polynomial with int degree passed into double coef
/-----------------------------------------------------------------------------------*/

// Polynomial with int degree passed into double coef
Polynomial::Polynomial(int d, double c[])
{
    for (int i = 0; i < ARRAY_SIZE(coef); i++)
        coef[i] = 0;
    degree = d;

    for (int i = 0; i <= degree; i++)
        coef[i] = c[i];
}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      ostream& operator << (ostream& os, const Polynomial &f)
 DESCRIPTION:   Output Operator
 RETURNS:       os
 NOTES:         overloads the << operator
/-----------------------------------------------------------------------------------*/

// Output operator, overloads the << operator
ostream& operator << (ostream& os, const Polynomial &f)
{

	for (int i =f.degree; i >= 0; i--)
	{
	        if (i < f.degree)
	        {
	            if (f.coef[i] >= 0) cout << " +";
	            else os << " ";
	        }
	        os << f.coef[i];
	
	        if (i>1) os << "x^(" << i<<")" ;
	        if (i==1) os << "x";
	 }
    cout << endl;
    return os;
} 

/*-----------------------------------------------------------------------------------/
 FUNCTION:      istream& operator >> (istream& is, Polynomial &f)
 DESCRIPTION:   Input Operator
 RETURNS:       is
 NOTES:         Overloads the >>
/-----------------------------------------------------------------------------------*/

//Input operator overloads the >> 
istream& operator >> (istream& is, Polynomial &f)
{
    cout << "\nEnter degree of polynomial: ";
    is >> f.degree;

    cout << "Enter the " << f.degree+1 << " coefficients: ";

    for (int i = f.degree; i >= 0; i--)
        is >> f.coef[i];
    return is;
}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      Polynomial Polynomial::operator + (const Polynomial &p1)
 DESCRIPTION:   Addition Operator
 RETURNS:       p2
 NOTES:        overloads the + operator to perform addition
/-----------------------------------------------------------------------------------*/

// Addition
Polynomial Polynomial::operator + (const Polynomial &p1)
{
    Polynomial p2;

    //cout << "\n Adding the polynomials:      ";

    p2.degree = MAX(degree, p1.degree);
    for (int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] + p1.coef[i];
	
    return p2;

}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      Polynomial Polynomial::operator - (const Polynomial &p1)
 DESCRIPTION:   Subtraction
 RETURNS:       p2
 NOTES:       overloads the - operator to perfom subtraction
/-----------------------------------------------------------------------------------*/

// Subtraction
Polynomial Polynomial::operator - (const Polynomial &p1)
{
    Polynomial p2;

    //cout << "\n Subtracting the polynomials:    ";

    p2.degree = MAX(degree, p1.degree);
    for (int i = p2.degree; i >= 0; i--)
        p2.coef[i] = coef[i] - p1.coef[i];

    return p2;

}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      Polynomial Polynomial::operator * (const Polynomial &p1)
 DESCRIPTION:   Multiplication Operator
 RETURNS:       p3
 NOTES:        overloads the * operator to peform multiplication
/-----------------------------------------------------------------------------------*/

// Multiplication
Polynomial Polynomial::operator * (const Polynomial &p1) 
{
    int i;
    Polynomial p3;
    
    //cout << "\n Multiplying the polynomials: ";

    p3.degree = (degree)+ (p1.degree);

        for (int j = degree; j >= 0; j--)
        {
           for (int k = p1.degree; k >=0; k--)
              {
                  i = j + k;
                  p3.coef[i] =(coef[j] * p1.coef[k]) + p3.coef[i];
              }
        }
    return p3;
}


/*-----------------------------------------------------------------------------------/
 FUNCTION:      Polynomial Polynomial::operator -- (int i)
 DESCRIPTION:   Differentiation Operator
 RETURNS:       p2
 NOTES:         Overloads the -- to perform differentiation
/-----------------------------------------------------------------------------------*/
// Derivative
Polynomial Polynomial::operator -- (int i)
{
   Polynomial p2;
   cout << " Differntiation :";
   p2.degree = (degree -1);
   for (int i = degree; i>=0;i--)
       p2.coef[i] = (coef[i+1] *(i+1));

    return p2;

}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      Polynomial Polynomial::operator ++ (int i)
 DESCRIPTION:   Indefinite Integration Operator
 RETURNS:       p2
 NOTES:         Overloads the ++ operator to perform integration
/-----------------------------------------------------------------------------------*/

//Indefinite Integration
Polynomial Polynomial::operator ++ (int i)
{
   Polynomial p2;
   cout << " Integration :";
   p2.degree = (degree +1);
   for (int i = degree; i>=0;i--)
       p2.coef[i+1] = (coef[i] /(i+1));
// degree++;
    return p2;

}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      Polynomial& Polynomial::operator ++ ()
 DESCRIPTION:   Definite integration Operator
 RETURNS:       *this
 NOTES:         Overloads the ++ to perform integration and also does bounds
		checking. 
/-----------------------------------------------------------------------------------*/

//definite Integration
Polynomial& Polynomial::operator ++ ()
{
double a, b, y;
Polynomial g = *this;

g++;
g.degree = 0;
 cout << g;
cout << "Input Lower and upper bounds: ";
cin >> a >> b;

y = g(b) - g(a);

cout << "  ---> Int = " << y << endl;

return *this;
}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      Double Polynomial::operator () (double x)
 DESCRIPTION:   Evaluation Operator
 RETURNS:       total
 NOTES:    
/-----------------------------------------------------------------------------------*/

// Evaluation
double Polynomial::operator () (double x)
{
   double total=0.0;
   for (int i = degree; i>=0; i--)
        total = ((coef[i]) * (pow ( x, degree)))+ total ;
   return total;
}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      bool Polynomial:: operator == (const Polynomial &p1)
 DESCRIPTION:   Equality Operator
 RETURNS:       True
 NOTES:        checks two polynomials against each and returns true/false
		if they're equal or not.
/-----------------------------------------------------------------------------------*/

// Equality
bool Polynomial:: operator == (const Polynomial &p1)
{
	if(this->degree != p1.degree) return false;

	for(int i = 0; i < this->degree; i++) {
		if(this->coef[i] != p1.coef[i]) return false;
	}

// 	cout << "Test: true" << endl;

	return true;
}

/*-----------------------------------------------------------------------------------/
 FUNCTION:      Polynomial & Polynomial::operator = (const Polynomial &f)
 DESCRIPTION:   Assignment Operator
 RETURNS:       *this
 NOTES:         performs assignment by overloading the = operator
/-----------------------------------------------------------------------------------*/

//Assign

Polynomial & Polynomial::operator = (const Polynomial &f)
{
       degree = f.degree;

       for (int i = 0; i <= degree; i++)
        coef[i] = f.coef[i];

	return *this;
}


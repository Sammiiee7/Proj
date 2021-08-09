/* -------------------------------------------------------------------------------------------------------------------------------
FILE:              Polynomial.cpp
DESCRIPTION:       This is an implementation file with a constructor
                     destrcutor and member functions.
COMPILER:          G ++ Linux
NOTES:
MODIFICATION HISTORY:
Author                  Date               Version
 --------------         ----------         -----------------------
Samuel Ayeju            2018-03-25         1.0 (created member functions, constr                                                uctor and destructor)
Samuel Ayeju            2018-04-02         1.1 (added indefinite integration)
Samuel Ayeju            2018-04-04         1.2 (added definite integration)
/-------------------------------------------------------------------------------------------------------------------------------- */

#include "Polynomial.h"

/*-----------------------------------------------------------------------------------/
 FUNCTION:	main()
 DESCRIPTION:	Program driver; responsible for running the program
 RETURNS:	0
 NOTES:         int argc  // Number of parameters on the command line   
	        char *argv[] // An array of pointers to C-strings		
/-----------------------------------------------------------------------------------*/

int main(int argc, char * argv[])
{
    Polynomial poly[6];
    double evalu, x;

    for (int n=0; n < 2; n++)
    {
	cin >> poly[n];				// input
	cout << poly[n];			// Output 
    }

   cout << "\n Adding the polynomials:      ";
   poly[3] = poly[0] + poly[1];			// Addition
    cout << poly[3];
   
  cout << "\n Subtracting the polynomials:    ";
    poly[3] = poly[0] - poly[1];		 //Subtraction
    cout << poly[3];
    
  cout << "\n Multiplying the polynomials: ";
    poly[3] = poly[0] * poly[1];		 // Multiplication
    cout << poly[3];

    cout<< "\n First polynomial";
    poly[3]= poly[0]--;				// Differentiation
    cout << poly[3];

    cout<< "\n Second polynomial";
    poly[3]= poly[1]--; 
    cout << poly[3];

 cout << " Differntiation :";

   cout<< "\n First polynomial Indefinite";
     poly[3]= poly[0]++;                         // Indefinite Integration
    cout << poly[3];

    cout<< "\n Second polynomial Indefinite";
   poly[3]= poly[1]++;
    cout << poly[3];


 cout<< "\n First polynomial definite";
     poly[3]= ++poly[0];                         // Definite Integration
    cout << poly[3];

    cout<< "\n Second polynomial definite";
   poly[3]= ++poly[1];
    cout << poly[3];




    cout<< " \n Value of x for the 1st  polynomial: ";
    cin >> x;
    evalu = poly[0](x) ;				// Evaluation
    cout << "\n  f("<<x << ")=    "<<evalu <<endl;		

    cout<< " \n Value of x for the 2nd polynomial: ";
    cin >> x;
    evalu = poly[1](x) ;
    cout << "\n  f("<<x << ")=    "<< evalu <<endl;

    cout << "Compare (x)  with the 1st  polynomial: ";
    cin >> poly[3];
    cout << "\n The 1st polynomial";
    bool check = poly[0] == poly[3];		// Equality
    cout <<check<< endl;
    if (check == true)
     cout<<"is = x \n";
    else if (check == false) 
     cout << " is !=  x \n";

    cout << "Compare (y)  with the 1st polynomial: ";
    cin >> poly[3];
    cout << "\n The 2nd polynomial";
    check = poly[1] == poly[3];
    cout <<check<< endl;
    if (check == true)
     cout<<"is =  y \n";
    else if (check == false)
     cout << " is !=  i \n";

    cout << endl;
  cout << endl;
  cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
  cout << __DATE__ << "  " __TIME__ << endl;
  cout << endl;

    return 0;
}


/*****************************************
 ** File: polynomial.c
 ** Author: Alexander D. Hall
 ** Date: 03/04/12
 ** Section: cs313-02 spring12
 ** E-mail: hall9@umbc.edu
 **
 **
 **
 ** Other Files requierd are
 ** 1. polynomail.h
 **
 ***********************************************/

#include <string.h>
#include <stdbool.h>
#include "polynomial.h"

// sortTerms prototype
static POLYNOMIAL sortTerms( POLYNOMIAL polynomial );


/**************************************************
 ** poly_addterm --
 **     This fucntion addes terms to the polynomail
 ** with the specified coff and expo
 **     Inputs: A Polynomial to insert the coeff and expo
 **     Output: The polynomial is returned
 **************************************************/
POLYNOMIAL poly_addterm ( POLYNOMIAL polynomial, int coeff, int expo ) {
    bool newTerm = true;
    int size = polynomial.size;
    
    if(polynomial.size == 0) {
        polynomial.terms[0].expo = expo;
        polynomial.terms[0].coeff = coeff;
        polynomial.size = 1;
    }
    else {
        for (int i = 0; i < size; i++) {
            if (polynomial.terms[i].expo == expo) {
                polynomial.terms[i].coeff = polynomial.terms[i].coeff + coeff;
                newTerm = false;
            }
            else if (i == size - 1 && newTerm == true) {
                polynomial.terms[size].expo = expo;
                polynomial.terms[size].coeff = coeff;
                polynomial.size = polynomial.size + 1;
            }
        }
    }

    polynomial = sortTerms ( polynomial );
    
    return polynomial;
}

/**************************************************
 ** poly_multiply --
 **     This fucntion multiplys each term coeff in the polynomail
 ** by a scalar
 **     Inputs: A Polynomial to apply the scalar
 **     Output: The polynomial is returned
 **************************************************/
POLYNOMIAL poly_multiply( POLYNOMIAL polynomial, int scalar ) {
    
    int size = polynomial.size;
    
    for(int i = 0; i < size; i++) {
        polynomial.terms[i].coeff = polynomial.terms[i].coeff * scalar;
    }
    
    polynomial = sortTerms ( polynomial );
    
    return polynomial;
}

/**************************************************
 ** poly_adding --
 **     This fucntion adds two different polynomials
 ** and stores it in a new polynomial
 **     Inputs: The new polynomial, followed by both polynomials
 ** being added
 **     Output: The polynomial is returned
 **************************************************/
POLYNOMIAL poly_adding( POLYNOMIAL polynomial, POLYNOMIAL polynomial1, POLYNOMIAL polynomial2 ) {
    
    
    if ( polynomial1.size >= polynomial2.size) {
        polynomial = polynomial1;
        for (int i = 0; i <= polynomial2.size; i++) {
            polynomial = poly_addterm(polynomial, polynomial2.terms[i].coeff, polynomial2.terms[i].expo);
        }
    }
    else {
        polynomial = polynomial2;
        for (int i = 0; i <= polynomial1.size; i++) {
            polynomial = poly_addterm(polynomial, polynomial1.terms[i].coeff, polynomial1.terms[i].expo);
        }
    }
    
    return polynomial;
}

/**************************************************
 ** poly_subtract --
 **     This fucntion subtract two different polynomials
 ** and stores it in a new polynomial
 **     Inputs: The new polynomial, followed the polynomial1
 ** and the second polynomial2 is beding subtracted from polynomial1
 **     Output: The polynomial is returned
 **************************************************/
POLYNOMIAL poly_subtract( POLYNOMIAL polynomial, POLYNOMIAL polynomial1, POLYNOMIAL polynomial2 ) {
    
    polynomial = polynomial1;
    
    for (int i = 0; i < polynomial2.size; i++) {
        polynomial = poly_addterm(polynomial, - polynomial2.terms[i].coeff, polynomial2.terms[i].expo);
    }
    
    polynomial = sortTerms ( polynomial );
    
    return polynomial;
}

/**************************************************
 ** sortTerms -- help method
 **     This funtions sorts the polynomial based on
 ** the expo value, from highest to lowest
 **     Inputs: The polynomial to be sorted
 **     Output: The sorted polynomial is returned
 **************************************************/
static POLYNOMIAL sortTerms( POLYNOMIAL polynomial ) {
    
    int size = polynomial.size;
    TERM temp;
    
    for ( int b = 0; b < size - 1; b++) {
        for ( int n = 0; n < size - 1 - b; n++ ) {
            if ( polynomial.terms[n].expo < polynomial.terms[n + 1].expo ) {
                temp = polynomial.terms[ n + 1 ];
                polynomial.terms[ n + 1 ] = polynomial.terms[ n ];
                polynomial.terms[ n ] = temp;
            }
        }
    }
    
    return polynomial;
}

/**************************************************
 ** polyString --
 **     This funtions constructs a string that contains
 ** the readable polynomial withe x and ^
 **     Inputs: The polynomial and the Address to the 
 ** string to be contructed 
 **     Output: This changes the via the address
 **************************************************/
void polyString( POLYNOMIAL polynomial, char s[]) {
    
    int size = polynomial.size;
    sprintf(s," ");
    for (int i = 0; i < size; i++) {
        if (polynomial.terms[i].coeff != 0) {
            if (polynomial.terms[i].expo == 0 ) {
                if (polynomial.terms[i].coeff > 0 && i != 0 ) {
                    sprintf(&s[strlen(s)], " + ");
                }
                else if (i != 0) {
                
                }
            
                sprintf( &s[strlen(s)], "%d", polynomial.terms[i].coeff );
            } 
            else if (polynomial.terms[i].expo == 1) {
                if (polynomial.terms[i].coeff > 0 && i != 0) {
                    sprintf(&s[strlen(s)],  " + ");
                }
                else if (i != 0) {
                
                }
            
                sprintf( &s[strlen(s)], "%dx", polynomial.terms[i].coeff );
            }
            else if (polynomial.terms[i].expo > 1) {
                if (polynomial.terms[i].coeff > 0 && i != 0) {
                    sprintf(&s[strlen(s)], " + ");
                }
                else if (i != 0) {
                
                }
            
                sprintf( &s[strlen(s)], "%dx^%d", polynomial.terms[i].coeff, polynomial.terms[i].expo );
            }
        }
    }
}
            
        

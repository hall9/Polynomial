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

static POLYNOMIAL sortTerms( POLYNOMIAL polynomial );

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

POLYNOMIAL poly_multiply( POLYNOMIAL polynomial, int scalar ) {
    
    int size = polynomial.size;
    
    for(int i = 0; i < size; i++) {
        polynomial.terms[i].coeff = polynomial.terms[i].coeff * scalar;
    }
    
    polynomial = sortTerms ( polynomial );
    
    return polynomial;
}

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

POLYNOMIAL poly_subtract( POLYNOMIAL polynomial, POLYNOMIAL polynomial1, POLYNOMIAL polynomial2 ) {
    
    polynomial = polynomial1;
    
    for (int i = 0; i < polynomial2.size; i++) {
        polynomial = poly_addterm(polynomial, - polynomial2.terms[i].coeff, polynomial2.terms[i].expo);
    }
    
    polynomial = sortTerms ( polynomial );
    
    return polynomial;
}

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
            
        

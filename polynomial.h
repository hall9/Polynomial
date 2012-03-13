/*****************************************
 ** File: polynomial.h
 ** Author: Alexander D. Hall
 ** Date: 03/04/12
 ** Section: cs313-02 spring12
 ** E-mail: hall9@umbc.edu
 **
 **
 **
 ** Other Files requierd are
 ** 1. polynomail.c
 **
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXTERMS 20

typedef struct term {
    
    int coeff;
    int expo;
    
} TERM;

typedef struct polynomial {
    
    int size;
    TERM terms[MAXTERMS];
    
} POLYNOMIAL;

POLYNOMIAL poly_addterm ( POLYNOMIAL polynomial, int coeff, int expo );

POLYNOMIAL poly_multiply( POLYNOMIAL polynomial, int scalar );

POLYNOMIAL poly_adding( POLYNOMIAL polynomial, POLYNOMIAL polynomial1, POLYNOMIAL polynomial2 );

POLYNOMIAL poly_subtract( POLYNOMIAL polynomial, POLYNOMIAL polynomial1, POLYNOMIAL polynomial2 );

void polyString( POLYNOMIAL polynomial, char s[]);
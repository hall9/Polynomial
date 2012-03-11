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

#include "polynomial.h"

#define MAXterms 20
#define MAXpolynomials 8

typedef struct term {

    int coeff;
    int expo;
    
} term;

typedef struct polynomial {
    
    int size;
    term terms[MAXterms];
    
} polynomial;

polynomial polynomials[MAXpolynomials];


static void poly_addterm (int index, int coeff, int expo) {
    
}

static void poly_multiply(int index, int scalar) {
    
}

static void poly_adding(int index, int index1, int index2) {
    
}

static void poly_subtract(int index, int index1, int index2) {
    
}

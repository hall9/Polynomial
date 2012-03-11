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


void poly_addterm (int index, int coeff, int expo) {
    
    int size = polynomials[index].size;
    int newTerm = 1;
    
    for (int i = 0; i < size; i++) {
        if (polynomials[index].terms[i].expo == expo) {
            polynomials[index].terms[i].coeff += coeff;
            newTerm = 0;
        }
    }
    
    if(newTerm) {
        polynomials[index].terms[size].expo = expo;
        polynomials[index].terms[size].coeff = coeff;
        polynomials[index].size += 1;
    }
    
    printf("/////  polyIndex: %d, size: %d, coeff: %d, Expo: %d\n\n", index, size, polynomials[index].terms[size].coeff, polynomials[index].terms[size].expo );
}

void poly_multiply(int index, int scalar) {
    
     int size = polynomials[index].size;
    
    for(int i = 0; i < size; i++) {
        polynomials[index].terms[i].coeff = polynomials[index].terms[i].coeff * scalar;
    }
    
    printf("/////  polyIndex: %d, size: %d, coeff: %d, Expo: %d\n", index, size, polynomials[index].terms[0].coeff, polynomials[index].terms[0].expo );
    printf("/////  polyIndex: %d, size: %d, coeff: %d, Expo: %d\n", index, size, polynomials[index].terms[1].coeff, polynomials[index].terms[1].expo );
    printf("/////  polyIndex: %d, size: %d, coeff: %d, Expo: %d\n\n", index, size, polynomials[index].terms[2].coeff, polynomials[index].terms[2].expo );
}

void poly_adding(int index, int index1, int index2) {
    
    
    
}

void poly_subtract(int index, int index1, int index2) {
    
}

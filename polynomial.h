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

static void poly_addterm (int index, int coeff, int expo);

static void poly_multiply(int index, int scalar);

static void poly_adding(int index, int index1, int index2);

static void poly_subtract(int index, int index1, int index2);


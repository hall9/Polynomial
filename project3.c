/*****************************************
 ** File: project3.c
 ** Author: Alexander D. Hall
 ** Date: 03/04/12
 ** Section: cs313-02 spring12
 ** E-mail: hall9@umbc.edu
 **
 ** This file contails the main driver program for project 3.
 ** This program reads the file specified and reads each command in the file followed
 ** the command arugments. The commmand ADDs, Multiply, Subtrackts polynomials.
 **
 **
 ** Other Files requierd are
 ** 1. cmdFile - This file contains the commands and arugments for the program to preform
 ** 2. polynomial.h - The header file for polynomial.c
 ** 3. polynomial.c - This file contains the fuctions snd helper funtions for a polynomial
 **
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polynomial.h"

#define MAXCOMMANDLENGTH 10
#define MAXPOLYNOMIALS 8
#define MAXSTRINGLENGTH 101

POLYNOMIAL polynomials[MAXPOLYNOMIALS];


// These are Commands that main can perform
static char addterm[] = "ADDTERM";
static char multiply[] = "MULTIPLY";
static char adding[] = "ADD";
static char subtract[] = "SUBTRACT";

int main (int numb, char *argv[] ) {
     
    // Read in file through the command line and close program is file is invalid.
    FILE *cmdFile = fopen(argv[1], "r");
    if (cmdFile == NULL) {
        printf("Error opening file: %s\nThis file may not exst or is empty.\nExiting program now...\n", argv[1]);
        exit(-1);
    }
    
    //printf("Reading this file: %s\n", argv[1]);
    
    char command[MAXCOMMANDLENGTH];
    int index;
    int index1;
    int index2;
    int coeffient;
    int exponent;
    int scalar;
    char string[MAXSTRINGLENGTH];
    
    // Read each line until white space
    while ( fscanf(cmdFile, "%s", command) != EOF ) {
        
        // If the command == ADDTERM
        if ( strcmp(command, addterm) == 0) {
            
            // Take in the next 3 values
            fscanf(cmdFile, "%d", &index );
            fscanf(cmdFile, "%d", &coeffient );
            fscanf(cmdFile, "%d", &exponent );
            
            // Print what the command line wants to perform
            printf("CMD: %s, Poly: %d, Coeff: %d, EXP: %d\n", command, index, coeffient, exponent );
            
            // Addterm to this array of at location array index
            polynomials[index] = poly_addterm(polynomials[index], coeffient, exponent);
            
            // construct the polynomial string
            polyString(polynomials[index], string);
            printf("Poly%d =%s\n\n", index, string);
        }
        else if ( strcmp(command, multiply) == 0 ) {
            
            // Take in the next 2 values
            fscanf(cmdFile, "%d", &index );
            fscanf(cmdFile, "%d", &scalar );
            
            // Print what the command line wants to excute 
            printf("CMD: %s, Poly: %d, Multiplier: %d\n", command, index, scalar );
            
            // Stores the polynomial struct to this location in the array
            polynomials[index] = poly_multiply(polynomials[index], scalar);
            
            // construct the polynomial string and prints it
            polyString(polynomials[index], string);
            printf("Poly%d =%s\n\n", index, string);
        }
        else if ( strcmp(command, adding) == 0 ) {
            
            // Take in the next 3 values
            fscanf(cmdFile, "%d", &index );
            fscanf(cmdFile, "%d", &index1 );
            fscanf(cmdFile, "%d", &index2 );
            
            // Print what the command line wants to excute 
            printf("CMD: %s, Sum: %d, Op1: %d, Op2: %d\n", command, index, index1, index2 );
            
            polynomials[index] = poly_adding(polynomials[index], polynomials[index1], polynomials[index2]);
            
            // construct the polynomial string and prints it
            polyString(polynomials[index], string);
            printf("Poly%d =%s\n\n", index, string);
        }
        else if ( strcmp(command, subtract) == 0 ) {
            
            // Take in the next 3 values
            fscanf(cmdFile, "%d", &index );
            fscanf(cmdFile, "%d", &index1 );
            fscanf(cmdFile, "%d", &index2 );
            
            // Print what the command line wants to excute 
            printf("CMD: %s, Diff: %d, Op1: %d, Op2: %d\n", command, index, index1, index2 );
            
            polynomials[index] = poly_subtract(polynomials[index], polynomials[index1], polynomials[index2]);
            
            // construct the polynomial string and prints it
            polyString(polynomials[index], string);
            printf("Poly%d =%s\n\n", index, string);
        }
    }
    
    return 0;
}
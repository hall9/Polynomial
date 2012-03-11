/*****************************************
 ** File: project3.c
 ** Author: Alexander D. Hall
 ** Date: 03/04/12
 ** Section: cs313-02 spring12
 ** E-mail: hall9@umbc.edu
 **
 ** This file contails the main driver program for project 3.
 ** This program read the file specified and reads each command in the file followed
 ** the command arugments.
 **
 **
 ** Other Files requierd are
 ** 1. cmdFile - This file contains the commands and arugments for the program to preform
 **
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "polynomial.h"

#define MAXcommandlength 10

static char addterm[] = "ADDTERM";
static char multiply[] = "MULTIPLY";
static char adding[] = "ADD";
static char subtract[] = "SUBTRACT";

int main (int numb, char *argv[] ) {
     
    FILE *cmdFile = fopen(argv[1], "r");
    if (cmdFile == NULL) {
        printf("Error opening file: %s\nThis file may not exst or is empty.\nExiting program now...\n", argv[1]);
        exit(-1);
    }
    
    printf("Reading this file: %s\n", argv[1]);
    
    char command[MAXcommandlength];
    int index;
    int index1;
    int index2;
    int coeffient;
    int exponent;
    int scalar;
    
    while ( fscanf(cmdFile, "%s", command) != EOF ) {
        
        if ( strcmp(command, addterm) == 0) {
            
            fscanf(cmdFile, "%d", &index );
            fscanf(cmdFile, "%d", &coeffient );
            fscanf(cmdFile, "%d", &exponent );
            
            printf("%s, Poly: %d, Coeff: %d, EXP: %d\n", command, index, coeffient, exponent );
            
            poly_addterm(index, coeffient, exponent);
        }
        else if ( strcmp(command, multiply) == 0 ) {
            
            fscanf(cmdFile, "%d", &index );
            fscanf(cmdFile, "%d", &scalar );
            
            printf("%s, Poly: %d, Multiplier: %d\n", command, index, scalar );
            
            poly_multiply(index, scalar);
        }
        else if ( strcmp(command, adding) == 0 ) {
            
            fscanf(cmdFile, "%d", &index );
            fscanf(cmdFile, "%d", &index1 );
            fscanf(cmdFile, "%d", &index2 );
            
            printf("%s, Sum: %d, Op1: %d, Op2: %d\n", command, index, index1, index2 );
            
            poly_adding(index, index1, index2);
            
        }
        else if ( strcmp(command, subtract) == 0 ) {
            
            fscanf(cmdFile, "%d", &index );
            fscanf(cmdFile, "%d", &index1 );
            fscanf(cmdFile, "%d", &index2 );
            
            printf("%s, Diff: %d, Op1: %d, Op2: %d\n", command, index, index1, index2 );
            
            poly_subtract(index, index1, index2);
        }
    }
    
    return 0;
}
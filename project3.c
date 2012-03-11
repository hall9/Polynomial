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
#include "polynomial.h"

int main (int numb, char *argv[] ) {
     
    FILE *cmdFile = fopen(argv[1], "r");
    if (cmdFile == NULL) {
        printf("Error opening file: %s\nThis file may not exst or is empty.\nExiting program now...\n", argv[1]);
        exit(-1);
    }
    
    printf("%s/n", argv[1]);
    
    return 0;
}
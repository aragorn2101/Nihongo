/*
 *  nihongo.h
 *
 *  Header file for the C conversion program.
 *  Contains the character sets stored in global variables and function
 *  prototypes. A UTF-8 terminal/editor is required to use the programs and to
 *  read/modify this header file.
 *
 */


#ifndef NIHONGO_H
#define NIHONGO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAXDIGITS 19
// maximum number of digits in numbers
// largest number is 1,000,000,000,000,000,000
#define MAXNUM 1000000000000000000


/*  Function prototypes  */
/*  Source code in functions.c  */
int breakint (long, int *);
int convert_num2jap(long, char **);


/*  Definition of global variables  */
/*  Initialisation in global_charset.c  */
char *k_ones[10];
char *k_factors[2][5];
char *h_ones[10];
char *h_factors[23];

#endif

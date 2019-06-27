/*
 *  Program to exercise with random japanese numbers.
 *  --  UNDER DEVELOPMENT  --
 *
 *  Copyright (C) 2019 Nitish Ragoomundun, Mauritius
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

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
int breakint (long, int *);


/***  BEGIN Main Function  ***/
int main(int argc, char **argv)
{
  /*  Kanji character sets for numbers  */
  /*  Ones  */
  char *ones[10] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"} ;

  /*  Factors of 10  */
  char *factors[7] = {"十", "百", "千", "万", "億", "兆", "京"};


  /*  Initialise RNG  */
  srandom(time(0));

  /*  Set locale so that large numbers are printed in
      comma separated format  */
  setlocale(LC_NUMERIC, "");


  int i;
  long LowerLim, UpperLim, number;
  int digits[MAXDIGITS], numdigits;
  char ans;


  /***  BEGIN parse command line arguments  ***/

  if (argc <= 2)
  {
    printf("Usage: %s LOWERLIM UPPERLIM\n", argv[0]);
    printf("The program generates random numbers in a range delimitered by\n");
    printf("LOWERLIM and UPPERLIM. LOWERLIM cannot be smaller than 0 and\n");
    printf("UPPERLIM cannot be greater than %ld.\n\n", MAXNUM);
    exit(1);
  }

  LowerLim = atol(argv[1]);
  UpperLim = atol(argv[2]);

  if (LowerLim < 0 || UpperLim < 0 || UpperLim > MAXNUM)
  {
    printf("%s: Range must be between 0 and %ld.\n\n", argv[0], MAXNUM);
    exit(2);
  }

  if (LowerLim > UpperLim)
  {
    printf("%s: Lower limit cannot be greater than upper limit.\n\n", argv[0]);
    exit(3);
  }

  if (UpperLim - LowerLim < 100)
  {
    printf("%s: Range for repetitions cannot be less than 100.\n\n", argv[0]);
    exit(4);
  }

  /***  END parse command line arguments  ***/



  /***  BEGIN LOOP Exercise  ***/
  do
  {
    /*  Generate random number  */
    number = (long)((UpperLim - LowerLim)*(1.0*random()/RAND_MAX) + LowerLim);

    printf("\n-> Random number: %'17ld\n", number);

    /*  Separate every digit  */
    numdigits = breakint(number, digits);
    for (i=MAXDIGITS-1 ; i>=0 ; i--)
      printf(i == 0 ? "%d.\n" : "%d, ", digits[i]);
    printf("Number of digits in integer: %d\nTest kanji:\t0 : %s\t10**8 : %s\n", numdigits, ones[0], factors[4]);

    printf("\n");

    printf("\nPress ENTER to continue or enter 'q' or 'Q' to quit. ");
    scanf("%c", &ans);
  }
  while (ans != 'q' && ans != 'Q');
  /***  END LOOP Exercise  ***/


  printf("\n");
  return(0);
}
/***  END Main Function  ***/



/*
 *  Function to separate every digit in a number
 *
 *  x: input number,
 *  x_array: array of integers of length MAXDIGIT to hold every digit
 *           separately. Least significant number is in position 0.
 *
 *  Returns the number of digits in the integer number input.
 */
int breakint (long x, int *x_array)
{
  long i;
  int j, x_numdigits = 0;

  i = MAXNUM;
  j = MAXDIGITS - 1;

  do
  {
    x_array[j] = x / i;

    if (x_numdigits == 0 && x_array[j] != 0)
      x_numdigits = j + 1;

    x -= (x / i) * i;
    i /= 10;
  }
  while (--j >= 0);

  return(x_numdigits);
}

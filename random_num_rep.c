/*
 *  random_num_rep.c
 *
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


#include "nihongo.h"


/***  BEGIN Main Function  ***/
int main(int argc, char **argv)
{
  /*  Initialise RNG  */
  srandom(time(0));

  /*  Set locale so that large numbers are printed in
      comma separated format  */
  setlocale(LC_NUMERIC, "");

  int i, m, n;
  long LowerLim, UpperLim, number;
  char ans;

  char *k_number_ptr[MAXDIGITS * 2];
  char *h_number_ptr[MAXDIGITS * 2];


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

    /*  Convert western number to japanese number  */
    printf("Calling convert_num2jap ...\n");
    convert_num2jap(number, k_number_ptr, h_number_ptr, &m, &n);

    /*  Print  */
    printf("\n\t%'17ld\n", number);
    printf("\nPress ENTER to print the conversion.\n");
    getchar();

    printf("\t");
    for (i=m-1 ; i>=0 ; i--)
      printf("%s", k_number_ptr[i]);

    printf("\n");

    for (i=n-1 ; i>=0 ; i--)
      printf("%s", h_number_ptr[i]);

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

/*
 *  Program to exercise when learning japanese numbers.
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



int main(int argc, char **argv)
{
  /*  Initialise RNG  */
  srandom(time(0));

  /*  Set locale so that large numbers are printed in
      comma separated format  */
  setlocale(LC_NUMERIC, "");


  long LowerLim, UpperLim, number;
  char ans;


  /***  BEGIN parse command line arguments  ***/

  if (argc <= 2)
  {
    printf("Usage: %s LOWERLIM UPPERLIM\n", argv[0]);
    printf("The program generates random numbers in a range delimitered by\n");
    printf("LOWERLIM and UPPERLIM. LOWERLIM cannot be smaller than 0 and\n");
    printf("UPPERLIM cannot be greater than 10,000,000,000,000,000.\n\n");
    exit(1);
  }

  LowerLim = atol(argv[1]);
  UpperLim = atol(argv[2]);

  if (LowerLim < 0 || UpperLim < 0 || UpperLim > 10000000000000000)
  {
    printf("%s: Range must be between 0 and 10,000,000,000,000,000.\n\n", argv[0]);
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
    printf("\nPress ENTER to continue or enter 'q' or 'Q' to quit. ");
    scanf("%c", &ans);
  }
  while (ans != 'q' && ans != 'Q');
  /***  END LOOP Exercise  ***/


  printf("\n");
  return(0);
}

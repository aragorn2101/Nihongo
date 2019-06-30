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


/***  BEGIN Main Function  ***/
int main(int argc, char **argv)
{
  /*  Initialise RNG  */
  srandom(time(0));

  /*  Set locale so that large numbers are printed in
      comma separated format  */
  setlocale(LC_NUMERIC, "");

  int i, n;
  long LowerLim, UpperLim, number;
  char ans;

  char *k_number_ptr[MAXDIGITS * 2];


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
    n = convert_num2jap(number, k_number_ptr);

    /*  Print  */
    printf("\n\t%'17ld\n", number);
    printf("\nPress any key to print the conversion.\n");
    getchar();

    printf("\t");
    for (i=n-1 ; i>=0 ; i--)
      printf("%s", k_number_ptr[i]);

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
 *  Function to separate every digit in a number and
 *  store in an array of integers.
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



/*
 *  Function to convert an integer to a number written
 *  in japanese numerals.
 *
 *  number: input integer,
 *  num_ptr: array of pointers for holding the address to the japanese numerals
 *           required to express the input integer (must be at least twice as
 *           long as the number of digits in the input integer)
 *
 *  Returns the number of slots used in the num_ptr array.
 *
 */
int convert_num2jap(long number, char **num_ptr)
{
  int i, j, k, n;
  int digits[MAXDIGITS];
  int numdigits;

  /*  Separate every digit  */
  numdigits = breakint(number, digits);


  /***  BEGIN Convert western-arabic digits to japanese numerals  ***/
  n = 0;
  for (k=0 ; k<numdigits ; k++)
  {
    i = k/4;
    j = k%4;

    if (j == 0 && i != 0)
      num_ptr[n++] = k_factors[1][i];

    if (digits[k] != 0)
    {
      num_ptr[n++] = k_factors[0][j];

      if (j == 0 || digits[k] != 1)
        num_ptr[n++] = k_ones[digits[k]];
    }
  }
  /***  END Convert western-arabic digits to japanese numerals  ***/

  return(n);
}

/*
 *  Source file for the stand-alone functions.
 *
 */


#include "nihongo.h"


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
int convert_num2jap(long number, char **num_ptr, char **words_ptr)
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
    {
      num_ptr[n] = k_factors[1][i];
      words_ptr[n++] = h_factors[i+3];
    }

    if (digits[k] != 0)
    {
      num_ptr[n] = k_factors[0][j];
      words_ptr[n++] = h_factors[j];

      if (j == 0 || digits[k] != 1)
      {
        num_ptr[n] = k_ones[digits[k]];
        words_ptr[n++] = h_ones[digits[k]];
      }
    }
  }
  /***  END Convert western-arabic digits to japanese numerals  ***/

  return(n);
}

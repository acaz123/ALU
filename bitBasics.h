#ifndef BITBASICS_H_INCLUDED
#define BITBASICS_H_INCLUDED

#include <stdbool.h>


//sizeof(int) * CHAR_BIT
extern const int byteSize;


/** CONVERTS DECIMAL TO BINARY
 *
 * (char *cArray) - Char array the size of an int.
 *  each char in the array will be a '1' or '0' to
 * represent the binary valuer of "a".
 *
 * (int a) - integer to be the value of the binary
 * represented number in "cArray".
 *
 */

void decimalToBinary(char * cArray, int a);


/** CONVERTS BINARY TO DECIMAL
 *
 * (char *cArray) - char array of '1' and '0'
 *  only representing a binary value that will
 *  be converted to a decimal value.
 *
 * return - the decimal value of cArray of type
 * int
 */

int binaryToDecimal(char *cArray);


/** CHECKS FOR PROPER BINARY FORMAT
 *
 * (char *digits) - char array to be tested
 *  for proper format. Format should consist
 *  purely of '1' and/or '0' combinations. If
 *  the array is not of proper input an error
 *  message is printed to the "stderr". The
 *  program then exits with a status of -1.
 *
 */

void properInput(char *digit);


#endif // BITBASICS_H_INCLUDED

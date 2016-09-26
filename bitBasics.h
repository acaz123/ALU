#ifndef BITBASICS_H_INCLUDED
#define BITBASICS_H_INCLUDED

#include <stdbool.h>


extern const int byteSize;


/** CONVERTS DECIMAL TO BINARY
 *
 * "Binary_Array" - char array the size of an int.
 * each char in the array will be a '1' or '0' to
 * represent the binary valuer of the integer"a".
 *
 * "a" - decimal value to be converted into binary
 *
 */

void Decimal_To_Binary(char * Binary_Array, int a);




/** CONVERTS BINARY TO DECIMAL
 *
 * "Binary_Array" - char array of '1's and '0's
 * representing a binary value that will be converted
 * to a decimal value.
 *
 * return - integer that is the the decimal value
 * of "Binary_Array".
 */

int Binary_To_Decimal(char *Binary_Array);




/** CHECKS FOR PROPER BINARY FORMAT
 *
 *  "Binary_Array" - char array to be tested
 *  for proper format. Format should consist
 *  purely of '1's and/or '0's. If
 *  the array is not of proper input an error
 *  message is printed to the "stderr". The
 *  program then exits with a status of -1.
 *
 */

void Proper_Format(char *Binary_Array);


#endif // BITBASICS_H_INCLUDED

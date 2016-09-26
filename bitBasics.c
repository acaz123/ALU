#include "errno.h"
#include <stdio.h>
#include <stdlib.h>
#include "bitBasics.h"
#include "limits.h"

const int byteSize = sizeof(int) * CHAR_BIT;


/** CHECKS FOR PROPER BINARY FORMAT
 *
 *  checks the char array "digit" proper
 *  input of 1's and 0's to represent a
 *  binary number. Returns true for proper
 *  input, false for improper input.
 *
 */

void Proper_Format(char *Binary_Array)
{
    int i;

    for(i = 0; i < byteSize; i++)
    {
        if(Binary_Array[i] != '0' && Binary_Array[i] != '1'){
            fprintf(stderr, "Invalid binary representation");
            exit(-1);
        }
    }
}


/** CONVERTS DECIMAL TO BINARY ARRAY
 *
 * converts an integer to a char array
 * of '1's and '0's as a binary
 * representation of the decimal number
 * by bit shifting out the bits from the
 * integer. "Binary_Array" is tested for
 * proper format.
 *
 */

void Decimal_To_Binary(char *Binary_Array, int a)
{
    int i;

    for(i = 0; i < byteSize; i++)
        Binary_Array[i] = (1 & (a >> i)) ? '1':'0' ;

    Proper_Format(Binary_Array);
}



/** CONVERTS BINARY TO DECIMAL
 *
 * converts a char array representation
 * of a binary number to a decimal number
 * and stores the value in an integer.
 *
 */

int Binary_To_Decimal(char *Binary_Array)
{
    int i, total = 0, power = 1;

    for(i = 0;i < byteSize; i++){
            total += (Binary_Array[i] - '0') * power;
            power *= 2;
    }

    return total;
}



#include "errno.h"
#include <stdio.h>
#include <stdlib.h>
#include "bitBasics.h"
#include "limits.h"

const int byteSize = sizeof(int) * CHAR_BIT;



/** CONVERTS DECIMAL TO BINARY
 *
 * converts an integer to a char array
 * as a binary representation of the
 * decimal number by bit shifting out the
 * bits actually representing the integer
 *
 */

void decimalToBinary(char *cArray, int a)
{
    int i;
    for(i = 0; i < byteSize; i++)
        cArray[i] = (1 & (a >> i)) ? '1':'0' ;
    properInput(cArray);
    return cArray;
}



/** CONVERTS BINARY TO DECIMAL
 *
 * converts a char array representation
 * of a binary number to an integer
 * decimal representation. This is done
 * by iterating through the binary
 * representation and summing up the bits
 * decimal value in correspondence to its
 * power of 2 value.
 *
 */

int binaryToDecimal(char *cArray)
{
    int i, total = 0, power = 1;
    for(i = 0;i < byteSize; i++){
            total += (cArray[i] - 48) * power;
            power *= 2;
    }

    return total;
}



/** CHECKS FOR PROPER BINARY FORMAT
 *
 *  checks the char array "digit" proper
 *  input of 1's and 0's to represent a
 *  binary number. Returns true for proper
 *  input, false for improper input.
 *
 */

void properInput(char *digit)
{
    int i;
    for(i = 0; i < byteSize; i++)
    {
        if(digit[i] != '0' && digit[i] != '1'){
            fprintf(stderr, "Invalid binary representation");
            exit(-1);
        }
    }
    return true;
}


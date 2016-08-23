#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bitBasics.h"
#include "BitwiseOperations.h"


/** BITWISE AND OF TWO BINARY NUMBERS
 *
 * performs the bitwise AND of two
 * binary numbers represented as char
 * arrays of 1's and 0's.
 */

void BitwiseAND(char *a, char *b, char *result)
{
    properInput(a);properInput(b);

    int i;
    for(i = 0; i < byteSize; i++)
    {
        result[i] = (a[i] == b[i]) ? a[i] : '0';
    }
}



/** BITWISE OR OF TWO BINARY NUMBERS
 *
 * performs the bitwise OR of two
 * binary numbers represented as char
 * arrays of 1's and 0's.
 */

void BitwiseOR(char *a, char *b, char *result)
{
    properInput(a);properInput(b);

    int i;
    for(i = 0; i < byteSize; i++)
    {
        if(a[i] == '1' || b[i] == '1')
            result[i] = '1';
        else result[i] = '0';
    }
}



/** BITWISE EXCLUSIVE OR (XOR) OF TWO BINARY NUMBERS
 *
 * performs the bitwise XOR (exclusive OR)
 * of two binary numbers represented as
 * as char arrays of 1's and 0's.
 */

void BitwiseXOR(char *a, char *b, char *result)
{
    properInput(a);properInput(b);

    int i;
    for(i = 0; i < byteSize; i++)
        result[i] = (a[i] == b[i]) ? '0': '1';
}



/** ONES COMPLIMENT OF A BINARY NUMBER
 *
 * performs the bitwise 1's compliment,
 * also know as the negate, of two binary
 * numbers represented as char arrays
 * of 1's and 0's.
 */

void BitwiseONESCOMPLIMENT(char *a)
{
    properInput(a);
    int i;

    for(i = 0; i < byteSize; i++)
        a[i] = (a[i] == '0') ? '1' : '0' ;
}



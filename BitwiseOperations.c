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

void Bitwise_AND(char *X_Binary, char *Y_Binary, char *Z_Binary)
{
    Proper_Format(X_Binary);Proper_Format(Y_Binary);

    int i;

    for(i = 0; i < byteSize; i++)
        Z_Binary[i] = (X_Binary[i] == Y_Binary[i]) ? X_Binary[i] : '0';
}



/** BITWISE OR OF TWO BINARY NUMBERS
 *
 * performs the bitwise OR of two
 * binary numbers represented as char
 * arrays of 1's and 0's.
 */

void Bitwise_OR(char *X_Binary, char *Y_Binary, char *Z_Binary)
{
    Proper_Format(X_Binary);Proper_Format(Y_Binary);

    int i;
    for(i = 0; i < byteSize; i++)
    {
        if(X_Binary[i] == '1' || Y_Binary[i] == '1')
            Z_Binary[i] = '1';
        else Z_Binary[i] = '0';
    }
}



/** BITWISE EXCLUSIVE OR (XOR) OF TWO BINARY NUMBERS
 *
 * performs the bitwise XOR (exclusive OR)
 * of two binary numbers represented as
 * as char arrays of 1's and 0's.
 */

void Bitwise_XOR(char *X_Binary, char *Y_Binary, char *Z_Binary)
{
    Proper_Format(X_Binary);Proper_Format(Y_Binary);

    int i;
    for(i = 0; i < byteSize; i++)
        Z_Binary[i] = (X_Binary[i] == Y_Binary[i]) ? '0': '1';
}



/** ONES COMPLIMENT OF A BINARY NUMBER
 *
 * performs the bitwise 1's compliment,
 * also know as the negate, of two binary
 * numbers represented as char arrays
 * of 1's and 0's.
 */

void Bitwise_Ones_Compliment(char *X_Binary)
{
    Proper_Format(X_Binary);

    int i;

    for(i = 0; i < byteSize; i++)
        X_Binary[i] = (X_Binary[i] == '0') ? '1' : '0' ;
}



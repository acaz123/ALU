#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "bitBasics.h"
#include "BitwiseOperations.h"


/**
 * performs the bitwise AND of two
 * binary numbers represented as char
 * arrays of 1's and 0's. The result
 * is returned.
 */

char *BitwiseAND(char *a, char *b, char *result)
{
    properInput(a);properInput(b);

    int i;
    for(i = 0; i < byteSize; i++)
    {
        result[i] = (a[i] == b[i]) ? a[i] : '0';
    }
    return result;
}



/**
 * performs the bitwise OR of two
 * binary numbers represented as char
 * arrays of 1's and 0's. The result
 * is returned.
 */

char *BitwiseOR(char *a, char *b, char *result)
{
    properInput(a);properInput(b);

    int i;
    for(i = 0; i < byteSize; i++)
    {
        if(a[i] == '1' || b[i] == '1')
            result[i] = '1';
        else result[i] = '0';
    }

    return result;
}



/**
 * performs the bitwise XOR (exclusive OR)
 * of two binary numbers represented as
 * as char arrays of 1's and 0's. The
 *result is returned.
 */

char *BitwiseXOR(char *a, char *b, char *result)
{
    properInput(a);properInput(b);

    int i;
    for(i = 0; i < byteSize; i++)
        result[i] = (a[i] == b[i]) ? '0': '1';

    return result;
}



/**
 * performs the bitwise 1's compliment,
 * also know as the negate, of two binary
 * numbers represented as char arrays
 * of 1's and 0's. The result is returned.
 */

char *BitwiseONESCOMPLIMENT(char *a, char *result)
{
    properInput(a);

    int i;
    for(i = 0; i < byteSize; i++)
        result[i] = (a[i] == '0') ? '1' : '0' ;

    return result;
}



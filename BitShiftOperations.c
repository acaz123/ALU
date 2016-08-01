#include <stdio.h>
#include <stdlib.h>
#include "bitBasics.h"


/** LOGICAL LEFT SHIFT OF A BINARY NUMBER
 *
 * Performs a left logical shift to
 * the char array binary represented
 * number. The bits are moved "shifts"
 * amount of times to the left starting
 * at the left end (MSB). Once the right
 * end (LSB) is reached and shifted, the
 * remaining bits to the right of the
 * last shifted bit are set to '0'
 *
 */

void logicLS(char *a, int shifts)
{
    int i;
    for(i = byteSize - 1; i >= shifts; i--)
        a[i] = a[i-shifts];

    for(; i >= 0; i--)
        a[i] = '0';
}


/** LOGICAL RIGHT SHIFT OF A BINARY NUMBER
 *
 * Performs a right logical shift to
 * the char array binary represented number.
 * The bits are shifted "shifts" amount of
 * times to the right starting at the
 * right end (LSB). Once the left end
 * (MSB) is reached and shifted, the
 * remaining bits to the left of the
 * last shifted bit are set to '0'
 *
 */

void logicRS(char *a, int shifts)
{
    int i;
    for(i = 0; i < byteSize - shifts ; i++)
        a[i] = a[i + shifts];

    for(; i < byteSize; i++)
        a[i] = '0';
}


/** ARITHMETIC LEFT SHIFT OF A BINARY NUMBER
 *
 * Calls function "logicLS()" since they
 * are equivalent functions.
 *
 */

void arithmeticLS(char *a, int shifts)
{
    logicLS(a, shifts);
}



/** ARITHMETIC RIGHT SHIFT OF A BINARY NUMBER
 *
 * Performs a right arithmetic shift to
 * the char array binary represented number.
 * The bits are shifted "shifts" amount of
 * times to the right starting at the
 * right end (LSB). Once the left end
 * (MSB) is reached and shifted, the
 * remaining bits to the left of the
 * last shifted bit are set to the left
 * most bit (MSB).
 *
 */

void arithmeticRS(char *a, int shifts)
{
    int i;
    for(i = 0; i < byteSize - shifts ; i++)
        a[i] = a[i + shifts];

    for(; i < byteSize; i++)
        a[i] = a[byteSize - 1];
}


/** ROTATE LEFT WITH NO CARRY OF A BINARY NUMBER
 *
 * The left most bit(s) are stored in a temporary
 * array the size of "rotations. The char array
 * binary represented number is then logical left
 * shifted "rotations" amount of times using "logicLS()".
 * The bit(s) stored in the temp array are then added
 * as the right most bit(s) of the char array.
 *
 */

void rotateL(char * a, int rotations)
{
    int i, j;
    char temp[rotations];

    for(i = byteSize - 1, j = rotations - 1;
    i >= byteSize - rotations; i--, j--)
        temp[j] = a[i];

    logicLS(a, rotations);

    for(i = 0;i < rotations; i++)
        a[i] = temp[i];
}


/** ROTATE RIGHT WITH NO CARRY OF A BINARY NUMBER
 *
 * The right most bit(s) are stored in a temporary
 * array the size of "rotations. The char array
 * binary represented number is then logical right
 * shifted "rotations" amount of times using "logicRS()".
 * The bit(s) stored in the temp array are then added
 * as the left most bit(s) of the char array.
 *
 */

void rotateR(char * a, int rotations)
{
    int i, j;
    char temp[rotations];

    for(i = 0; i < rotations; i++)
        temp[i] = a[i];

    logicRS(a, rotations);

    for(i = byteSize - 1, j = rotations - 1;
    i >= byteSize - rotations; i--, j--)
        a[i] = temp[j];
}


/**
 *
 *
 */

void rotateLcarry(char * a, int rotations)
{

}


/**
 *
 *
 */

void rotateRcarry(char * a, int rotations)
{

}





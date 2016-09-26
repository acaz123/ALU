#include <stdio.h>
#include <stdlib.h>
#include "bitBasics.h"

///     MSB = Most Significant Bit
///     LSB = Least Significant Bit





/** LOGICAL LEFT SHIFT OF A BINARY NUMBER
 *
 * Performs a left logical shift to the
 * "Binary_Array". The bits are shifted
 * "shifts" amount of times to the
 * left starting at the left end (MSB).
 * Once the right end (LSB) is reached and
 * shifted, the remaining bits to the right
 * of the last shifted bit are set to '0'.
 *
 */

void Logic_Left_Shift(char *Binary_Array, int shifts)
{
    int i;

    for(i = byteSize - 1; i >= shifts; i--)
        Binary_Array[i] = Binary_Array[i-shifts];

    for(; i >= 0; i--)
        Binary_Array[i] = '0';
}




/** LOGICAL RIGHT SHIFT OF A BINARY NUMBER
 *
 * Performs a right logical shift to
 * "Binary_Array". The bits are shifted
 * "shifts" amount of times to the right
 * starting at the right end (LSB). Once
 * the left end (MSB) is reached and shifted,
 * the remaining bits to the left of the
 * last shifted bit are set to '0'
 *
 */

void Logic_Right_Shift(char *Binary_Array, int shifts)
{
    int i;

    for(i = 0; i < byteSize - shifts ; i++)
        Binary_Array[i] = Binary_Array[i + shifts];

    for(; i < byteSize; i++)
        Binary_Array[i] = '0';
}




/** ARITHMETIC LEFT SHIFT OF A BINARY NUMBER
 *
 * Calls function "Logic_Left_Shift()" since they
 * are equivalent functions.
 *
 */

void Arithmetic_Left_Shift(char *Binary_Array, int shifts)
{
    Logic_Left_Shift(Binary_Array, shifts);
}



/** ARITHMETIC RIGHT SHIFT OF A BINARY NUMBER
 *
 * Performs a right arithmetic shift to
 * the "Binary_Array". The bits are shifted
 * "shifts" amount of times to the right
 * starting at the right end (LSB). Once the
 * left end (MSB) is reached and shifted, the
 * remaining bits to the left of the
 * last shifted bit are set to the left
 * most bit (MSB).
 *
 */

void Arithmetic_Right_Shift(char *Binary_Array, int shifts)
{
    int i;

    for(i = 0; i < byteSize - shifts ; i++)
        Binary_Array[i] = Binary_Array[i + shifts];

    for(; i < byteSize; i++)
        Binary_Array[i] = Binary_Array[byteSize - 1];
}


/** ROTATE LEFT WITH NO CARRY
 *
 * The left most bit(s) (MSB's) are stored in a temporary
 * array the size of "rotations. "Binary_Array" is
 * then logical left shifted "rotations" amount of
 * times using "Logic_Left_Shift()". The bit(s)
 * stored in the temp array are then added
 * as the right most bit(s) (LSB's) of the char array.
 *
 */

void Rotate_Left(char * Binary_Array, int rotations)
{
    int i, j;
    char temp[rotations];

    for(i = byteSize - 1, j = rotations - 1;
    i >= byteSize - rotations; i--, j--)
        temp[j] = Binary_Array[i];

    Logic_Left_Shift(Binary_Array, rotations);

    for(i = 0;i < rotations; i++)
        Binary_Array[i] = temp[i];
}


/** ROTATE RIGHT WITH NO CARRY OF A BINARY NUMBER
 *
 * The right most bit(s) (LSB's) are stored in a
 * temporary array the size of "rotations.
 * "Binary_Array" is then logical right shifted
 * "rotations" amount of times using
 * "Logic_Right_Shift()". The bit(s) stored in
 * the temp array are then added as the left most
 * bit(s) (MSB's) of the char array.
 *
 */

void Rotate_Right(char * Binary_Array, int rotations)
{
    int i, j;
    char temp[rotations];

    for(i = 0; i < rotations; i++)
        temp[i] = Binary_Array[i];

    Logic_Right_Shift(Binary_Array, rotations);

    for(i = byteSize - 1, j = rotations - 1;
    i >= byteSize - rotations; i--, j--)
        Binary_Array[i] = temp[j];
}


/**
 *
 *
 */

void Rotate_Left_Carry(char *Binary_Array, int rotations)
{

}


/**
 *
 *
 */

void Rotate_Right_Carry(char *Binary_Array, int rotations)
{

}





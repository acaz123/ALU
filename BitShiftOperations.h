#ifndef BITSHIFTOPERATIONS_H_INCLUDED
#define BITSHIFTOPERATIONS_H_INCLUDED

/** ARITHMETIC LEFT SHIFT OF A BINARY NUMBER
 *
 * "Binary_Array" - char array of '1's and/or '0's
 *  representing a binary number.
 *
 * "shifts" - number of times the array is to
 *  be shifted.
 *
 */

void Arithmetic_Left_Shift(char *Binary_Array, int shifts);




/** ARITHMETIC RIGHT SHIFT OF A BINARY NUMBER
 *
 * "Binary_Array - char array of '1's and/or '0's
 *  representing a binary number.
 *
 * "shifts" - number of times the array is to
 *  be shifted.
 *
 */

void Arithmetic_Right_Shift(char *Binary_Array, int shifts);




/** LOGICAL LEFT SHIFT OF A BINARY NUMBER
 *
 * "Binary_Array - char array of '1's and/or '0's
 *  representing a binary number.
 *
 * "shift" - number of times the array is to
 *  be shifted.
 *
 */

void Logic_Left_Shift(char *Binary_Array, int shifts);




/** LOGICAL RIGHT SHIFT OF A BINARY NUMBER
 *
 * "Binary_Array" - char array of '1's and/or '0's
 *  representing a binary number.
 *
 * "shifts" - number of times the array is to
 *  be shifted.
 *
 */

void Logic_Right_Shift(char *Binary_Array, int shifts);




/** ROTATE LEFT WITH NO CARRY OF A BINARY NUMBER
 *
 * "Binary _Array" - char array of '1's and/or '0's
 *  representing a binary number.
 *
 * "rotations" - number of times the array is to
 *  be rotated.
 *
 */

void Rotate_Left(char * Binary_Array, int rotations);




/** ROTATE RIGHT WITH NO CARRY OF A BINARY NUMBER
 *
 * "Binary_Array" - char array of '1's and/or '0's
 *  representing a binary number.
 *
 * "rotations" - number of times the array is to
 *  be rotated.
 *
 */

void Rotate_Right(char *Binary_Array, int rotations);


/** UNIMPLEMENTED
 *
 */

void Rotate_Left_Carry(char * Binary_Array, int rotations);


/** UNIMPLEMENTED
 *
 */

void Rotate_Right_Carry(char * Binary_Array, int rotations);

#endif // BITSHIFTOPERATIONS_H_INCLUDED

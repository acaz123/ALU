#ifndef BITSHIFTOPERATIONS_H_INCLUDED
#define BITSHIFTOPERATIONS_H_INCLUDED

/** ARITHMETIC LEFT SHIFT OF A BINARY NUMBER
 *
 * (char *a) - char array of '1' and/or '0' characters
 *  only to represent a binary number.
 *
 * (int shifts) - number of times the array is to
 *  be shifted.
 *
 */

void arithmeticLS(char *a, int shifts);


/** ARITHMETIC RIGHT SHIFT OF A BINARY NUMBER
 *
 * (char *a) - char array of '1' and/or '0' characters
 *  only to represent a binary number.
 *
 * (int shifts) - number of times the array is to
 *  be shifted.
 *
 */

void arithmeticRS(char *a, int shifts);


/** LOGICAL LEFT SHIFT OF A BINARY NUMBER
 *
 * (char *a) - char array of '1' and/or '0' characters
 *  only to represent a binary number.
 *
 * (int shifts) - number of times the array is to
 *  be shifted.
 *
 */

void logicLS(char *a, int shifts);


/** LOGICAL RIGHT SHIFT OF A BINARY NUMBER
 *
 * (char *a) - char array of '1' and/or '0' characters
 *  only to represent a binary number.
 *
 * (int shifts) - number of times the array is to
 *  be shifted.
 *
 */

void logicRS(char *a, int shifts);


/** ROTATE LEFT WITH NO CARRY OF A BINARY NUMBER
 *
 * (char *a) - char array of '1' and/or '0' characters
 *  only to represent a binary number.
 *
 * (int rotations) - number of times the array is to
 *  be rotated.
 *
 */

void rotateL(char * a, int rotations);


/** ROTATE RIGHT WITH NO CARRY OF A BINARY NUMBER
 *
 * (char *a) - char array of '1' and/or '0' characters
 *  only to represent a binary number.
 *
 * (int rotations) - number of times the array is to
 *  be rotated.
 *
 */

void rotateR(char *a, int rotations);


/** UNIMPLEMENTED
 *
 */

void rotateLcarry(char * a, int rotations);


/** UNIMPLEMENTED
 *
 */

void rotateRcarry(char * a, int rotations);

#endif // BITSHIFTOPERATIONS_H_INCLUDED

#ifndef BITWISEOPERATIONS_H_INCLUDED
#define BITWISEOPERATIONS_H_INCLUDED

/** BITWISE AND OF TWO BINARY NUMBERS
  *
  * (char *a) - char array of '1'
  *  and/or '0' characters only to represent
  *  a binary number. First array to be
  *  ANDed with the second.
  *
  * (char *b) - char array of '1'
  *  and/or '0' characters only to represent
  *  a binary number. Second array to be
  *  ANDed with the first.
  *
  * (char *results) - char array of '1'
  *  and/or '0' characters only to represent
  *  a binary number. Array where the AND
  *  results from "a" and "b" will be stored.
  *
*/
void BitwiseAND(char *a, char *b, char *result);


/** BITWISE OR OF TWO BINARY NUMBERS
  *
  * (char *a) - char array of '1'
  *  and/or '0' characters only to represent
  *  a binary number. First array to be
  *  ORed with the second.
  *
  * (char *b) - char array of '1'
  *  and/or '0' characters only to represent
  *  a binary number. Second array to be
  *  ORed with the first.
  *
  * (char *results) - char array of '1'
  *  and/or '0' characters only to represent
  *  a binary number. Array where the OR
  *  results from "a" and "b" will be stored.
  *
*/
void BitwiseOR(char *a, char *b, char *result);


/** BITWISE XOR OF TWO BINARY NUMBERS
  *
  * (char *a) - char array of '1'
  *  and/or '0' characters only to represent
  *  a binary number. First array to be
  *  exclusive ORed with the second.
  *
  * (char *b) - char array of '1'
  *  and/or '0' characters only to represent
  *  a binary number. Second array to be
  *  exclusive ORed with the first.
  *
  * (char *results) - char array of '1'
  *  and/or '0' characters only to represent
  *  a binary number. Array where the exclusive
  *  OR results from "a" and "b" will be stored.
  *
*/
void BitwiseXOR(char *a, char *b, char *result);


/** ONES COMPLIMENT OF A BINARY NUMBER
 *
 * (char *a) - char array of '1'
 *  and/or '0' characters only to represent
 *  a binary number. Array to be negated (1's
 * compliment).
 *
 * (char *results) - char array of '1'
 *  and/or '0' characters only to represent
 *  a binary number. Array where the
 * 1's compliment will be stored.
 *
 */

void BitwiseONESCOMPLIMENT(char *a);

#endif // BITWISEOPERATIONS_H_INCLUDED

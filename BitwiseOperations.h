#ifndef BITWISEOPERATIONS_H_INCLUDED
#define BITWISEOPERATIONS_H_INCLUDED

/** BITWISE AND OF TWO BINARY NUMBERS
  *
  *  "X_Binary" - char array of '1's
  *  and/or '0's representing a binary
  *  number. First array to be ANDed
  *  with the second.
  *
  *  "Y_Binary" - char array of '1's
  *  and/or '0's representing a binary
  *  number. Second array to be ANDed
  *  with the first.
  *
  *  "Z_Binary" - char array of '1's
  *  and/or '0's representing a binary
  *  number. Array where the AND
  *  results from "X_Binary" and
  *  "Y_Binay" will be stored.
  *
*/
void Bitwise_AND(char *X_Binary, char *Y_Binary, char *Z_Binary);


/** BITWISE OR OF TWO BINARY NUMBERS
  *
  *  "X_Binary" - char array of '1's
  *  and/or '0's representing a binary
  *  number. First array to be ORed
  *  with the second.
  *
  *  "Y_Binary" - char array of '1's
  *  and/or '0's representing a binary
  *  number. Second array to be ORed
  *  with the first.
  *
  *  "Z_Binary" - char array of '1's
  *  and/or '0's representing a binary
  *  number. Array where the OR
  *  results from "X_Binary" and
  *  "Y_Binay" will be stored.
  *
*/
void Bitwise_OR(char *X_Binary, char *Y_Binary, char *Z_Binary);


/** BITWISE XOR OF TWO BINARY NUMBERS
  *
  *  "X_Binary" - char array of '1's
  *  and/or '0's representing a binary
  *  number. First array to be XORed
  *  (exclusive ORed) with the second.
  *
  *  "Y_Binary" - char array of '1's
  *  and/or '0's representing a binary
  *  number. Second array to be XORed
  *  (exclusive ORed) with the first.
  *
  *  "Z_Binary" - char array of '1's
  *  and/or '0's representing a binary
  *  number. Array where the XOR
  *  (exclusive OR) results from
  *  "X_Binary" and "Y_Binay" will be
  *  stored.
  *
*/
void Bitwise_XOR(char *X_Binary, char *Y_Binary, char *Z_Binary);


/** ONES COMPLIMENT OF A BINARY NUMBER
 *
 * "X_Binary" - char array of '1's
 * and/or '0's representing a binary
 * number. Array to be negated (1's
 * compliment).
 *
 */

void Bitwise_Ones_Compliment(char *X_Binary);

#endif // BITWISEOPERATIONS_H_INCLUDED

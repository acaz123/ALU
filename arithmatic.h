#ifndef ARITHMATIC_H
#define ARITHMATIC_H


/** MULTIPLY "NUMB" BY -1
 *
 * "numb" - char array of '0's and '1's
 * representing a binary number.
 *
 */

void Bitwise_Twos_Compliment(char *numb);




/** A + B = RESULT
 *
 * "a" char array of '0's and '1's
 * representing a binary number.
 * First number to be summed.
 *
 * "b" char array of '0's and '1's
 * representing a binary number.
 * Second number to be summed.
 *
 * "result" char array of '0's and '1's
 * representing a binary number. Set to
 * the sum of "a" and "b".
 *
 */

void Addition(char *a, char *b, char *result);




/** A - B = RESULT
 *
 * "a" char array of '0's and '1's
 * representing a binary number.
 *
 * "b" char array of '0's and '1's
 * representing a binary number.
 *
 * "result" char array of '0's and '1's
 * representing a binary number. Set to
 * the result of "a" minus "b".
 *
 */

void Subtraction(char *a, char *b, char *result);




/** A * B = RESULT
 *
 * "a" char array of '0's and '1's
 * representing a binary number.
 * First number to be multiplied.
 *
 * "b" char array of '0's and '1's
 * representing a binary number.
 * Second number to be multiplied.
 *
 * "result" char array of '0's and '1's
 * representing a binary number. Set to
 * the result of "a" multiplied by "b".
 *
 */
void Multiplication(char *a, char *b, char *result);



/// /////////////NEED TO DECIDE ABOUT REMAINDER/////////////////////

/** A / B = RESULT
 *
 * "a" char array of '0's and '1's
 * representing a binary number.
 *
 * "b" char array of '0's and '1's
 * representing a binary number.
 *
 * "result" char array of '0's and '1's
 * representing a binary number. Set to
 * the division of "a" divided by "b".
 *
 */
void Division(char *a, char *b, char *result);


#endif // ARITHMATIC_H

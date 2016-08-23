#include "arithmatic.h"
#include "BitwiseOperations.h"
#include "BitShiftOperations.h"
#include "bitBasics.h"


char half_adder_bit(char a, char b)
{
    int A = a - '0';
    int B = b - '0';

    return (A ^ B) ? '1' : '0';
}

char half_adder_carry_bit(char a, char b)
{
    int A = a - '0';
    int B = b - '0';

    return (A && B) ? '1' : '0';
}
/** \brief
 *
 * should add default parameter to exit program
 * or print error message. Possible assert();
 *
 * should also put default return to get ride
 * of warnings.
 *
 */

char full_adder_bit(char a, char b, char c)
{
    int value = a - '0' + b - '0' + c - '0';
    switch(value)
    {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '0';
        case 3:
            return '1';
    }
}

char full_adder_carry_bit(char a, char b, char c)
{
    int value = a - '0' + b - '0' + c - '0';
    switch(value)
    {
        case 0:
            return '0';
        case 1:
            return '0';
        case 2:
            return '1';
        case 3:
            return '1';
    }
}

/** Performs same operations as a full adder in hardware
 *
 *
 */

void fullAdder(char *a, char *b, char *result)
{
    int carry = 0, i, sum = 0;
    for(i = 0; i < byteSize; i++)
    {
        sum = a[i] - '0' + b[i] - '0' + carry;
        switch (sum)
        {
            case 0:
                result[i] = '0';
                break;
            case 1:
                result[i] = '1';
                carry = 0;
                break;
            case 2:
                result[i] = '0';
                carry = 1;
                break;
            case 3:
                result[i] = '1';
                carry = 1;
                break;
        }
    }
}

/** Adds one to the value of the binary char array
 *
 * creates a temporary array then calls function
 * "decimalToBinary() to give the temporary array
 * a value of 1. The temporary array is then added
 * to the value passed in.
 *
 */

void addOne(char *numb)
{
    char temp[byteSize];
    decimalToBinary(temp, 1);
    fullAdder(numb, temp, numb);
}


/** Changes the value of numb to its negative
 *
 * performs the bitwise compliment of the
 * array passed in. Then adds one.
 *
 */

void negativeNumber(char *numb)
{
    BitwiseONESCOMPLIMENT(numb);
    addOne(numb);
}

/** subtracts "b" from "a". Stores answer in "result"
 *
 * changes "b" into it's negative then adds the
 * Two numbers using "fullAdder()"
 */

void subtraction(char *a, char *b, char *result)
{
    negativeNumber(b);
    fullAdder(a, b, result);
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void binary_multiply(char *a, char *b, char **wallace_Matrix)
{
    int i, j;
    for(i = 0; i < byteSize; i++)
        for(j = 0; j < byteSize; j++)
            wallace_Matrix[i][i+j] = (a[j] == '1') ? b[j]: '0';
}


/** Sets all chars inside matrix to '0'
 *
 * should add "try catch" block for potential
 * out of bounds attempts for matrix.
 */

void set_Matrix_Empty(char (*matrix)[byteSize])
{
    int i, j;///look at last bookmark saved internet
    for(i = 0; i < byteSize; i++)
        for(j = 0; j < 2*byteSize; j++)
            matrix[i][j] = '0';
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void multiplication(char *a, char *b, char *result)
{
    int depth = byteSize;
    char wallace_Matrix[byteSize][2*byteSize];

    set_Matrix_Empty(wallace_Matrix);
    binary_multiply(a, b, wallace_Matrix);

    while(depth > 1){
    ///AND into new matrix (repeat)  int AND_matrix(char **wallace_Matrix){return depth;}
    ///depth = AND_matrix(wallace_Matrix);
    }
    ///result = wallace_Matrix first row
}



void division(char *a, char *b, char *result)
{

}

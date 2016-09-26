#include "arithmatic.h"
#include "BitwiseOperations.h"
#include "BitShiftOperations.h"
#include "bitBasics.h"
#include "errno.h"
#include "DaddaMultiply.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Adders.h"
#include <string.h>


/** MULTIPLY NUMBER BY -1
 *
 * Negates "numb" by calling "Bitwise_Ones_Compliment()
 * then adds one by calling "Add_One() effectively
 * performing the bitwise two's compliment of the
 * binary number.
 *
 */

void Bitwise_Twos_Compliment(char *numb)
{
    Bitwise_Ones_Compliment(numb);
    Add_One(numb);
}

/** A - B = RESULT
 *
 * changes "b" into it's negative by calling
 * "Bitwise_Twos_Compliment()". Then adds the
 * Two numbers using "Full_Adder_Array()"
 */

void Subtraction(char *a, char *b, char *result)
{
    Bitwise_Twos_Compliment(b);
    Full_Adder_Array(a, b, result);
}




/** A + B = RESULT
 *
 * Calls function Full_Adder_Array() to
 * perform addition.
 *
 */

 void Addition(char *a, char *b, char *result)
 {
     Full_Adder_Array(a, b, result);
 }




/** A * B = RESULT
 *
 * This function calls a series of other functions
 * resulting in multiplication performed the same
 * way a Dadda Multiplier circuit would.
 *
 */

void Multiplication(char *a, char *b, char *result)
{
    int depth = byteSize;
    char **Dadda_Matrix = (char**)Allocate_Matrix(byteSize, 2 * byteSize - 1);

    Set_Matrix_Empty(Dadda_Matrix, byteSize, 2 * byteSize - 1);
    Binary_Long_Multiplication(a, b, Dadda_Matrix);

    Print_Matrix(Dadda_Matrix);
    while(depth > 2)
    {
     depth = Reduce_Dadda_Matrix(Dadda_Matrix, depth);
     Print_Matrix(Dadda_Matrix);
    }

    Reduce_Dadda_Matrix(Dadda_Matrix, 1);
    Print_Matrix(Dadda_Matrix);

    Set_Result_From_Matrix(Dadda_Matrix, result);
    Free_Matrix(Dadda_Matrix, byteSize);
}




void Division(char *a, char *b, char *result)
{

}

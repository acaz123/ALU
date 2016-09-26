#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "DaddaMultiply.h"
#include "bitBasics.h"
#include "Adders.h"

///For storing binary long multiplication in proper
///format to a dadda tree matrix
#define DADDA_FORMAT(i, j)(i - ( (i+j)%(byteSize-1) * ((i+j)/(byteSize-1)) ))

#define BASE_HEIGHT 2
#define Prev_Wires 0
#define Next_Wires 1
#define Half_Inputs 2
#define Full_Inputs 3




/** ALLOCATE MEMORY FOR MATRIX
 *
 * Allocates a 2d char array to be used
 * as the DADDA tree for multiplication
 * returns a pointer to the memory block.
 *
 */

 char** Allocate_Matrix(int Height, int Width)
 {
    int i;

    char **this = (char**)malloc(Height * sizeof(char*));
    assert(this != NULL);

    for(i = 0; i < Height; i++)
    {
        this[i] = (char*)malloc(Width * sizeof(char));
        assert(this[i] != NULL);
    }

    return this;
 }




 /** FREE ALLOCATED MEMORY OF "Matrix"
  *
  */

void Free_Matrix(char **Matrix, int Height)
{
    int i;

    for(i = 0; i < Height; i++)
        free(Matrix[i]);

    free(Matrix);
}




/** SET ALL ELEMENTS OF MATRIX TO '-' (EMPTY)
 *
 * Possibly add error handling for potential
 * out of bounds exceptions.
 */

void Set_Matrix_Empty(char **Matrix, int Height, int Width)
{
    int i;
    for(i = 0; i < Height; i++)
        memset(Matrix[i], '-', Width);
}




/** PRINT "Overflow_Matrix"
 *
 * Used in testing
 *
 */

void Print_Overflow(char **Overflow_Wires)
{
    int i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < byteSize; j++)
            printf("%c", Overflow_Wires[i][j]);
        printf("\n");
    }
}




/** PERFORMS LONG MULTIPLICATION
 *
 * Performs the long multiplication of "a" and "b".
 * The result is stored inside "Dadda_Matrix".
 * It is important to note the product of "a" and
 * "b" is not stored in the matrix, only the long
 * multiplication.
 *
 */

void Binary_Long_Multiplication(char *a, char *b, char **Dadda_Matrix)
{
    int i, j;

    for(i = 0; i < byteSize; i++){
        for(j = 0; j < byteSize - 1; j++)
            Dadda_Matrix[ DADDA_FORMAT(i, j) ][i+j] = (a[i] == '1') ? b[j]: '0';
        /// ////////////////////////////////////////////////
        ///Special end case formula does not work for///////
        Dadda_Matrix[0][i+j] = (a[i] == '1') ? b[j]: '0';///
        /// ////////////////////////////////////////////////
    }
}




/** GET RECUCTION HEIGHT FOR DADDA ALGORITHM
 *
 * Uses the formula d(j+1) = 1.5 * dj. Formula
 * is predefined as part of Dadda Algorithm.
 *
 */

int Get_Reduction_Height(int Height)
{
    /// //////////////////////////////////////////////////////////
    if(Height == 1)return Height;  ///NOT PART OF ALGORITHM!!!////
    /// //////////////////////////////used for final AND after////
                                   ///reductions have finished////
                                   /// ///////////////////////////
    int Reduction_Height, Next_Height = BASE_HEIGHT;

    while(Next_Height < Height)
    {
        Reduction_Height = Next_Height;
        Next_Height *= 1.5;
    }

    return Reduction_Height;
}




/** COUNT HOW MANY BITS IN "inputs"
 *
 * Iterates through "inputs" while bits
 * are found. Stops iterating once a bit
 * is not found and returns the index
 * value, which is equal to the count
 * of bits.
 *
 */

int Count_Bits(char *inputs, int max)
{
    int i;

    for(i = 0; i < max; i++)
        if(inputs[i] != '0' && inputs[i] != '1')
            break;

    return i;
}




/** "TRUE" IF BITS IN "Overflow_Wires[Prev]" ELSE "FALSE"
 *
 * Iterates through "Overflow_Wires[Prev]" in search of
 * a bit. Returns "true" if a bit is found. Returns "false"
 * otherwise
 *
 */

bool Bits_In_Overflow(char **Overflow_Wires)
{
    int i;

    for(i = 0; i < byteSize; i++)
        if(Overflow_Wires[Prev_Wires][i] != '-')
            return true;

    return false;

}




/** APPEND A CHAR TO END OF "Overflow_Wires[Prev_Wires]"
 *
 * Starts at the beginning of "Overflow_Wires[Prev_Wires]"
 * and iterates through till '-' is found. It is then
 * replaced with "c".
 *
 */

void Append_Overflow_Prev(char **Overflow_Wires, char c)
{
    int i;

    for(i = 0; i < byteSize; i++)
        if(Overflow_Wires[Prev_Wires][i] == '-')
        {
            Overflow_Wires[Prev_Wires][i] = c;
            break;
        }
}




/** APPEND A CHAR TO END OF "Overflow_Wires[Next_Wires]"
 *
 * Starts at the beginning of "Overflow_Wires[Next_Wires]"
 * and iterates through till '-' is found. It is then
 * replaced with "c".
 *
 */

void Append_Overflow_Next(char **Overflow_Wires, char c)
{
    int i;

    for(i = 0; i < byteSize; i++)
        if(Overflow_Wires[Next_Wires][i] == '-')
        {
            Overflow_Wires[Next_Wires][i] = c;
            break;
        }
}




/** GET OVERFLOW BITS FROM PREVIOUS CALCULATIONS
 *
 * "Overflow_Wires[Prev_Wires]" has all overflow
 * bits from the previous column's calculations,
 * if any. This function iterates through the
 * Overflow_Wires[Prev_Wires] to find any bits.
 * If a bit is found, stored in "inputs" then set
 * to '-' in Overflow_Wires[Prev_Wires]. If
 * "Bits_Needed" amount of bits are found and stored
 * into "inputs" the function will return.
 *
 */

void Get_Bits_From_Overflow(char **Overflow_Wires, char *inputs, int Bits_Needed)
{
    int i, count;
    count = Count_Bits(inputs, Bits_Needed);

    for(i = byteSize - 1; i >=0; i--)
    {
        if(Overflow_Wires[Prev_Wires][i] != '-')
        {
            inputs[count] = Overflow_Wires[Prev_Wires][i];
            Overflow_Wires[Prev_Wires][i] = '-';
            count++;
        }

        if(count == Bits_Needed)
            break;
    }
}




/** GET SUM BIT FOR AN ADDITION OF 2 OR 3 BITS
 *
 * The bits in "inputs" is counted. The bits are
 * then sent to a Half or Full Adder depending on
 * how many bits there are. The sum bit from
 * addition is returned.
 *
 */

char Get_Sum_Bit(char *inputs, int Bits_Needed)
{
    char Sum;

    if(Bits_Needed == Full_Inputs)
    {
        Sum = Full_Adder_Sum_Bit(inputs[0], inputs[1], inputs[2]);
        return Sum;
    }

    if(Bits_Needed == Half_Inputs)
    {
        Sum = Half_Adder_Sum_Bit(inputs[0], inputs[1]);
        return Sum;
    }
}




/** GET CARRY BIT FOR AN ADDITION OF 2 OR 3 BITS
 *
 * The bits in "inputs" is counted. The bits are
 * then sent to a Half or Full Adder depending on
 * how many bits there are. The carry bit from
 * addition is returned.
 *
 */

char Get_Carry_Bit(char *inputs, int Bits_Needed)
{
    char Carry;

    if(Bits_Needed == Full_Inputs)
    {
        Carry = Full_Adder_Carry_Bit(inputs[0], inputs[1], inputs[2]);
        return Carry;
    }

    if(Bits_Needed == Half_Inputs)
    {
        Carry = Half_Adder_Carry_Bit(inputs[0], inputs[1]);
        return Carry;
    }
}




/** ADD BITS IN COLUMN AND REPLACE WITH THEIR SUM
 *
 * Starts at the bottom of the column until a valid bit is
 * found. That bit is temporarily stored in "inputs" for use
 * in an adder. The bit in the column is replace with a '-'
 * meaning an empty slot. Once "Bits_Needed" amount of bits
 * are removed from the column they are added. The sum bit is
 * appended as the last bit in the column. The carry bit is
 * returned.
 *
 */

char Add_Bits_In_Column(char **Dadda_Matrix, int Column,  char *inputs, int Bits_Needed)
{
    char Carry;
    int i, count;
    count = Count_Bits(inputs, Bits_Needed);

    for(i = byteSize - 1; i >=0; i--)
    {
        if(Dadda_Matrix[i][Column] != '-')
        {
            inputs[count] = Dadda_Matrix[i][Column];
            Dadda_Matrix[i][Column] = '-';
            count++;
        }

        if(Bits_Needed == count){
            Carry = Get_Carry_Bit(inputs, Bits_Needed);
            Dadda_Matrix[i][Column] = Get_Sum_Bit(inputs, Bits_Needed);
            return Carry;
        }
    }
}




/** ADD BITS IN COLUMN
 *
 * First gets bits, if any, from "Overflow_Wires" "Prev_Wires"
 * Column. "Prev_Wires" column are carry bits from adds done
 * in the previous column. If there are 3 or more bits in
 * "Prev_Wires" column they are added and the sum bit is put
 * back in the column so the process can be repeated. Once the
 * "Prev_Wires" column is empty, bits in the matrix column will
 * be added with the sum bit restored in the column.
 *
 * This Full Adder is called when a reduction of 2 bit is needed.
 *
 */

void Full_Adder_Column(char **Dadda_Matrix, char **Overflow_Wires, int Column)
{
    char Carry, *inputs;
    inputs = (char*)calloc(Full_Inputs , sizeof(char));
    assert(inputs != NULL);
    int count;

    Get_Bits_From_Overflow(Overflow_Wires, inputs, Full_Inputs);
    count = Count_Bits(inputs, Full_Inputs);

    if(count == Full_Inputs)
    {
        Append_Overflow_Prev(Overflow_Wires, Full_Adder_Sum_Bit(inputs[0], inputs[1], inputs[2]));
        Append_Overflow_Next(Overflow_Wires, Full_Adder_Carry_Bit(inputs[0], inputs[1], inputs[2]));
    }

    if(count < Full_Inputs)
    {
        Carry = Add_Bits_In_Column(Dadda_Matrix, Column, inputs, Full_Inputs);
        Append_Overflow_Next(Overflow_Wires, Carry);
    }

    free(inputs);
}




/** ADD BITS IN COLUMN
 *
 * First gets bits, if any, from "Overflow_Wires" "Prev_Wires"
 * Column. "Prev_Wires" column are carry bits from adds done
 * in the previous column. If there are 3 or more bits in
 * "Prev_Wires" column they are added and the sum bit is put
 * back in the column so the process can be repeated. Once the
 * "Prev_Wires" column is empty, bits in the matrix column will
 * be added with the sum bit restored in the column.
 *
 * This Half Adder is called when a reduction of 1 bit is needed.
 *
 */

void Half_Adder_Column(char **Dadda_Matrix, char **Overflow_Wires, int Column)
{
    char Carry, *inputs;
    inputs = (char*)calloc(Half_Inputs , sizeof(char));
    assert(inputs != NULL);
    int count;

    Get_Bits_From_Overflow(Overflow_Wires, inputs, Half_Inputs);
    count = Count_Bits(inputs, Half_Inputs);

    if(count == Half_Inputs)
    {
        Append_Overflow_Prev(Overflow_Wires, Half_Adder_Sum_Bit(inputs[0], inputs[1]));
        Append_Overflow_Next(Overflow_Wires, Half_Adder_Carry_Bit(inputs[0], inputs[1]));
    }

    if(count < Half_Inputs)
    {
        Carry = Add_Bits_In_Column(Dadda_Matrix, Column, inputs, Half_Inputs);
        Append_Overflow_Next(Overflow_Wires, Carry);
    }
}




/** SET "Overflow_Wires" FOR USE IN NEXT REDUCTION
 *
 * Sets all bits in column of "Prev_Wires" equal to all
 * bits in "Next_Wires" column i.e. Sets

 * "Overflow_Wires[Next_Wires][]" = "Overflow_Wires[Next_Wires][]"
 *
 * Then sets all bits in "Next_Wires" column to empty ('-')
 * Returns the amount of bits transfered from "Next_Wires"
 * column to "Prev_Wires" column.
 *
 */

int Set_Overflow_Wires_Next(char **Overflow_Wires)
{
    char c;
    int i, count = 0;

    for(i = 0; i < byteSize; i++)
    {
        c = Overflow_Wires[Next_Wires][i];
        if(c != '-')count++;
        Overflow_Wires[Prev_Wires][i] = c;
        Overflow_Wires[Next_Wires][i] = '-';
    }

    return count;
}




/** REDUCE BITS IN "Dadda_Matrix[][Column]" BY "Overage" AMOUNT
 *
 * Adders are used to add the bits in the column reducing the
 * amount of bits in the column. This is repeated until the
 * overage is reduced to zero. The sum bit is restored in the
 * column which means Full Adders reduce by 2 bits each cycle.
 * Half Adders reduce by 1 bit each cycle. The carry over bits
 * from adders are stored in "Overflow_Wires[Next_Wires][]"
 * for the next Column to use when reduced. The amount of carry
 * bits is returned.
 *
 */

int Reduce_Overage(int Overage, char **Dadda_Matrix, char **Overflow_Wires, int Column)
{
    int Over = Overage;

    while(Over > 0)
    {
        if(Over > 1){
            Full_Adder_Column(Dadda_Matrix, Overflow_Wires, Column);
            Over -= 2;///Amount Full Adders reduce by. Input bits to output.
        }
        if(Over == 1)
        {
            Half_Adder_Column(Dadda_Matrix, Overflow_Wires, Column);
            Over -=1;///Amount Half Adders reduce by. Input bits to output.
        }
    }

    return Set_Overflow_Wires_Next(Overflow_Wires);
}





 /** REDUCE USING DADDA MULTIPLIER ALGORITHM
  *
  * This function iterates through the columns of the Matrix
  * linearly. Each column's "Wires" (bits) are counted. The
  * sum bits and carry over bits from the previous column are
  * reduced until there are no more carry over bits from the
  * previous column, and the number of bits in the current
  * column are less than or equal to the reduction limit.
  *
  * -------------------------EXAMPLE--------------------------
  *
  *    PREV Dadda_Matrix                NEXT Dadda_Matrix
  *    Max Column height = 5            Max Column Height = 3
  *
  *    *********                            *********
  *     *******                              *******
  *      *****      Reduction_Height = 3      *****
  *       ***
  *        *
  *
  *
  * Where stars represent a bit placement within the matrix
  *
  */

int Reduce_Dadda_Matrix(char **Dadda_Matrix, int depth)
{
    int Wires, Wires_Added = 0, Column, Overage, Reduction_Height;
    Reduction_Height = Get_Reduction_Height(depth);

    char **Overflow_Wires = Allocate_Matrix(2, byteSize);
    Set_Matrix_Empty(Overflow_Wires, 2, byteSize);

    for(Column = 0; Column < 2 * byteSize - 1; Column++)
    {
        for(Wires = 0; Wires < byteSize; Wires++)
            if(Dadda_Matrix[Wires][Column] == '-')break;

        Overage = Wires + Wires_Added - Reduction_Height;
        Wires_Added = Reduce_Overage(Overage, Dadda_Matrix, Overflow_Wires, Column);
    }

    Free_Matrix(Overflow_Wires, 2);

    return Reduction_Height;
}




/** SET "Result" TO FIRST ROW OF "Dadda_Matrix"
 *
 */

void Set_Result_From_Matrix(char **Dadda_Matrix, char *Result)
{
    int i;

    for(i = 0; i < byteSize; i++)
        Result[i] = Dadda_Matrix[0][i];
}




/** PRINTS "Dadda_Matrix"
 *
 * Used for testing. Prints user friendly
 * view as if long multiplication was done
 * by hand
 *
 */

void Print_Matrix(char **Dadda_Matrix)
{
    int i, j;
     for(i = 0; i < byteSize; i++){
        for(j = 2 * byteSize - 2; j >=0; j--)
            printf("%c", Dadda_Matrix[i][j]);
        printf("\n");
     }
}



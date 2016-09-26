#include <stdio.h>
#include <stdlib.h>
#include "BitwiseOperations.h"
#include "bitBasics.h"
#include "bitShiftOperations.h"
#include "arithmatic.h"

/** RANDOMLY FILL PART OF "Binary_Array" WITH '1'
 *
 * Will randomly fill the char array "Binary_Array[]
 * with '1' from "start" index up to "end" index.
 * Used for testing.
 *
 */

void Random_Fill(char *Binary_Array, int start, int end)
{
    int i;
    for(i = start; i <= end; i++)
    {
        Binary_Array[i] = '1';
    }
}


/** SET ALL ELEMENTS OF "Binary_Array" TO '0'
 *
 * Used for testing
 *
 */

void Set_Array(char *Binary_Array)
{
    int i;
    for(i = 0; i < byteSize; i++)
    {
        Binary_Array[i] = '0';
    }
}

/** PRINTS "Binary_Array"
 *
 * Used for testing
 *
 */

void Print_Array(char *Binary_Array)
{
    int i;
    for(i = byteSize - 1; i >= 0; i--)
    {
        printf("%c", Binary_Array[i]);
    }
    printf("\n");
}

/** TO BE DELETED!!!!
 *
 * \param
 * \param
 * \return
 *
 */

void andTest(int x)
{
    //x >>= 1;
    //x |= 5;

    ///will set bit 4 to a 1 inside x
    x |= 1 << 4;
    printf("x is : %i", x);
}
///cArray[i] = (1 & (a >> i)) ? '1':'0' ;

int main()
{
    char *a = malloc(sizeof(char*) * byteSize);
    char *b = malloc(sizeof(char*) * byteSize);
    char *result = malloc(sizeof(char*) * byteSize);

    int A = -5;
    Decimal_To_Binary(a, A);
    Print_Array(a);

    int B = -10;
    Decimal_To_Binary(b, B);
    Print_Array(b);

    int R;
    Multiplication(a, b, result);
    printf("\n\n");
    Print_Array(result);
    R = Binary_To_Decimal(result);
    printf("%d * %d = %d\n", A, B, R);



    free(a);free(b);free(result);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void Partial_Fill(char *Binary_Array, int start, int end)
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

    int A, B, R;
    printf("Enter a non decimal number\n");
    scanf("%d", &A);
    Decimal_To_Binary(a, A);
    printf("%d in binary is\n", A);
    Print_Array(a);

    printf("\nEnter another non decimal number\n");
    scanf("%d", &B);
    Decimal_To_Binary(b, B);
    printf("%d in binary is\n", B);
    Print_Array(b);

    R = A + B;
    printf("\n%d + %d = %d\n", A, B, R);

    Addition(a, b, result);
    printf(" ");
    Print_Array(a);
    printf("+");
    Print_Array(b);
    printf("---------------------------------\n ");
    Print_Array(result);

    R = A * B;
    printf("%d * %d = %d\n", A, B, R);

    printf("The following is a dadda multiplier performing long multiplication then reducing");
    Multiplication(a, b, result);
    printf("The resulting binary number is\n");
    Print_Array(result);

    printf("The binary array converted back to decimal is: %d\n", Binary_To_Decimal(result));
    printf("Press ctrl + c to exit");

    free(a);free(b);free(result);

    char *c;
    scanf("%s", c);
    return 0;
}


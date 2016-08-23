#include <stdio.h>
#include <stdlib.h>
#include "BitwiseOperations.h"
#include "bitBasics.h"
#include "bitShiftOperations.h"
#include "arithmatic.h"

void randomFill(char *cArray, int start, int end)
{
    int i;
    for(i = start; i <= end; i++)
    {
        cArray[i] = '1';
    }
}

void setArray(char *cArray)
{
    int i;
    for(i = 0; i < byteSize; i++)
    {
        cArray[i] = '0';
    }
}


void printArray(char *cArray)
{
    int i;
    for(i = byteSize - 1; i >= 0; i--)
    {
        printf("%c", cArray[i]);
    }
    printf("\n");
}


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
    char a[byteSize], b[byteSize], result[byteSize];

    decimalToBinary(a, 6);
    printArray(a);

    decimalToBinary(b, 5);
    printArray(b);

    subtraction(a, b, result);
    printArray(result);


    //andTest(2);

    return 0;
}


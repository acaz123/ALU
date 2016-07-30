#include <stdio.h>
#include <stdlib.h>
#include "scanTest.h"
#include "stack.h"
#include "BitwiseOperations.h"
#include "bitBasics.h"
#include "bitShiftOperations.h"

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

int main()
{
    char a[byteSize], b[byteSize], result[byteSize];

    decimalToBinary(a, 25);
    printArray(a);
    rotateR(a, 5);
    printArray(a);





    //printArray(result);

    return 0;
}

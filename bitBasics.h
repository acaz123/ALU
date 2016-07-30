#ifndef BITBASICS_H_INCLUDED
#define BITBASICS_H_INCLUDED

#include <stdbool.h>

extern const int byteSize;

char *decimalToBinary(char * cArray, int a);

int binaryToDecimal(char *cArray);

bool properInput(char *digit);


#endif // BITBASICS_H_INCLUDED

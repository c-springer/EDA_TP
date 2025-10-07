#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "Complex.h"

int main()
{
    setlocale(LC_ALL, "pt_PT");
    setlocale(LC_NUMERIC, "C"); 

    Complex z1, z2, z3;

    printf("Introduzir 2 complexos, na forma a + ib:\n    z1: ");
    z1.read();
    printf("\n    z2: ");
    z2.read();
    printf("\n");








    
    return 0;
}
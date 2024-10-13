#include <stdlib.h>
#include <stdio.h>


int show(char** stringArr, int count)
{
    if ( stringArr == NULL || stringArr[0] == NULL || count < 1) return 1;
    
    for (int i = 0; i < count; i++)
        printf("[%d] %s\n", i, stringArr[i]);
    
    return 0;
}
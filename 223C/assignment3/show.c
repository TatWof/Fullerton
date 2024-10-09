#include <stdlib.h>


int show(char** stringArr, int count)
{
    if (stringArr[0] == NULL) return 1;
    

    for (size_t i = 0; i < count; i++)
        printf("[%d] %s\n", i, stringArr[i]);
    
    return 0;
}
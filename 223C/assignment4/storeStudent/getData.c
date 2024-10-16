#include <stdlib.h>
#include <stdio.h>

#include "student.h"

int getData(char* ifname, struct Student** data, int maxsize)
{
    FILE* file = open(ifname, "r");
    int i, j, k, l;
    int count;
    char* buffer[2048];
    int cbuf;

    count = 0;
    k = 0;
    while(1)
    {
        if(count > maxsize) break;
        cbuf = fgetc(file);
        buffer[k] = cbuf;
        ++k;

        if (cbuf == '\n' || cbuf == EOF)
        {
            
        }
        

    }
}
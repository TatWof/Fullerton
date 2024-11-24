#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern struct Student* get(FILE*, fpos_t*);
extern int showData(struct Student**, int);

int show(FILE* file)
{
    fpos_t record;
    struct Student* s[256];
    int i;
    int buffer;

    printf("[Begining of Records]\n");

    fseek(file, 0, SEEK_SET);
    for (i = 0; fgetc(file) != EOF;)
    {
        fseek(file, -1, SEEK_CUR);
        
        fread(&buffer, sizeof(int), 1, file);
        fseek(file, -4, SEEK_CUR);
        if(buffer != 0)
        {
            fgetpos(file, &record);
            s[i] = get(file, &record);
            i++;
        }
        
        fseek(file, 128, SEEK_CUR);
    }

    showData(s, i);
    printf("[End of Records]\n");
    
    return 0;
}
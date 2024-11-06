#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern struct Student* get(FILE*, fpos_t*);
extern int showData(struct Student**, int);

int show(FILE* file)
{
    fpos_t* save;
    fpos_t* record;
    struct Student* s[256];
    int i;

    fgetpos(file, save);

    fseek(file, 0, SEEK_SET);
    for (i = 0; fgetc(file) != EOF; i++)
    {
        fseek(file, -1, SEEK_CUR);
        
        fgetpos(file, record);
        s[i] = get(file, record);
        
        fseek(file, 128, SEEK_CUR);
    }

    showData(s, i);
    
    fsetpos(file, save);
    return 0;
}
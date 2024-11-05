#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern int store(FILE*, struct Student*);
extern int search(FILE*, unsigned int);

int add(FILE* file)
{
    fpos_t save;
    int pos;
    struct Student s;
    char buffer;

    fgetpos(file, save);

    while(1)
    {
        
        pos = search(file, 0);    
        (pos < 0) ? fseek(file, 0, SEEK_END) : fsetpos(file, pos * 128);
        store(file, &s);
        
        printf("do you wish to continue? enter \'C\' to continue, \'Q\' to stop");
        scanf("%c", buffer);

        if(buffer == 'C' || buffer == 'c') break;

    }

    fsetpos(file, save);
    return 0;
}
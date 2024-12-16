/*
    name: Billy Leong
    email: bleong@csu.fullerton.edu
*/

#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern struct Student* get(FILE*, fpos_t*);
extern int showData(struct Student**, int);

/* Show
 * command for showing all records on file.
 *
 * params: 
 * file pointer
*/
int show(FILE* file)
{
    fpos_t record;
    struct Student* s[256];
    int i;
    int buffer;

    printf("[Beginning of Records]\n");

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
    s[i] = NULL;

    if(showData(s, i)) printf("No records found\n");
    printf("[End of Records]\n");
    for (size_t i = 0; s[i] != NULL; i++)
        free(s[i]);
    
    return 0;
}
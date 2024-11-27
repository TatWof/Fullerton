#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern struct Student* get(FILE*, fpos_t*);
extern int search(FILE*, unsigned int, fpos_t*);
extern int showData(struct Student**, int);

/* Find
 * command for finding a specific record. only compares CWID.
 *
 * params: 
 * file pointer
 * CWID to find
*/
int find(FILE* file, unsigned int match)
{
    fpos_t pos;
    struct Student* s;

    if(search(file, match, &pos))
    {
        printf("Record can not be found.\n");
        return 0;
    }

    s = get(file, &pos);
    showData(&s, 1);

    free(s);
    return 0;
}
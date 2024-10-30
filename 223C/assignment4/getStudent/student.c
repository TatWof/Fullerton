#include <stdlib.h>
#include "student.h"

/* Destruct Student
 * frees the allocated memory of a student
*/
void destructStudent(struct Student* s)
{
    free(s->name);
    free(s->major);
    free(s);
    return;
}
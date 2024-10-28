#include <stdlib.h>
#include "student.h"

void destructStudent(struct Student* s)
{
    free(s->name);
    free(s->major);
    free(s);
    return;
}
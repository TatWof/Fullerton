#include <stdlib.h>
#include <stdio.h>

#include "student.h"


struct Student* get(FILE* file, fpos_t* pos)
{
    fpos_t* save;
    struct Student* stu = malloc(1 * sizeof(struct Student));
    int temp;

    fgetpos(file, save);

    fsetpos(file, pos);

    fread(&stu->name, sizeof(char), 30, file);
    fread(&stu->CWID, sizeof(int), 1, file);
    fread(&stu->major, sizeof(char), 74, file);
    
    fread(&temp, sizeof(int), 1, file);
    switch (temp)
    {
    case 0:
        stu->standing = Freshman;
        break;
    case 1:
        stu->standing = Sophmore;
        break;
    case 2:
        stu->standing = Junior;
        break;
    case 3:
        stu->standing = Senior;
        break;
    
    default:
        stu->standing = Freshman;
        break;
    }
    
    fread(&stu->phone, sizeof(long long), 1, file);
    fread(&stu->parking_cost, sizeof(float), 1, file);
    fread(&stu->ZIPcode, sizeof(int), 1, file);

    fsetpos(file, save);
    return stu;
}
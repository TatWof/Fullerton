#include <stdio.h>
#include "student.h"

/* Show Data
 * prints out each student record
 *
 * params:
 * - data
 * - number of records
 * 
 * requires:
 * Student object
 * class standing enum
*/
int showData(struct Student** data, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("[Student %2d]\n", i + 1);
        printf("name = %s\n", data[i]->name);
        printf("CWID = %d\n", data[i]->CWID);
        printf("major = %s\n", data[i]->major);

        switch (data[i]->class_standing)
        {
        case Freshman:
            printf("class standing = Freshman\n");
            break;

        case Sophmore:
            printf("class standing = Sophmore\n");
            break;
        case Junior:
            printf("class standing = Junior\n");
            break;
        case Senior:
            printf("class standing = Senior\n");
            break;
        default:
            break;
        }

        printf("parking cost = %5.2f\n", data[i]->parking_cost);
        printf("zip code = %d\n", data[i]->ZIPcode);
    }
    
}
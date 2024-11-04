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
    if (data[0] == NULL)
    {
        printf("No data was found.\n");
        return 1;
    }
    
    for (int i = 0; i < count; i++)
    {
        printf("[Student %2d]\n", i + 1);
        printf("name = %s\n", data[i]->name);
        printf("CWID = %d\n", data[i]->CWID);
        printf("major = %s\n", data[i]->major);

        switch (data[i]->standing)
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

        printf("parking cost = %5.2lf\n", data[i]->parking_cost);
        printf("zip code = %d\n", data[i]->ZIPcode);
    }
    return 0;
}
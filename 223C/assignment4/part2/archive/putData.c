#include <stdlib.h>
#include <stdio.h>
#include "student.h"


/* Put Data
 * Puts data into a text file
 * 
 * params: 
 * - filename
 * - records
 * - number of records
 * 
 * requires:
 * - student object
 * - class standing enum
*/
int putData(char* filename,struct Student** data, int count)
{
    FILE* file = fopen(filename, "w");
    int i, j;
    char buffer[2048];

    for (i = 0; i < count; i++)
    {
        // name
        fputs(data[i]->name, file);
        fputs("\n", file);

        // CWID
        sprintf(buffer, "%d\n", data[i]->CWID);
        fputs(buffer, file);

        // major
        fputs(data[i]->major, file);
        fputs("\n", file);

        // class standing
        switch (data[i]->class_standing)
        {
        case Freshman:
            fputs("0\n", file);
            break;
        case Sophmore:
            fputs("1\n", file);
            break;
        case Junior:
            fputs("2\n", file);
            break;
        case Senior:
            fputs("3\n", file);
            break;
        
        default:
            fputs("0\n", file);
            break;
        }

        // parking cost
        sprintf(buffer, "%5.2lf\n", data[i]->parking_cost);
        fputs(buffer, file);

        // zip code
        sprintf(buffer, "%d\n", data[i]->ZIPcode);
        fputs(buffer, file);
    }
    

}
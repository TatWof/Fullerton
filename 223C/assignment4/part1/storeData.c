#include <stdlib.h>
#include <stdio.h>

#include "student.h"

/* Store Data
 * stores data into a binary file
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
int storeData(char* filename, struct Student** data, int count)
{
    FILE* file = fopen(filename, "wb");
    int i, j;

    if (file == NULL) 
    {
        printf("Error with creating file.\n");
        return 1;
    }
    if (data[0] == NULL) return 1;

    fwrite(&count, sizeof(int), 1, file);

    for (i = 0; i < count; i++)
    {
        /* structure for each record
        [4b, int][~b, char][4b, int][4b, int][1b, int][8b, float][4b, int]
        */

        // writes a string (name) 
        for (j = 0; data[i]->name[j] != 0;){++j;}
        fwrite(&j, sizeof(int), 1, file);   // writes in how long the string is
        fputs(data[i]->name, file);         // the string itself
        
        // writes int (CWID) 
        fwrite(&(data[i]->CWID), sizeof(int), 1, file);
        
        // writes a string (major)
        for (j = 0; data[i]->major[j] != 0;){++j;}
        fwrite(&j, sizeof(int), 1, file);   // writes in how long the string is
        fputs(data[i]->major, file);        // the string itself

        // writes 1 byte for enum
        switch (data[i]->class_standing)
        {
        case Freshman:
            fputc(0, file);
            break;
        case Sophmore:
            fputc(1, file);
            break;
        case Junior:
            fputc(2, file);
            break;
        case Senior:
            fputc(3, file);
            break;
        default:
            fputc(0, file);
            break;
        }

        // writes a double (Parking cost)
        fwrite(&(data[i]->parking_cost), sizeof(double), 1, file);

        // writes an int (zipcode)
        fwrite(&(data[i]->ZIPcode), sizeof(int), 1, file);
    }
    fclose(file);
}
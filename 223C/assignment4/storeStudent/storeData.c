#include <stdlib.h>
#include <stdio.h>

#include "student.h"

int storeData(char* filename, struct Student** data, int count)
{
    FILE* file = fopen(filename, "wb");
    int i, j;

    fwrite(&count, sizeof(int), 1, file);

    for (i = 0; i < count; i++)
    {
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

        // writes a float (Parking cost)
        fwrite(&(data[i]->parking_cost), sizeof(double), 1, file);

        // writes an int (zipcode)
        fwrite(&(data[i]->ZIPcode), sizeof(int), 1, file);
    }
    
}
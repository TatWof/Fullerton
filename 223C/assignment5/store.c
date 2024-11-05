#include <stdlib.h>
#include <stdio.h>

#include "student.h"

/* Store Record (Student)
 * stores a single record into the file. 
 * This function assumes that the file pointer has already been modified to point to an available space 
 * Each record is exactly 128 btyes and is structure as in the following
 * [30b, char][4b, int][74b, char][4b, int][8b, int][4b, float][4b, int]
 * 
 * params: 
 * - file pointer
 * - record
 * 
 * requires:
 * - student object
 * - class standing enum
*/
int store(FILE* file, struct Student* data)
{
    int i, j;

    if (file == NULL) return 1;

    /* structure for each record
    [30b, char][4b, int][74b, char][4b, int][8b, int][4b, float][4b, int] = 128b per record 
    */

    // writes a string (name) 
    for(j = 0; data->major[j] != 0 || j < 30; ++j)
        fwrite(&(data->name[j]), sizeof(char), 1, file);
    fwrite(0, sizeof(char), 30 - j, file);
    
    // writes int (CWID) 
    fwrite(&(data->CWID), sizeof(int), 1, file);
    
    // writes a string (major)
    for(j = 0; data->major[j] != 0 || j < 74; ++j)
        fwrite(&(data->major[j]), sizeof(char), 1, file);
    fwrite(0, sizeof(char), 74 - j, file);

    // writes 4 byte for enum
    switch (data->standing)
    {
    case Freshman:
        fwrite(0, sizeof(int), 1, file);
        break;
    case Sophmore:
        fwrite(1, sizeof(int), 1, file);
        break;
    case Junior:
        fwrite(2, sizeof(int), 1, file);
        break;
    case Senior:
        fwrite(3, sizeof(int), 1, file);
        break;
    default:
        fwrite(0, sizeof(int), 1, file);
        break;
    }

    // writes phone
    fwrite(&(data->phone), sizeof(unsigned long long), 1, file);

    // writes a double (Parking cost)
    fwrite(&(data->parking_cost), sizeof(float), 1, file);

    // writes an int (zipcode)
    fwrite(&(data->ZIPcode), sizeof(int), 1, file);

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "student.h"

/* Get Binary Data
 * gets data from a binary file and puts it into a student object
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
int getBinData(char* filename, struct Student** data, int maxsize)
{
    FILE* file = fopen(filename, "rb");
    int count;
    int i, j;

    if (file == NULL) return 0;

    fread(&count, sizeof(int), 1, file);
    
    for (i = 0; i < count; ++i)
    {
        data[i] = malloc(1 * sizeof(struct Student));
        
        // name
        fread(&j, sizeof(int), 1, file);
        data[i]->name = malloc(j + 1 * sizeof(char));
        fread(data[i]->name, sizeof(char), j, file);
        data[i]->name[j] = 0;

        // CWID
        fread(&data[i]->CWID, sizeof(int), 1, file);

        // major
        fread(&j, sizeof(int), 1, file);
        data[i]->major = malloc(j + 1 * sizeof(char));
        fread(data[i]->major, sizeof(char), j, file);
        data[i]->major[j] = 0;

        // class standing
        fread(&j, sizeof(char), 1, file);
        switch (j)
        {
        case 0:
            data[i]->class_standing = Freshman;
            break;
        case 1:
            data[i]->class_standing = Sophmore;
            break;
        case 2:
            data[i]->class_standing = Junior;
            break;
        case 3:
            data[i]->class_standing = Senior;
            break;
        
        default:
            data[i]->class_standing = Freshman;
            break;
        }

        //phone
        fread(&data[i]->phone, sizeof(long long), 1, file);

        // parking cost
        fread(&data[i]->parking_cost, sizeof(float), 1, file);
        
        // zipcode
        fread(&data[i]->ZIPcode, sizeof(int), 1, file);
    }
    return count;
}
#include <stdlib.h>
#include <stdio.h>

#include "student.h"

int getData(char* ifname, struct Student** data, int maxsize)
{
    FILE* file = fopen(ifname, "r");
    int i, k, l;
    int count;
    char buffer[2048];
    int cbuf;

    if (file == NULL) return 0;
    

    count = 0;
    k = 0;
    while(1)
    {
        if(count > maxsize) break;
        cbuf = fgetc(file);
        buffer[k] = cbuf;
        ++k;

        if (cbuf == '\n' || cbuf == EOF)
        {
            ++l;
            switch (l)
            {
            case 1: // name
                data[count] = malloc(1 * sizeof(struct Student));

                data[count]->name = malloc(k * sizeof(char));
                for (i = 0; i < k - 1; i++)
                    data[count]->name[i] = buffer[i];
                data[count]->name[k] = 0;
                k = 0;
                break;
            
            case 2: // CWID
                buffer[k] = 0;
                data[count]->CWID = atoi(buffer);
                k = 0;
                break;

            case 3: // major
                data[count]->major = malloc(k * sizeof(char));
                for (i = 0; i < k - 1; i++)
                    data[count]->major[i] = buffer[i];
                data[count]->major[k] = 0;
                k = 0;
                break;

            case 4: // class standing
                switch (cbuf)
                {
                case 0:
                    data[count]->class_standing = Freshman;
                    break;
                case 1:
                    data[count]->class_standing = Sophmore;
                    break;
                case 2:
                    data[count]->class_standing = Junior;
                    break;
                case 3:
                    data[count]->class_standing = Senior;
                    break;
                default:
                    break;
                }
                k = 0;
                break;

            case 5: // parking cost
                buffer[k] = 0;
                data[count]->parking_cost = atof(buffer);
                k = 0;
                break;

            case 6: //zipcode
                buffer[k] = 0;
                data[count]->ZIPcode = atoi(buffer);
                k = 0;
                
            default:
                l = 0;
                ++count;
                break;
            }

            if (cbuf == EOF) break;
        }
    }

    return count;
}
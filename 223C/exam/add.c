/*
    name: Billy Leong
    email: bleong@csu.fullerton.edu
*/

#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern int store(FILE*, struct Student*);
extern int search(FILE*, unsigned int, fpos_t*);

/* Add
 * command for adding new records on file.
 * will overwrite empty records first.
 *
 * params: 
 * file pointer
*/
int add(FILE* file)
{
    fpos_t save;
    fpos_t pos;
    struct Student s;
    char buffer;
    char str[2048];

    fgetpos(file, &pos);
    while(1)
    {
        printf("enter name: ");
        scanf("%s", s.name);
        scanf("%c", &buffer);

        printf("enter CWID: ");
        scanf("%d", &s.CWID);
        while(1)
        {
            if (!search(file, s.CWID, &pos)) break;
            printf("That number is taken\nPlease enter a new number: ");
            scanf("%d", &s.CWID);
        }
        

        printf("enter major: ");
        scanf("%s", s.major);
        scanf("%c", &buffer);

        printf("enter class standing: ");
        scanf("%s", str);
        scanf("%c", &buffer);

        switch (str[1])
        {
        case 'r':
            s.standing = Freshman;
            break;
        case 'o':
            s.standing = Sophmore;
            break;
        case 'u':
            s.standing = Junior;
            break;
        case 'e':
            s.standing = Senior;
            break;
        default:
            s.standing = Freshman;
            break;
        }

        printf("enter phone number: ");
        scanf("%lld", &s.phone);

        printf("enter parking fee: ");
        scanf("%f", &s.parking_cost);

        printf("enter ZIP code: ");
        scanf("%d", &s.ZIPcode);


        if (search(file, 0, &pos))
        {
            fseek(file, 0, SEEK_END);
            fgetpos(file, &pos);
        }
        store(file, &s);
        
        scanf("%c", &buffer);
        printf("\nDo you wish to continue?\nEnter [c] to continue (anything else will exit)\nEnter: ");
        scanf("%c", &buffer);

        if(!(buffer == 'c')) break;
    }
    return 0;
}
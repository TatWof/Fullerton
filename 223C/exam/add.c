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
    fpos_t pos;
    struct Student s;
    char buffer;
    char str[2048];
    int i;

    fgetpos(file, &pos);
    while(1)
    {
        printf("enter name: ");
        scanf("%c", &buffer);
        fgets(s.name, 30, stdin);
        for (i = 0; i < 74 || s.name[i] != 0; i++)
            if (s.name[i] == '\n') break;
        s.name[i] = 0;
        

        printf("enter CWID: ");
        scanf("%d", &s.CWID);
        while(1)
        {
            if (search(file, s.CWID, &pos)) break;
            printf("That number is taken\nPlease enter a new number: ");
            scanf("%d", &s.CWID);
        }
        

        printf("enter major: ");
        scanf("%c", &buffer);
        fgets(s.major, 74, stdin);
        for (i = 0; i < 74 || s.major[i] != 0; i++)
            if (s.major[i] == '\n') break;
        s.major[i] = 0;

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
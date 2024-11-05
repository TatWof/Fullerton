#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern int store(FILE*, struct Student*);
extern fpos_t* search(FILE*, unsigned int);

int add(FILE* file)
{
    fpos_t* save;
    fpos_t* pos;
    struct Student s;
    char buffer;
    char str[2048];

    fgetpos(file, save);

    while(1)
    {
        
        printf("enter name: ");
        scanf("%s", s.name);
        scanf("%c", &buffer);

        printf("enter CWID: ");
        scanf("%d", s.CWID);

        printf("enter major: ");
        scanf("%s", s.major);
        scanf("%c", &buffer);

        printf("enter class standing");
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
        break;

        printf("enter phone number: ");
        scanf("%lld", s.phone);

        printf("enter parking fee: ");
        scanf("%f", s.parking_cost);

        printf("enter ZIP code: ");
        scanf("%d", s.ZIPcode);

        pos = search(file, 0);    
        (pos < 0) ? fseek(file, 0, SEEK_END) : fsetpos(file, pos);
        store(file, &s);
        
        printf("do you wish to continue?\nEnter \'C\' to continue (anything else will exit)\nEnter:");
        scanf("%c", buffer);

        if(!(buffer == 'C' || buffer == 'c')) break;
    }

    fsetpos(file, save);
    return 0;
}
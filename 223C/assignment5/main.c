/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 00/00/2024 - 23:59:00
    Program Name:
    Purpose:
    OS: Windows 11
*/

#include <stdlib.h>
#include <stdio.h>

extern int add(FILE*);
extern int delete(FILE*, unsigned int);
extern int find(FILE*, unsigned int);
extern int show(FILE* file);

int main(int argc, char const *argv[])
{
    char* filename = "academic.bin";
    FILE* file = fopen(filename,"r+");
    char cbuf;
    int findkey;

    if(file == NULL) file = fopen(filename, "w+");

    printf("Welcome to Student Record Manager.\nAll data will be stored in \'academic.bin\'.\n\n");


    printf("Enter [a] to add, [d] to delete, [f] to find, and [s] to show all records.\nEnter: ");
    scanf("%c", &cbuf);

    while(1)
    {

        if(cbuf == 'x' || cbuf == 'X' || cbuf == 'q' || cbuf == 'Q') break;
        
        switch (cbuf)
        {
        case 'A':
        case 'a': 
            add(file);
            scanf("%c", &cbuf);
            break;
        case 'D':
        case 'd':
            printf("Please enter the CWID of the record you want to delete.\nEnter: ");
            scanf("%d", &findkey);
            delete(file, findkey);
            scanf("%c", &cbuf);
            break;
        case 'F':
        case 'f':
            printf("Please enter the CWID of the record you want to find.\nEnter: ");
            scanf("%d", &findkey);
            find(file, findkey);
            scanf("%c", &cbuf);
            break;
        case 'S':
        case 's':
            show(file);
            scanf("%c", &cbuf);
            break;
        default:
            printf("Sorry. That is not a valid command. Please try again.\n");
            break;
        }

        
        printf("Enter [a] to add, [d] to delete, [f] to find, and [s] to show all records.\nEnter [x] to exit\nEnter: ");
        scanf("%c", &cbuf);
    }
    
    printf("Thank You for using Student Record Manager.\nGoodbye.");
    fclose(file);
    return 0;
}

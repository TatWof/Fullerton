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
    FILE* file = fopen(filename,"w+");
    char cbuf;
    int findkey;

    do{
        printf("Enter [a] to add, [d] to delete, [f] to find, and [s] to show all records.\nEnter: ");
        scanf("%c", &cbuf);

        if(cbuf == 'x') break;
        
        switch (cbuf)
        {
        case 'a':
            add(file);
            break;
        case 'd':
            printf("Please enter the CWID of the record you want to delete.\nEnter: ");
            scanf("%d", &findkey);
            delete(file, findkey);
            break;
        case 'f':
            printf("Please enter the CWID of the record you want to find.\nEnter: ");
            scanf("%d", &findkey);
            find(file, findkey);
            break;
        case 's':
            show(file);
            break;
        default:
            printf("Sorry. That is not a valid command. Please try again.\n");
            break;
        }

    } while(1);
    

    
    fclose(file);
    return 0;
}

/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 11/03/2024 - 23:59:00
    Program Name: Scholar Part 2
    Purpose: print data from a binary file
    OS: Windows 11
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "student.h"

extern int getBinData(char*, struct Student**, int);
extern int showData(struct Student**, int);

int main(int argc, char const *argv[])
{
    char* ifname = malloc(2048 * sizeof(char));
    struct Student* data[2048];
    int datacount;
    int i;

    printf("Welcome to Scholarize Part 2.\nThis program is for getting data from a Binary file and printing them out\n");

    // get the name of the data file
    printf("Enter the name of data file to be read: ");
    scanf("%s", ifname);

    // get the data from the file
    datacount = getBinData(ifname, data, 2048);
    if(datacount == 0)
    {
        printf("No data was read from the file.\n");
        return 0;
    }
    
    //show the records
    printf("%d records was read.\nHere are the records:\n", datacount);
    if(showData(data, datacount)) return 0;
    printf("\n");

    printf("Thank you for using this program\nGoodbye\n");
    for (size_t i = 0; i < datacount; i++)
        destructStudent(data[i]);
    return 0;
}

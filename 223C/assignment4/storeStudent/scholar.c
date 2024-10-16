/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 11/03/2024 - 23:59:00
    Program Name: Scholar
    Purpose: store data into a binary file
    OS: Windows 11
*/

#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern int getData(char*, struct Student**, int);
extern int storeData(char*,struct Student**, int);

int main(int argc, char const *argv[])
{
    char* ifname;
    char* ofname;
    struct Student* data[2048];

    if (getData(ifname, data, 2048) == 1)
    {
        printf("Something went wrong while getting data.\n");
        return 0;
    }

    storeData(ofname, data, 2048);
    return 0;
}

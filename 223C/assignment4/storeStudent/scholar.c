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
extern int showData(struct Student**, int);

int main(int argc, char const *argv[])
{
    char* ifname = "data.txt";
    char* ofname = "data.bin";
    struct Student* data[2048];
    int datacount;

    datacount = getData(ifname, data, 2048);
    showData(data, datacount);

    storeData(ofname, data, datacount);

    for (size_t i = 0; i < datacount; i++)
        destructStudent(data[i]);
    
    return 0;
}

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

#include "student.h"

extern int getBinData(char*, struct Student**, int);
extern int putData(char*, struct Student**, int);
extern int showData(struct Student**, int);

int main(int argc, char const *argv[])
{
    char* ifname = "data.bin";
    char* ofname = "students.txt";
    struct Student* data[2048];
    int datacount;

    datacount = getBinData(ifname, data, 2048);
    showData(data, datacount);

    //putData(ofname, data, datacount);

    return 0;
}

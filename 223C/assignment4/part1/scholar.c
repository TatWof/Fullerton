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
#include <string.h>

#include "student.h"

extern int getData(char*, struct Student**, int);
extern int storeData(char*,struct Student**, int);
extern int showData(struct Student**, int);

int main(int argc, char const *argv[])
{
    char* ifname = malloc(2048 * sizeof(char));
    char* ofname = malloc(2048 * sizeof(char));
    struct Student* data[2048];
    int datacount;
    int cbuf;
    int i;

    // get the name of the data file
    printf("enter the name of data file to be read:");
    scanf("%s", ifname);
    scanf("%c", cbuf);

    // generating the name of the output file
    for (i = 0; ifname[i] != '.'; ++i)
        ofname[i] = ifname[i];
    ofname[i] = 0;
    ofname = strcat(ofname, ".bin");


    datacount = getData(ifname, data, 2048);
    showData(data, datacount);

    storeData(ofname, data, datacount);

    for (size_t i = 0; i < datacount; i++)
        destructStudent(data[i]);
    
    return 0;
}

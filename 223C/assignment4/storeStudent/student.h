#ifndef STUDENT_H
#define STUDENT_H

#define FIELDS 5

enum Class {Freshman, Sophmore, Junior, Senior};

struct Student
{
    char* name;
    int CWID;
    char* major;
    Class class_standing;
    int ZIPcode;
};

#endif
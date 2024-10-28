#ifndef STUDENT_H
#define STUDENT_H

#define FIELDS 6

enum Class {Freshman, Sophmore, Junior, Senior};

struct Student
{
    char* name;
    int CWID;
    char* major;
    enum Class class_standing;
    float parking_cost;
    int ZIPcode;
};

#endif
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
    double parking_cost;
    int ZIPcode;
};

extern void destructStudent(struct Student*);

#endif
#ifndef STUDENT_H
#define STUDENT_H

#define FIELDS 7

enum Class {Freshman, Sophmore, Junior, Senior};

struct Student
{
    char* name;
    int CWID;
    char* major;
    enum Class standing;
    long long phone;
    float parking_cost;
    int ZIPcode;
};

extern void destructStudent(struct Student*);

#endif
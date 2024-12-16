/*
    name: Billy Leong
    email: bleong@csu.fullerton.edu
*/

#ifndef STUDENT_H
#define STUDENT_H

#define FIELDS 7

enum Class {Freshman, Sophmore, Junior, Senior};

struct Student
{
    char name[30];
    unsigned int CWID;
    char major[74];
    enum Class standing;
    unsigned long long phone;
    float parking_cost;
    unsigned int ZIPcode;
};

#endif
#ifndef STUDENT_H
#define STUDENT_H

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
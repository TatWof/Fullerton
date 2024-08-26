//****************************************************************************************************************************
//Program name: "Simple Time".  This program displays the current date, time, and seconds since the Epoch using the most     *
// simple code possible.. Copyright (C) 2024  Floyd Holliday.                                                                *
//                                                                                                                           *
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License  *
//version 3 as published by the Free Software Foundation.  This program is distributed in the hope that it will be useful,   *
//but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See   *
//the GNU General Public License for more details A copy of the GNU General Public License v3 is available here:             *
//<https://www.gnu.org/licenses/>.                                                                                           *
//****************************************************************************************************************************

//Author: Floyd Holliday
//Author email: holliday@fullerton.edu
//Program name: Simple Time
//Programming languages: One file in C language and two files in Bash.
//Date program began: 2024-Jan-17
//Date of last update: 2024-Jan-17
//Files in this program: current-time.c and r.sh.  At a future date rg.sh may be added.
//Testing: Alpha testing completed.  All functionality is correct
//Status: Ready for release to the customers

//Purpose of this program:
//  This program is study material for students enrolled in a first semester class of C programming.

//This file
//  File name: current-time.c
//  Language: C language, 202x standardization where x will be a decimal digit.
//  Max page width: 124 columns
//  Compile: gcc -c -Wall -m64 -no-pie -o current-time.o current-time.c -std=c17
//  Link: gcc -m64 -no-pie -o current.out current-time.o -std=c17

//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2**
//
//
//===== Begin code area ================================================================================================

#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{//There is one physical clock in the computer, which outputs tics at a given frequency often
 //measured in units GHz.

 //Obtain and display the elapsed time since the Epoch.
 time_t current_linux_time;
 current_linux_time = time(NULL);
 printf("The number of seconds since the Great Epoch is %lu\n",current_linux_time);
 //Use the Linux time computed immediately above and convert it to broken time (human manageable 
 //time) in the current time zone.
 struct tm * broken = localtime(&current_linux_time);
 if(broken == NULL)
     printf("A call to function localtime failed.\n");
 else
     printf("The date and time are now: %04d-%02d-%02d @ %02d:%02d:%02d\n",
             broken->tm_year+1900,
             broken->tm_mon+1,
             broken->tm_mday,
             broken->tm_hour,
             broken->tm_min,
             broken->tm_sec);  //End of printf

 printf("%s\n","Bye");
 return 0;
}
//=======1=========2=========3=========4=========5=========6=========7=========8=========9=========0=========1=========2**





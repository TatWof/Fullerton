This is a README markdown text file for the End User with instructions for how to compile and run.

# Compiling Instructions
In a terminal with a directory opened to this file's directory, input the following command based on your operating system:
- On Linux: `./r.sh`

- On Windows: `./rwin.sh`

The Linux bash will automatically run the program after it finishes compiling. To run the output executable file on Windows use the command `./main.out`

# Known Issues

- shell script is locked when attempting to run on Linux (Ubuntu).
    - Unknown: use `chmod u=x r.sh` then run the shell script again.
- linkage error when using the shell script.
    - Fixed: added `-lm` command to link command line.

# Credits

Developer Billy Leong

Email: bleong@csu.fullerton.edu

Course ID: CPSC223C

Due Date: 09/08/2024 - 23:59:00

Program Name: Assignment 1 Trigonometry

Purpose: getting used to C libraries with simple IO, time, and math

OS: Windows 11
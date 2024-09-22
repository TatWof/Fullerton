This is a README markdown text file for the End User with instructions for how to compile and run.

# Program Information
Name: Assignment 2 Tokenizer

Purpose: File IO and string processing

Due Date: 09/22/2024

## Compatibility
- Windows: stable
- Linux (Ubuntu): working

# Compiling Instructions
In a terminal with a directory opened to this file's directory, input the following command based on your operating system:
- On Linux: `./r.sh`

- On Windows: `./rwin.sh`

The Linux bash will automatically run the program after it finishes compiling. To run the output executable file on Windows use the command `./main.out`

# Changelog
## Version 1
Source code uses a struct with a custom tokenizer function

## Version 2
Altered source code to use strtok() function instead of custom tokenizer

Old version of the main file can be seen in the `/archive` folder.

# Known Issues
- printing strings is also printing ending trash data
    - Identified: C-strings requires null-termination
    - Fixed: dynamically adds `\0` to the end of all bespoke strings.
- scanf() when using strings causes the next scanf() to be skipped
    - Identified: ending new line character is not discarded after inputs
    - Fixed: additional scanf() to catch the new line character is required after inputting strings.
- shell file fails while running compiling commands
    - Identified: multiple source code files have to be compiled individually
    - Fixed: individual compile instructions added to shell files
- token list is statically sized, may cause issues if the number of tokens exceeds arbitrary limit
    - Feature: token list is now dynamically sized.
# Credits

Developer Billy Leong

Email: bleong@csu.fullerton.edu

Course ID: CPSC223C

Github Repo: https://github.com/TatWof/Fullerton

OS: Windows 11
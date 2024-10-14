/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 10/14/2024
    Product: Midterm test
    OS: Windows 11
*/

#include <stdlib.h>
#include <stdio.h>

/* Tasks:
 * get char from files
 * calc frequencies
 * print 3-col array {ascii code, ascii char, frequency}
 * sort by frequency
 * print sorted array
 * goodbye
*/

#include "freq.h"

extern char* copy_1d(char*);
extern struct FREQ** calc_cfreq(char*);
extern int show_cfreq(struct FREQ**);
extern int sort_bycfreq(struct FREQ**);

int main(int argc, char const *argv[])
{
    char* filename;
    struct FREQ** freq;
    char* str;
    char cbuf;

    // Startup
    printf("Welcome to File Character Counter\nPlease input the file to be counted: ");
    scanf("%s", filename);
    scanf("%c", &cbuf);

    printf("Confirming file => %s\n", filename);

    // copy file contents to a string
    str = copy_1d(filename);

    if(str == NULL) return 0;
    printf("File has been successfully copied\n");


    //calculate character frequencies
    freq = calc_cfreq(str);
    if(freq == NULL)
    {
        printf("Error while calculating character frequencies.\nPlease try again.\n");
        free(str);
        return 0;
    }
    
    // show frequencies
    printf("\n\nShowing frequencies.\n");
    if(show_cfreq(freq) == 1)
    {
        printf("Error while printing.\n");
        for (int i = 0; i < 256; i++)
            free(freq[i]);
        free(freq);
        free(str);
        return 0;
    }

    // sort frequencies and show them
    if(sort_bycfreq(freq) == 1)
    {
        printf("\n\n something went wrong while sorting, please try again");
    }
    else
    {
        printf("\n\nShowing the table sorted by frequencies.\n");
        if(show_cfreq(freq) == 1)
            printf("Error while printing.\nPlease try again.\n");
    }

    // Goodbye
    printf("Thank you for using File Character Counter\nGoodbye.\n");

    // deallocate memory
    for (int i = 0; i < 256; i++)
        free(freq[i]);
    free(freq);
    free(str);

    return 0;
}

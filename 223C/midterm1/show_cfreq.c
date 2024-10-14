#include <stdio.h>
#include "freq.h"

/* Show Character Frequency
 * shows character frequencies by a table, special characters may break the table, this is expected behavior
 *
 * params: Frequecy table pointer array
 * requires: frequency table struct
 * returns: 1 if no table, 0 if successful
*/
int show_cfreq(struct FREQ** freqs)
{
    // if no frequency table exit
    if (freqs == 0) return 1;
    
    // print code character and frequency of character. special characters will break the table, this is expected behavior
    printf("code   ascii   frequency\n");
    for (int i = 0; i < 256; i++)
       printf("%3d %7c %5d\n", freqs[i]->code, (freqs[i]->code), freqs[i]->freq);
    
    return 0;
}